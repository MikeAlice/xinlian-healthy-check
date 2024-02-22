<!-- 用户管理 -->
<template>
   <el-container>
      <el-header style="height: 200px;">
        <div class="dis">
          <div>用户名 <el-input v-model="name" placeholder="请输入用户名" class="model"/></div>

        <div>所属科室  <el-select v-model="value" placeholder="请选择科室" class="model">
    <el-option v-for="item in options" :key="item.value" :label="item.label" :value="item.value"/> </el-select></div>

    <div>手机号<el-input v-model="phone" placeholder="请输入手机号码" class="model"/></div>
    
    <div>邮箱<el-input v-model="mail" placeholder="请输入邮箱" class="model"/></div>
  </div>
    
  <div class="dis">
    <div>性别<el-select v-model="value" placeholder="选择性别" class="wid">
    <el-option v-for="item in gender" :key="item.value" :label="item.label" :value="item.value" /></el-select></div>
  
        <div>登录账号<el-input v-model="input" placeholder="请输入登录账号" class="model"/></div>

        <div>用户ID<el-input v-model="input" placeholder="请输入用户ID" class="model"/></div>

        <div>创建时间 <el-input v-model="input" placeholder="输入起始时间" class="model"/></div>
   </div>
        <el-button>搜索</el-button>
        <el-button>重置</el-button>
      </el-header>
      <el-main>
      <el-button @click="add = true">添加用户</el-button>
      <el-button @click="">批量删除</el-button>
      <el-select v-model="value" placeholder="更多操作" class="wid">
    <el-option v-for="item in more" :key="item.value" :label="item.label" :value="item.value" /></el-select>
      <el-button @click="">关闭搜索</el-button>
      <el-button @click="">关闭提示</el-button>
        <el-table :data="tableData" height="250" border :cell-style="{ textAlign: 'center' }" :header-cell-style="{ 'text-align': 'center' }" style="width: 100%">
        <el-table-column prop="" label="" width="60" />
        <el-table-column prop="number" label="#" width="60" />
        <el-table-column prop="id" label="登录账号" />
        <el-table-column prop="name" label="用户名" />
        <el-table-column prop="avator" label="头像" />
        <el-table-column prop="affiliation" label="所属科室" />
        <el-table-column prop="phone" label="手机" />
        <el-table-column prop="gender" label="性别" />
        <el-table-column prop="type" label="类型" />
        <el-table-column prop="state" label="状态" />
        <el-table-column prop="time" label="创建时间" />
        <el-table-column fixed="right" label="操作" width="240">
      <template #default>
        <el-button link type="primary" size="small" @click="handleClick"
          >编辑</el-button>
        <el-button link type="primary" size="small">禁用</el-button>
        <el-button link type="primary" size="small">删除</el-button>
        <el-button link type="primary" size="small" @click="handleDrawer">修改密码</el-button>
      </template>
    </el-table-column>
      </el-table>
      <div>
        共5页<el-input-number v-model="num" :min="1" :max="10" @change="handleChange" />
        <el-select v-model="value" size="large" style="width: 140px">
    <el-option v-for="item in options" :key="item.value" :label="item.label" :value="item.value"/>
  </el-select>
  跳至<el-input v-model="num" style="width: 50px;"></el-input>页
      </div>
      <!-- 添加用户抽屉 -->
      <el-drawer  title="添加用户"  v-model="add" >
        <div class="dis">
          <div>登录账号 <el-input v-model="input" style="width: 150px;"/></div>
        <div>密码 <el-input v-model="input"/></div>
        </div>
        <div class="dis">
          <div>用户名 <el-input v-model="input" style="width: 150px;"/></div>
        <div>邮箱 <el-input v-model="input" /></div>
        </div>
        <div class="dis">
        <div>手机号 <el-input v-model="input" style="width: 150px;"/></div>
        <div>性别 <el-select v-model="value" placeholder="选择性别" class="model">
    <el-option v-for="item in gender" :key="item.value" :label="item.label" :value="item.value" /></el-select></div>
      </div>
        <div class="dis">
        <div>所属部门 <el-input v-model="input" style="width: 150px;"/></div>
        <div>用户类型 <el-select v-model="userleixing" placeholder="选择类型" class="model">
    <el-option v-for="item in userleixing"
      :key="item.value"
      :label="item.label"
      :value="item.value" /></el-select></div>
      </div>
      <div>头像<div>角色分配 <el-select v-model="gender" class="model">
    <el-option v-for="item in options" :key="item.value" :label="item.label" :value="item.value" /></el-select></div></div>
    <div>个人资料</div>
    <div>所在地区 <el-input v-model="input" style="width: 150px;"/></div>
    <div>街道地址 <el-input v-model="input" style="width: 150px;"/></div>
    <div>签名文件</div>
    <div>生日</div>
    <div>简介<el-input v-model="textarea" :rows="2" type="textarea"/></div>
    <div></div>
        <template #footer>
       <el-button>提交</el-button>
       <el-button>取消</el-button>
      </template>
      </el-drawer>
      <!-- 修改密码抽屉 -->
  <el-drawer v-if="drawerVisible" v-model="drawer" title="修改密码">
    <el-form v-model="remakePw" style="margin-top: 15px" :label-position="drawerLabel">
      <el-form-item label="*原密码" label-width="100">
        <el-input v-model="remakePw.oldPassword" show-password type="password" placeholder="请输入现在使用的密码"></el-input>
      </el-form-item>
      <el-form-item label="*新密码" label-width="100">
        <el-input v-model="remakePw.newPassword" show-password type="password" placeholder="请输入新密码,长度为6-20个字符"></el-input>
      </el-form-item>
      <el-form-item label="*确认新密码" label-width="100">
        <el-input v-model="remakePw.confirm" show-password type="password" placeholder="请再次输入新密码"></el-input>
      </el-form-item>
    </el-form>
    <template #footer>
      <div style="flex: auto">
        <el-button type="primary" @click="editMm" >提交</el-button>
        <el-button @click="closeDrawer">取消</el-button>
      </div>
    </template>
  </el-drawer>
      </el-main>
    </el-container>
</template>

<script setup>
import { ref,reactive } from 'vue'
import NewButtonCG from '@/components/details/NewButtonCG.vue'
import { defineProps } from 'vue'
import { useUserManagementStores } from '@/stores/usermanagement/index.js'

/* Stores中的方法 */
const userManagementStore = useUserManagementStores()
  
// 抽屉显隐
const drawer = ref(true)

// 切换抽屉
const drawerVisible = ref(false)

// 点击取消关闭抽屉
const closeDrawer = () => {
  drawerVisible.value = !drawerVisible.value
}


// 修改密码表单
const remakePw = reactive({
  id:'1488982016',
  oldPassword: '',
  newPassword: '',
  confirm: '',
  pass_strength: '弱'
})

// 点击修改打开抽屉
const handleDrawer = () => {
  drawerVisible.value = !drawerVisible.value
}

//修改密码
const editMm = () => {
  const result = userManagementStore.modifyPasswordStore(remakePw)
  if(result.code == 200){
    console.log('修改成功')
  }
}
  const props = defineProps({
    tableData: {
      type: Array,
      default: () => []
    }
  })
const input = ref('')
const value = ref('')
const name =ref('')
const phone =ref('')
const mail =ref('')
const add=ref(false)
const textarea = ref('')
const num = ref(1);
const handleChange = (value) => {
  num++;
  console.log(value);
};
const options = [
  {
    value: '10条/页',
    label: '10条/页',
  },
  {
    value: '20条/页',
    label: '20条/页',
  },
  {
    value: '30条/页',
    label: '30条/页',
  },
]
const gender = [
    {
      value:'男',
      label:'男',
    },
    {
      value:'女',
      label:'女',
    }, ]
  const userleixing = [
    {
      value:'普通用户',
      label:'普通用户',
    },
    {
      value:'管理员',
      label:'管理员',
    }]
  
    const tableData = [
  {
    number:'123',
    id:'123',
    name:'tom',
    avotor: '',
    affiliation: '精神科',
    phone: '123456789',
    gender: '男',
    type: '普通用户',
    state: '良好',
    time: '2024-2-1',
  }]
  const more = [
    {
      value:'刷新',
      label:'刷新',
    },
    {
      value:'重置用户密码',
      label:'重置用户密码',
    }, {
      value:'导出所选数据',
      label:'导出所选数据',
    },
    {
      value:'导出全部数据',
      label:'导出全部数据',
    },
    {
      value:'导入数据',
      label:'导入数据',
    }]
  
</script>

<style lang="scss" scoped>
.model{
  width: 200px;
  line-height: 100px;
  margin: 10px;
}
.dis{
  display: flex;
  justify-content:space-between;
}
.wid{
  width: 100px;
}
</style>
