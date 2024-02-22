<!-- 部门管理 -->
<template>
  <el-tabs type="border-card">
    <el-tab-pane label="树结构">
      <el-container>
        <el-header>
          <div class="dis">
            <el-button @click="add">添加子部门</el-button>
            <el-button @click="adddeparitment">添加一级部门</el-button>
            <el-button>批量删除</el-button>
            <el-button @click="refresh">刷新</el-button>
            <el-switch v-model="value1" witdh="50px" inline-prompt active-text="级联" inactive-text="不级联" />
          </div>
        </el-header>
        <!-- 添加子部门 -->
        <el-dialog v-model="openbutton1" width="30%">
          <el-card>
            <template #header> 添加子部门 </template>
            <div>上级部门：宜宾美年大健康体检中心</div>
            <div>部门名称<el-input v-model="name"></el-input></div>
            <div>排序值<el-input v-model="number"></el-input></div>
            <div>是否启用 <el-switch v-model="value1" witdh="50px" inline-prompt active-text="启用" inactive-text="不启用" /></div>
            <template #footer><el-button @click="close">取消</el-button><el-button>提交</el-button></template>
          </el-card>
        </el-dialog>
        <!-- 添加一级部门 -->
        <el-dialog v-model="department" width="30%">
          <el-card>
            <template #header> 添加一级部门 </template>
            <div>部门名称<el-input v-model="name"></el-input></div>
            <div>排序值<el-input v-model="number"></el-input></div>
            <div>是否启用 <el-switch v-model="value1" witdh="50px" inline-prompt active-text="启用" inactive-text="不启用" /></div>
            <template #footer><el-button @click="closedepartment">取消</el-button><el-button>提交</el-button></template>
          </el-card>
        </el-dialog>

        <el-container>
          <el-aside>
            <el-aside width="400px">
              <!-- 提示框 -->
              <div class="hint">
                <span>
                  <el-icon style="color: blue">
                    <InfoFilled></InfoFilled>
                  </el-icon>
                  当前选择编辑： {{ selectWhich }}
                </span>
              </div>
              <el-input v-model="menuName" style="width: 380px; margin: 10px" placeholder="请输入菜单名搜索" :suffix-icon="Search" />
            </el-aside>
          </el-aside>
          <el-main>
            <div display:column>
              <div display:flex class="text">
                上级部门<el-input v-model="input" class="input-1" />
                <!-- 弹出框 -->
                <el-popover placement="bottom" title="选择上级部门" :width="200" trigger="click" content="this is content, this is content, this is content">
                  <template #reference>
                    <el-button @click="Selectdepartment">选择部门</el-button>
                  </template>
                </el-popover>
              </div>
              <div class="text">*部门名称 <el-input v-model="input" class="input-1" /></div>
              <div class="text">部门负责人 <el-input v-model="input" class="input-1" /> <el-button @click="Selectpeople1">选择用户</el-button></div>
              <div class="text">副负责人 <el-input v-model="input" class="input-1" /> <el-button @click="Selectpeople2">选择用户</el-button></div>
              <div class="text">
                *排序值
                <el-popover placement="right" :width="200" trigger="hover" content="值越小越靠前，支持小数">
                  <template #reference> <el-input-number v-model="num" :min="1" :max="10" @change="handleChange" /></template
                ></el-popover>
              </div>
              <div>是否启用<el-switch v-model="value1" witdh="50px" inline-prompt active-text="启用" inactive-text="不启用" /></div>
            </div>
            <el-button>修改并保存</el-button><el-button>重置</el-button>
          </el-main>
        </el-container>
      </el-container>
    </el-tab-pane>
    <!-- 列表 -->
    <el-tab-pane label="列表">
      <el-container>
        <el-header>
          <el-button @click="adddeparitment">添加一级部门</el-button>
          <el-button>批量删除</el-button>
          <el-button @click="refresh">刷新</el-button>
          <el-input v-model="departmentName" style="width: 380px; margin: 10px" placeholder="请输入菜单名搜索" :suffix-icon="Search" />
        </el-header>
        <div class="dis">
          已选择20项
          <div>清空</div>
        </div>
        <el-button @click="close">关闭提示</el-button>
        <el-table :data="tableData" height="250" border :cell-style="{ textAlign: 'center' }" :header-cell-style="{ 'text-align': 'center' }" style="width: 100%">
          <el-table-column prop="" label="" width="60" />
          <el-table-column prop="number" label="#" width="60" />
          <el-table-column prop="name" label="部门名称" />
          <el-table-column prop="id" label="排序" />
          <el-table-column prop="time" label="创建时间" />
          <el-table-column fixed="right" label="操作" width="240">
            <template #default>
              <el-button link type="primary" size="small">添加子部门</el-button>
              <el-button link type="primary" size="small">删除</el-button>
            </template>
          </el-table-column>
        </el-table>
      </el-container>
    </el-tab-pane>
  </el-tabs>
</template>

<script setup>
import { ref } from 'vue'
import { ArrowUp, ArrowDown, Search, Plus, InfoFilled, Refresh, DeleteFilled, Bottom, View, Edit } from '@element-plus/icons-vue'
// import {usephysicalexaminationStore} from'@stores/physicalexamination/index.js'
//stores方法
// const physicalexaminationStore=usephysicalexaminationStore()

//  const modifyreference = async (params) => {
//    return await physicalexaminationStore.modifyreference(params)
//  }
//  const removereference = async (params) => {
//    return await physicalexaminationStore.removereference(params)
//  }
//  const queryall = async (params) => {
//    return await physicalexaminationStore.queryall(params)
//  }
//  const queryrules = async (params) => {
//    return await physicalexaminationStore.queryrules(params)
//  }
//  const modifyrules = async (params) => {
//    return await physicalexaminationStore.modifyrules(params)
//  }
//  const getlistdetails = async (params) => {
//    return await physicalexaminationStore.getlistdetails(params)
//  }
//  const addlistdetails = async (params) => {
//    return await physicalexaminationStore.addlistdetails(params)
//  }
//  const addproject = async (params) => {
//    return await physicalexaminationStore.addproject(params)
//  }
//  constselectproject = async (params) => {
//    return await physicalexaminationStore.selectproject(params)
//  }
//  const getproject = async (params) => {
//    return await physicalexaminationStore.getproject(params)
//  }
//  const addvalue = async (params) => {
//    return await physicalexaminationStore.addvalue(params)
//  }
//  const getvalue = async (params) => {
//    return await physicalexaminationStore.getvalue(params)
//  }
//  const newpackage = async (params) => {
//    return await physicalexaminationStore.newpackage(params)
//  }
//  const deletepackage = async (params) => {
//    return await physicalexaminationStore.deletepackage(params)
//  }
//  const modifypackage = async (params) => {
//    return await physicalexaminationStore.modifypackage(params)
//  }
//  const deltbp = async (params) => {
//    return await physicalexaminationStore.deltbp(params)
//  }
//  const updatetbp = async (params) => {
//    return await physicalexaminationStore.updatetbp(params)
//  }
//  const deletepackagerisis = async (params) => {
//    return await physicalexaminationStore.deletepackagerisis(params)
//  }
//  const modifypackagerisis = async (params) => {
//    return await physicalexaminationStore.deletepackagerisis(params)
//  }

const value1 = ref(true)
const input = ref('')
const num = ref(1)
const selectWhich = ref('')
const menuName = ref('')
const openbutton1 = ref(false)
const departmentName = ref('')
const add = () => {
  openbutton1.value = true
}
const close = () => {
  openbutton1.value = false
}
const department = ref(false)
const adddeparitment = () => {
  department.value = true
}
const closedepartment = () => {
  department.value = false
}
const handleChange = (value) => {
  num.value++
  console.log(value)
}
const tableData = [
  {
    number: '123',
    name: 'abc',
    id: 'ac',
    time: 'a'
  }
]
</script>

<style lang="scss" scoped>
.input-1 {
  width: 200px;
  line-height: 100px;
  margin: 10px;
}
.text {
  text-align: left;
}
.dis {
  display: flex;
}
.hint {
  position: relative;
  height: 48px;
  padding: 10px;
  border: 1px solid RGB(171, 220, 255);
  border-radius: 5px;
  margin: 10px 5px;
  background-color: RGB(240, 250, 255);
}
</style>
