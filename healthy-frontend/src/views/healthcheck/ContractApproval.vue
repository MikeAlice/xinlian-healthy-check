<!-- 合同审批 -->
<template>
  <el-container>
    <el-header class="header">
      <a class="header-text">首页</a>
      <a class="header-text">健康体检</a>
      <a class="header-text">团单审批</a>
    </el-header>
    <div class="right">
    <el-container>
      <el-aside width="200px">
        <PeopleListCG style="height: 100%; width: 100%">
          <template #form>
          <el-form :model="form">
            <el-form-item prop="name">
              <el-input v-model="form.name" placeholder="请输入关键字" clearable />
            </el-form-item>
          </el-form>
        </template>

          <template #table>
          <List></List>
        </template>
          <template #page>
          <el-pagination
            v-model:current-page="currentPage"
            v-model:page-size="pageSize"
            :page-sizes="[100, 200, 300, 400]"
            :small="small"
            :disabled="disabled"
            :background="background"
            layout="prev, jumper, next"
            :total="400"
            @size-change="handleSizeChange"
            @current-change="handleCurrentChange"
          />
        </template>
        </PeopleListCG>
      </el-aside>
      <el-main width="600px">
        <div display:flex size="large">
          <el-button size="default" @click="OpenCard">合同二级审核</el-button>
          <el-button size="default">评审报告预览</el-button>
          <el-button size="default">委托协议预览</el-button>
          <el-button size="default" @click="Open">查询基本信息</el-button>
        </div>

        <!-- 体检项目 -->
        <div>
          <div><el-text>体检项目</el-text></div>
          <el-tabs type="border-card" style="margin-bottom: 15px;">
          <el-tab-pane label="男">
         <SortTable :tableData="tableData1"/>
        </el-tab-pane>  
        <el-tab-pane label="女">
          <SortTable :tableData="tableData2"/>
        </el-tab-pane> </el-tabs>                  
        <div><el-text>体检人员</el-text></div>
        <PersonInfo :personInfo="tableData" style="margin-bottom: 15px" />
          <div display:flex class="line-text">共0条
            <el-select
    v-model="value"
    class="m-2"
    placeholder="Select"
    size="large"
    style="width: 140px"
  >
    <el-option
      v-for="item in options"
      :key="item.value"
      :label="item.label"
      :value="item.value"
    />
  </el-select>
  跳至
      <el-input-number v-model="num" :min="1" :max="10" @change="handleChange" />
      页
          </div>
          <h3>订单合计:  sum ￥元</h3>
        </div>
      </el-main>
    </el-container>
    </div>
      </el-container>
      <!-- 基本信息 -->
      <el-drawer
      v-model="drawer" title="基本信息"
  >
          <span class="drawer-text">
            <div>合同名称:</div>
            <div>合同编号:</div>
            <div>委托单位:</div>
            <div>委托内容:</div>
            <div>编制部门:</div>
            <div>编制人:</div>
            <div>审核人:</div>
            <div>审核状态:</div>
            <div>联系人:</div>
            <div>联系电话:</div>
            <div>审核日期:</div>
            <div>销售负责人:</div>
            <div>签订时间:</div>
            <div>交付时间:</div></span>
            <el-button @click="Close">关闭</el-button>
      </el-drawer>
      <!-- 合同二级审核弹窗 -->
      <el-dialog v-model="card"  >
        <el-container>
      <el-header >合同二级审核</el-header>
      <el-container>
        <el-aside width="400px"><el-tabs type="border-card" style="margin-bottom: 15px;">
          <el-tab-pane label="委托协议">
        </el-tab-pane>  
        <el-tab-pane label="营业执照">
        </el-tab-pane> </el-tabs>
        </el-aside>
        <el-container>
          <el-main width="300px"> <div class="a">1.用人单位提供的资料（盖鲜章）</div>radio4
            <div class="dialog-text">1.用人单位基本情况信息表</div>
            <el-radio-group v-model="radio1">
      <el-radio label="no" size="large">否</el-radio>
      <el-radio label="yes" size="large">是</el-radio>
    </el-radio-group>
            <div class="dialog-text">2.近期职业病危害因素检测报告或评价报告</div>
            <el-radio-group v-model="radio2">
      <el-radio label="no">否</el-radio>
      <el-radio label="yes">是</el-radio>
    </el-radio-group>
            <div class="dialog-text">3.营业执照（三证合一）</div>
            <el-radio-group v-model="radio3" >
      <el-radio label="no" size="small">否</el-radio>
      <el-radio label="yes" size="small">是</el-radio>
    </el-radio-group>
            <div class="dialog-text">4.合同（委托书）</div>
            <el-radio-group v-model="radio4" >
      <el-radio label="no" size="small">否</el-radio>
      <el-radio label="yes" size="small">是</el-radio>
    </el-radio-group>
            <div class="dialog-text">5.与体检人员名单信息（姓名，性别，身份证号，手机号，工龄，岗位，职业病危害因素，接害工龄等）</div>
            <el-radio-group v-model="radio5">
      <el-radio label="no" size="small">否</el-radio>
      <el-radio label="yes" size="small">是</el-radio>
    </el-radio-group>
          </el-main>
          <el-footer><el-button @click="CloseCard">取消</el-button>
              <el-button>提交</el-button>
</el-footer>
        </el-container> 
      </el-container>
    </el-container>
    
  </el-dialog>
</template>
<script setup>
import { ref,reactive } from 'vue';
import PeopleListCG from '@/components/peoplelist/PeopleList-CG.vue'
import List from '@/components/peoplelist/List.vue'
const value = ref('')

//搜索框字段
const form = reactive({
  name:''
})
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
const num = ref(1);
const handleChange = (value) => {
  num.value++;
  console.log(value);
};

const drawer = ref(false)
// 打开抽屉
const Open = () => {
  drawer.value=true;
}
// 关闭抽屉
const Close = () =>{
  drawer.value=false;
}
// 打开卡片
const card = ref(false)
const OpenCard = () => {
  card.value=true;
}
// 关闭卡片
const CloseCard = () => {
  card.value=false;
}
const radio1 = ref('yes')
const radio2 = ref('yes')
const radio3 = ref('yes')
const radio4 = ref('yes')
const radio5 = ref('yes')
</script>

<style lang="scss" scoped>

</style>
<style>
.header{
  background-color: blue;
  text-align: center;
  font-size: large;
  height: 50px;
}
.header-text{
  line-height: 25px;
}
.header-text{
  margin: 30px;
}
.line-text{
  text-align: right;
}
.drawer-text{
  line-height: 40px;
  text-align: center;
}
.a{
  font-size: 25px;
}
.dialog-text{
  font-size: 15px;
}
</style>
