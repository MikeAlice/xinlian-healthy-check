<template>
  <div class="base_data_list">
    <el-card class="box-card">
      <template v-if="props?.useForm" #header>
        <!-- form表单 -->
        <el-form ref="formRef" :model="formData" inline>
          <slot name="form"></slot>
        </el-form>
      </template>
      <div class="main">
        <!-- 功能栏 -->
        <slot name="operation"></slot>
        <!-- 多选清除栏 -->
        <slot name="hint"></slot>
        <!-- table表格 -->
        <el-table
          v-if="childrenData"
          ref="tableRef"
          :data="props?.tableData"
          border
          row-key="id"
          lazy
          :load="load"
          :tree-props="{ children: 'children', hasChildren: 'hasChildren' }"
          @selection-change="handleSelectionChange"
          @select="selectTc"
        >
          <!-- 多选列 -->
          <el-table-column v-if="useSelection" type="selection"></el-table-column>
          <!-- 表格内容 -->
          <el-table-column v-for="item in props.tableColumnAttribute" :key="item" :prop="item.prop" :label="item.label" :width="item.width" :align="item.align">
            <!-- 是否使用switch开关 -->
            <template v-if="item.useSwitch" #default="{ row }">
              <el-switch :model-value="row[item.prop] ? true : false" inline-prompt active-text="启用" inactive-text="停用" size="large" @change="(state) => emits('updateSwitchState', state, row)" />
            </template>
          </el-table-column>
          <!-- 固定列 -->
          <el-table-column v-if="props.useFixed" fixed="right" label="操作" width="220">
            <template #default="{ row }">
              <slot name="fixed" :row="row"></slot>
            </template>
          </el-table-column>
        </el-table>
        <!-- 分页 -->
        <template v-if="props.usePagination">
          <el-pagination
            v-model:current-page="props.paginationData.currentPage"
            v-model:page-size="props.paginationData.pageSize"
            layout="total,prev, pager, next, jumper, ->"
            :total="props.total"
            style="margin-top: 30px; justify-content: flex-end"
            @current-change="handleCurrentChange"
          />
        </template>
      </div>
    </el-card>
  </div>
</template>

<script setup>
import { watch, ref } from 'vue'
const childrenData = ref(true)
const props = defineProps({
  //是否使用树形数据
  childrenData: {
    type: Boolean,
    default: false
  },
  // 是否使用Form表单
  useForm: {
    type: Boolean,
    default: false
  },
  // 是否使用多选
  useSelection: {
    type: Boolean,
    default: true
  },
  // form表单数据
  formData: {
    type: Object,
    require: true
  },
  // 表格数据
  tableData: {
    type: Array,
    require: true
  },
  // 表格列属性
  tableColumnAttribute: {
    type: Array,
    require: true
  },
  // 是否使用固定列
  useFixed: {
    type: Boolean,
    default: false
  },
  // 分页参数
  paginationData: {
    type: Object,
    default: () => {
      return 5
    }
  },
  // 表格的数据数量
  total: {
    type: Number,
    require: true
  },
  // 是否使用分页器
  usePagination: {
    type: Boolean,
    default: true
  },
  // 是否使用关凯
  useSwitch: {
    type: Boolean,
    default: false
  }
  // handleEdit: Function,
  // handleDelete: Function
})
const emits = defineEmits(['updateTableData', 'update:modelValue', 'update-table-data', 'update-selected-rows', 'updateSwitchState'])
// 实现 form表单v-model 逻辑
watch(
  () => props.formData,
  (newVal) => {
    emits('update:modelValue', newVal)
  },
  { deep: true }
)
const rows = ref()
// 获取table实例
const tableRef = ref()
// 清除选中行
function clearSelectedRows() {
  if (tableRef.value) {
    tableRef.value.clearSelection()
  }
}
const handleSelectionChange = (selectRows) => {
  rows.value = selectRows
  emits('update-selected-rows', selectRows)
}

// 套餐项目-表格绑定事件selectTc
const selectTc = (selection, row) => {
  // 当表格数据都没有被勾选的时候 就返回
  // 主要用于将当前勾选的表格状态清除
  if (selection.length == 0) return
  tableRef.value.toggleRowSelection(row, true)
  emits('update-selected-row', selection)
}
defineExpose({
  // 暴露选中的row
  rows,
  // 暴露清除选中项方法
  clearSelectedRows
})
const handleCurrentChange = (currentPage) => {
  // console.log(currentPage)
  console.log(props.paginationData.pageSize)
  emits('update-table-data', props.paginationData.pageSize, currentPage)
}
</script>

<style lang="scss" scoped></style>
