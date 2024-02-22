<!-- 团检订单 -->
<template>
  <el-container style="height: 100%">
    <el-aside width="250px">
      <PeopleListCG style="height: 100%; width: 100%">
        <!-- 表单 -->
        <template #form>
          <el-form :model="form">
            <el-form-item prop="date">
              <el-row clearable>
                <el-date-picker v-model="form.startDate" type="date" placeholder="开始时间" style="width: 46%" />
                <span style="width: 8%; padding: 0 4px">~</span>
                <el-date-picker v-model="form.endDate" type="date" placeholder="结束时间" style="width: 46%" />
              </el-row>
            </el-form-item>
            <el-form-item prop="name">
              <el-input v-model="form.name" placeholder="请输入关键字" clearable />
            </el-form-item>
            <!-- 重置 -->
            <el-button @click="onSubmit" size="small">重置</el-button>
          </el-form>
        </template>

        <!-- 表格 -->
        <template #table>
          <List></List>
        </template>

        <!-- 分页 -->
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
    <el-main style="">
      <!-- 按钮 -->
      <el-row style="margin-bottom: 15px">
        <el-button type="primary">
          <el-icon><Edit /></el-icon>
          Primary
        </el-button>
        <el-button type="primary">
          <el-icon><Edit /></el-icon>
          Primary
        </el-button>
        <el-button type="primary">
          <el-icon><Edit /></el-icon>
          Primary
        </el-button>
        <el-button type="primary">
          <el-icon><Edit /></el-icon>
          Primary
        </el-button>
        <el-button type="primary">
          <el-icon><Edit /></el-icon>
          Primary
        </el-button>
      </el-row>

      <!-- 表单 -->
      <el-form :inline="true" :model="formInline" class="demo-form-inline" style="padding: 0 25px">
        <el-form-item label="团检单号">
          <el-input v-model="input3" placeholder="团检单号" class="input-with-select" disabled style="max-width: 220px">
            <template #append>
              <el-button>未确认</el-button>
            </template>
          </el-input>
        </el-form-item>
        <el-form-item label="团检单位">
          <el-select v-model="value" placeholder="请选择" style="min-width: 192px">
            <el-option v-for="item in options" :key="item.value" :label="item.label" :value="item.value" />
          </el-select>
        </el-form-item>
        <el-form-item label="销售负责人">
          <el-select v-model="value" placeholder="请选择" style="min-width: 192px">
            <el-option v-for="item in options" :key="item.value" :label="item.label" :value="item.value" />
          </el-select>
        </el-form-item>
        <el-form-item label="签订日期">
          <el-date-picker v-model="value1" type="datetime" placeholder="选择日期" />
        </el-form-item>
        <el-form-item label="体检日期">
          <el-date-picker v-model="value1" type="datetime" placeholder="选择日期" />
        </el-form-item>
        <el-form-item label="零星体检">
          <el-select v-model="value" placeholder="请选择" style="min-width: 192px">
            <el-option v-for="item in options" :key="item.value" :label="item.label" :value="item.value" />
          </el-select>
        </el-form-item>
        <el-form-item label="是否需要合同审批">
          <div class="mb-2 flex items-center text-sm">
            <el-radio-group v-model="radio1" class="ml-4">
              <el-radio label="1" size="large">否</el-radio>
              <el-radio label="2" size="large">是</el-radio>
            </el-radio-group>
          </div>
        </el-form-item>
      </el-form>

      <!-- 体检项目 -->
      <Head name="体检项目">
        <span>
          <el-button type="primary" size="small">
            <el-icon><icon-edit /></el-icon>
            <span>编辑分组</span>
          </el-button>
          <el-button type="primary" size="small">
            <el-icon><icon-edit /></el-icon>
            <span>套餐选择</span>
          </el-button>
          <el-button type="primary" size="small">
            <el-icon><icon-edit /></el-icon>
            <span>编辑分组</span>
          </el-button>
        </span>
      </Head>
      <!-- 分页标签 -->
      <el-tabs type="border-card" style="margin-bottom: 15px">
        <el-tab-pane label="男">
          <ActionTable :tableData="tableData1" />
        </el-tab-pane>
        <el-tab-pane label="女">
          <ActionTable :tableData="tableData2" />
        </el-tab-pane>
      </el-tabs>

      <!-- 体检人员 -->
      <Head name="体检人员"></Head>
      <!-- 表格 -->
      <el-table :data="tableData1" height="250" border :cell-style="{ textAlign: 'center' }" :header-cell-style="{ 'text-align': 'center' }" style="width: 100%">
        <el-table-column type="selection" width="60" />
        <el-table-column prop="name" label="姓名" />
        <el-table-column prop="result" label="性别" />
        <el-table-column prop="unit" label="证件号码" />
        <el-table-column prop="reference" label="年龄" />
      </el-table>
      <!-- 分页 -->
      <div class="demo-pagination-block" style="display: flex; justify-content: end; margin-top: 15px">
        <el-pagination
          v-model:current-page="currentPage4"
          v-model:page-size="pageSize4"
          :page-sizes="[10, 20, 50]"
          :small="small"
          :disabled="disabled"
          :background="background"
          layout="total, sizes, prev, pager, next, jumper"
          :total="200"
          @size-change="handleSizeChange"
          @current-change="handleCurrentChange"
        />
      </div>
    </el-main>
  </el-container>
</template>

<script setup>
import { ref } from 'vue'
import ActionTable from '@/components/details/ActionTable.vue'
import PeopleListCG from '@/components/peoplelist/PeopleList-CG.vue'
import List from '@/components/peoplelist/List.vue'
import Head from '@/components/head/Head.vue'

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

const tableData1 = [
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
