<template>
  <div class="Leftside_bar">
    <!-- 顶部标题区域 -->
    <template v-if="props?.useHeader">
      <div class="card-header">
        <span>{{ props.title }}</span>
      </div>
    </template>
    <!-- 是否使用el-tabs-插槽 -->
    <div class="change-page">
      <slot name="change-page"></slot>
    </div>

    <!-- 主体部分 -->
    <div class="card-body">
      <!-- 使用多个按钮组(插槽) -->
      <div class="button-group">
        <slot name="button-group"></slot>
      </div>

      <!-- 使用搜索框(插槽) -->
      <div class="search-bar">
        <slot name="search-bar"></slot>
      </div>

      <!-- 表单区域 -->
      <el-form ref="formRef" :model="form">
        <template #default>
          <el-row>
            <el-form-item v-if="props.isShowCheckbox" prop="checkbox" style="display: flex; margin-right: auto">
              <el-radio-group v-model="form.checkbox">
                <!-- <el-radio v-for="item in checkboxItem" :key="item" :label="item" /> -->
                <el-radio label="已检" />
                <el-radio label="未检" />
              </el-radio-group>
            </el-form-item>

            <el-form-item v-if="props.isShowSwitch" prop="switch">
              <el-switch v-model="form.switch" inline-prompt active-text="复查" inactive-text="非复" @change="(state) => emits('updateSwitchState', state, row)"></el-switch>
            </el-form-item>
          </el-row>

          <!-- 日期组件 -->
          <el-form-item v-if="props.isDateVisible" prop="date">
            <el-row clearable>
              <el-date-picker v-model="form.startDate" style="width: 49%" type="date" placeholder="开始时间" />
              <span style="width: 2%">~</span>
              <el-date-picker v-model="form.endDate" style="width: 49%" type="date" placeholder="结束时间" />
            </el-row>
          </el-form-item>

          <!-- 查询输入框区域 -->
          <el-form-item v-if="props.isShowNameInput" prop="name">
            <el-input v-model="form.name" placeholder="请输入姓名" clearable />
          </el-form-item>
          <!-- 从父组件传入的其他表单项 -->
          <!-- <div v-if="isShowInput">
            <el-form-item v-for="(item, index) of externalFormItems" :key="index">
              <el-input v-model="item.name" :placeholder="item.placeholder" clearable />
            </el-form-item>
          </div> -->

          <!-- 从父组件传入的其他表单项(插槽方式，暂时保留) -->
          <!-- 以下是示例代码，在没有接口数据传入之前，没有死数据填充会导致被折叠的输入框不展开 -->
          <template v-if="isShowInput">
            <!-- 身份证搜索框(插槽) -->
            <slot name="id-input"></slot>
            <el-form-item prop="serialNumber">
              <el-input v-model="form.serialNumber" placeholder="请输入体检编号" clearable />
            </el-form-item>
            <el-form-item prop="workplace">
              <el-input v-model="form.workplace" placeholder="请输入单位名称" clearable></el-input>
            </el-form-item>
          </template>

          <!-- 表单按钮区域 -->
          <el-form-item>
            <el-button type="primary" @click="onSubmit">查询</el-button>
            <el-button plain @click="resetForm">重置</el-button>
            <el-button type="text" style="margin-left: 14px" @click="toggleCollapse"
              >{{ isShowInput ? '收起' : '展开' }}
              <el-icon v-show="isShowInput == true"><ArrowUp /></el-icon>
              <el-icon v-show="isShowInput == false"><ArrowDown /></el-icon>
            </el-button>
          </el-form-item>
        </template>
      </el-form>

      <!-- 表格区域 -->
      <!-- 需要替换表格测试(插槽) -->
      <div class="table-area">
        <slot name="table-area"></slot>
      </div>

      <!-- 原表格，可以注释掉以测试列表样式 -->
      <el-table v-loading="openLoading" style="font-size: 12px; width: 100%; height: 350" table-layout="auto" :data="props?.tableData" @selection-change="handleSelectionChange">
        <!-- 第一列：多选 -->
        <el-table-column v-if="props?.useSelectColumn" type="selection" width="15" />
        <!-- <el-table-column prop="name" label="姓名" width="55"></el-table-column>
        <el-table-column prop="gender" label="性别" width="55"></el-table-column>
        <el-table-column prop="age" label="年龄" width="55"></el-table-column>
        <el-table-column prop="tag" label="标签" style="display: flex">
          <template #default>
            <el-tag :type="info">好</el-tag>
            <el-tag :type="info">坏</el-tag>
          </template>
        </el-table-column> -->

        <el-table-column v-for="item in props?.tableColumnAttribute" :key="item" :prop="item.prop" class-name="class-name">
          <!-- 表格的列内容如果使用tag -->
          <template v-if="item.useTag" #default="{ row }">
            <el-tag :type="row[item.prop].tagType">
              {{ row[item.prop].value }}
            </el-tag>
          </template>
        </el-table-column>

        <!-- 表格没有数据的样式 -->
        <!-- <template #empty>
          <el-empty class="emptyTable" description="没有数据"></el-empty>
        </template> -->
      </el-table>

      <!-- 分页器 -->
      <template v-if="props?.usePagination">
        <el-pagination
          v-model:current-page="paginationData.currentPage"
          v-model:page-size="paginationData.pageSize"
          :page-sizes="props.pageSizes"
          layout=" prev,pager, next"
          :total="props.total"
          pager-count="5"
          @size-change="handleSizeChange"
          @current-change="handleCurrentChange"
        />
      </template>
    </div>
  </div>
</template>

<script setup>
import { ref } from 'vue'
import { ArrowUp, ArrowDown } from '@element-plus/icons-vue'

const props = defineProps({
  // 顶部栏标题
  title: {
    type: String,
    required: 'true',
    default: '人员列表'
  },
  // 是否使用header
  useHeader: {
    type: Boolean,
    default: true
  },
  // 是否使用checkbox
  isShowCheckbox: {
    type: Boolean,
    default: true
  },
  // 当前checkbox状态
  checkboxItem: {
    type: Array,
    require: true,
    default: () => {
      return ['已检', '未检', '已登记', '未登记', '未确认', '已确认', '在检', '待检', '已总检']
    }
  },
  // 当前switch状态
  checkSwitchItem: {
    type: Array,
    require: true,
    default: () => {
      return ['复查', '非复']
    }
  },
  // 是否使用滑块开关
  isShowSwitch: {
    type: Boolean,
    default: true
  },
  // 是否显示日期组件
  isDateVisible: {
    type: Boolean,
    default: true
  },
  // 是否显示姓名搜索框
  isShowNameInput: {
    type: Boolean,
    default: true
  },
  // 是否显示身份证号搜索框
  isShowIdInput: {
    type: Boolean,
    default: false
  },
  // 表格的列属性
  tableColumnAttribute: {
    type: Array,
    require: true,
    default: () => ['你好', '不好']
  },
  // 表格数据
  tableData: {
    type: Array,
    default: () => []
  },
  // 是否使用使用多选列
  useSelectColumn: {
    type: Boolean,
    default: true
  },
  // 表格每页的数据容量
  pageSizes: {
    type: Array,
    default: () => {
      return [5]
    }
  },
  // 表格的数据数量
  total: {
    type: Number,
    require: true,
    default: 50
  },
  // 是否使用分页器
  usePagination: {
    type: Boolean,
    default: true
  },

  // 查询表单内容配置
  externalFormItems: {
    type: Array,
    default: () => []
  }
})

// 表单验证逻辑
const formRef = ref([])
const form = ref({
  // 设置默认选择哪个状态
  checkbox: props.checkboxItem[0],
  // checkbox: '已检',
  switch: false,
  name: '',
  id: '',
  date: '',
  startDate: '',
  endDate: ''
})

// 表格的loading
const openLoading = ref(false)

// 滑块开关的loading
const openSwitchLoading = ref(false)

// 定义行数据
const rows = ref([])

// 处理表格的选择框发生变化时的回调函数
const handleSelectionChange = (newRows) => {
  rows.value = newRows
  // 通过emit向父组件传递数据( 这里是向父组件传递一个数组, 数组中存放的是被选中的行数据的长度)
  emits('selectTableChange', newRows.length)
}

// 调用父组件更新表格的数据
// 调用父组件数据修改滑块开关的函数：updateSwitchState
const emits = defineEmits(['updateSwitchState'], ['updateTableData'], ['selectTableChange'])

const handleSizeChange = (pageSize) => {
  // 当前页的数据容量改变，重置页码为1
  paginationData.value.pageSize = pageSize
  paginationData.value.currentPage = 1
  // 传入当期那页面的容量大小和当前页码
  emits('updateTableData', pageSize, paginationData.value.currentPage)
}
const handleCurrentChange = (currentPage) => {
  paginationData.value.currentPage = currentPage
  // 传入当前页码容量(默认值5)和当前页码
  emits('updateTableData', paginationData.value.pageSize, currentPage)
}

// 提交表单查询逻辑
const onSubmit = () => {
  console.log('submit')
}
// 重置表单逻辑
const resetForm = () => {
  // 重置固定的表单项
  form.value.name = ''
  // 遍历所有动态添加的表单项，并将它们重置
  props.externalFormItems.forEach((item) => {
    item.name = ''
  })
}
// 点击展开按钮按钮的折叠逻辑
const isShowInput = ref(false)
const toggleCollapse = () => {
  isShowInput.value = !isShowInput.value
}

// 表格数据存放区域
// const defaultTableData = [
//   {
//     name: '张楠楠',
//     gender: '女',
//     age: '30',
//     tag: '健'
//   },
//   {
//     name: '张楠楠',
//     gender: '女',
//     age: '30',
//     tag: '零'
//   },
//   {
//     name: '张楠楠',
//     gender: '女',
//     age: '30',
//     tag: '零'
//   },
//   {
//     name: '张楠楠',
//     gender: '女',
//     age: '30',
//     tag: '零'
//   },
//   {
//     name: '张楠楠',
//     gender: '女',
//     age: '30',
//     tag: '零'
//   },
//   {
//     name: '张楠楠',
//     gender: '女',
//     age: '30',
//     tag: '零'
//   },
//   {
//     name: '张楠楠',
//     gender: '女',
//     age: '30',
//     tag: '零'
//   },
//   {
//     name: '张楠楠',
//     gender: '女',
//     age: '30',
//     tag: '零'
//   },
//   {
//     name: '张楠楠',
//     gender: '女',
//     age: '30',
//     tag: '零'
//   },
//   {
//     name: '张楠楠',
//     gender: '女',
//     age: '30',
//     tag: '零'
//   }
// ]

// 分页数据的处理逻辑
const paginationData = ref({
  currentPage: 1,
  pageSize: props.pageSizes ? props.pageSizes[0] : 5
})

// 表单的相关属性方法还未解决完
defineExpose({
  // 表单部分
  form,
  formRef,
  // 开关的loading
  openSwitchLoading,
  // 暴露出被选中的row
  rows,
  // 暴露出表格的加载
  openLoading,
  // 暴露出分页数据
  paginationData
})
</script>

<style lang="scss" scoped>
.Leftside_bar {
  width: 100%;
  height: 100%;
  background-color: #fff;
}

.card-header {
  min-height: 5%;
  width: 100%;
  display: flex;
  text-align: center;
  justify-content: center;
  align-items: center;
  background-color: #f0faff;
  border: 1px solid #abdcff;

  span {
    font-size: 14px;
    font-weight: 550;
    text-align: center;
  }
}

.card-body {
  height: 95%;
  width: 100%;
  padding: 15px;
  background-color: #fff;
}
.card-body:hover {
  box-shadow: rgba(100, 100, 111, 0.2) 0px 7px 9px 0px;
}

.emptyTable {
  min-width: auto;
  min-height: auto;
}

.el-pagination {
  display: flex;
  justify-content: center;
  align-items: center;
  text-align: center;
  margin-top: 30px;
  position: absolute;
  bottom: 0;
}
</style>
