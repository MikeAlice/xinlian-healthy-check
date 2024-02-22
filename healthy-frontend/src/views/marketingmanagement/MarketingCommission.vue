<!-- 营销提成 -->
<!-- 团检订单 -->
<template>
  <el-container style="height: 100%">
    <el-main style="">
      <!-- 表单 -->
      <el-form :inline="true" :model="formInline" class="demo-form-inline" style="padding: 0 25px">
        <el-form-item label="编号">
          <el-select v-model="value" placeholder="请选择" style="min-width: 192px">
            <el-option v-for="item in options" :key="item.value" :label="item.label" :value="item.value" />
          </el-select>
        </el-form-item>
        <el-form-item label="订单类型">
          <el-select v-model="value" placeholder="请选择" style="min-width: 192px">
            <el-option v-for="item in options" :key="item.value" :label="item.label" :value="item.value" />
          </el-select>
        </el-form-item>
        <el-form-item label="体检类型">
          <el-select v-model="value" placeholder="请选择" style="min-width: 192px">
            <el-option v-for="item in options" :key="item.value" :label="item.label" :value="item.value" />
          </el-select>
        </el-form-item>
        <el-form-item label="签订时间">
          <el-date-picker v-model="value1" type="datetime" placeholder="选择日期" />
        </el-form-item>
        <el-form-item label="交付时间">
          <el-date-picker v-model="value1" type="datetime" placeholder="选择日期" />
        </el-form-item>

        <!-- 按钮 -->
        <el-row style="margin-bottom: 15px">
          <el-button type="primary">
            <el-icon><Edit /></el-icon>
            查询
          </el-button>
          <el-button>
            重置
          </el-button>
        </el-row>
      </el-form>

      <!-- 表格 -->
      <el-table :data="tableData" border :cell-style="{ textAlign: 'center' }" :header-cell-style="{ 'text-align': 'center' }" style="width: 100%">
      <el-table-column prop="id" label="#" width="60" />
      <el-table-column prop="name" label="状态" />
      <el-table-column prop="name" label="体检分类" />
      <el-table-column prop="result" label="名称" />
      <el-table-column prop="unit" label="销售人员" />
      <el-table-column prop="reference" label="体检类型" />
      <el-table-column prop="prompt" label="预检人数" />
      <el-table-column prop="prompt" label="实检人数" />
      <el-table-column prop="prompt" label="增项金额" />
      <el-table-column prop="prompt" label="超限金额" />
      <el-table-column prop="prompt" label="复检金额" />
      <el-table-column prop="prompt" label="弃检金额" />
      <el-table-column prop="prompt" label="退费金额" />
      <el-table-column prop="prompt" label="原价金额" />
      <el-table-column prop="prompt" label="折扣金额" />
      <el-table-column prop="prompt" label="实收金额" />
      <el-table-column prop="prompt" label="提成" />
      <el-table-column prop="prompt" label="提成比例" />
      <el-table-column prop="prompt" label="提成绩效" />
      <el-table-column prop="prompt" label="操作" width="150">
        <template #default="scope">
          <el-button-group>
            <el-button size="small" @click="handleEdit(scope.$index, scope.row)">
                <el-icon><icon-view /></el-icon>
            </el-button>
            <el-button size="small" @click="handleEdit(scope.$index, scope.row)">
                <el-icon><icon-edit /></el-icon>
            </el-button>
            <el-button type="danger" size="small" @click="handleDelete(scope.$index, scope.row)">
                <el-icon><icon-delete /></el-icon>
            </el-button>
          </el-button-group>
        </template>
      </el-table-column>
    </el-table>
    </el-main>
  </el-container>
</template>

<script setup>
import { ref } from 'vue'

const form = ref({
  checkbox: '',
  slider: '',
  date: '',
  serialNumber: '',
  workplace: '',
  name: '',
  startDate: '',
  endDate: ''
})

// 单选框
const radio1 = ref('1')

const tableData = [
  {
    id: '1',
    name: 'Tom',
    result: '正常',
    unit: '-',
    reference: '114514',
    prompt: '-',
    abnormal: false
  },
  {
    id: '2',
    name: 'Tom',
    result: '不正常',
    unit: '-',
    reference: '114514',
    prompt: '-',
    abnormal: true
  },
  {
    id: '3',
    name: 'Tom',
    result: '正常',
    unit: '-',
    reference: '114514',
    prompt: '-',
    abnormal: false
  },
  {
    id: '4',
    name: 'Tom',
    result: '正常',
    unit: '-',
    reference: '114514',
    prompt: '-',
    abnormal: false
  },
  {
    id: '5',
    name: 'Tom',
    result: '正常',
    unit: '-',
    reference: '114514',
    prompt: '-',
    abnormal: false
  },
  {
    id: '6',
    name: 'Tom',
    result: '不正常',
    unit: '-',
    reference: '114514',
    prompt: '-',
    abnormal: true
  }
]

// 分页相关
const currentPage1 = ref(5)
const currentPage2 = ref(5)
const currentPage3 = ref(5)
const currentPage4 = ref(4)
const pageSize2 = ref(100)
const pageSize3 = ref(100)
const pageSize4 = ref(100)
const small = ref(false)
const background = ref(false)
const disabled = ref(false)

// const handleSizeChange = (val: number) => {
//   console.log(`${val} items per page`)
// }
// const handleCurrentChange = (val: number) => {
//   console.log(`current page: ${val}`)
// }

// 日期相关
const value1 = ref('')
const value2 = ref('')
const value3 = ref('')
const defaultTime = new Date(2000, 1, 1, 12, 0, 0)

const shortcuts = [
  {
    text: 'Today',
    value: new Date()
  },
  {
    text: 'Yesterday',
    value: () => {
      const date = new Date()
      date.setTime(date.getTime() - 3600 * 1000 * 24)
      return date
    }
  },
  {
    text: 'A week ago',
    value: () => {
      const date = new Date()
      date.setTime(date.getTime() - 3600 * 1000 * 24 * 7)
      return date
    }
  }
]
</script>

<style lang="scss" scoped>
.alter {
  background-color: #f0faff;
  border: 1px solid #b7e0ff;
  padding: 6px;
  border-radius: 5px;

  span {
    color: #000;
    font-weight: 600;
    font-size: small;
    margin-right: 15px;
  }
}
</style>
