<!--
 * @Author: setti5 2283356040@qq.com
 * @Date: 2024-01-30 15:48:01
 * @LastEditors: setti5 2283356040@qq.com
 * @LastEditTime: 2024-02-05 14:53:58
 * @FilePath: \zero-one-healthy-check\healthy-frontend\src\views\basicdata\SampleLibrary.vue
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
-->
<!-- 样本库 -->
<template>
  <div class="container">
    <BaseDataList
      ref="BaseDataRef"
      :use-form="useForm"
      :form-data="formData"
      :table-data="tableData"
      :table-column-attribute="tableColumnAttribute"
      :total="total"
      :use-pagination="usePagination"
      :pagination-data="paginationData"
      :handle-edit="handleEdit"
      :use-fixed="useFixed"
      @update-table-data="handlePageChange"
      @update-selected-rows="selectRows"
    >
      <!-- fixed固定列 -->
      <template #fixed="{ row }">
        <!-- <el-button type="primary" style="margin-right: 5px" @click="handelLook(row)"> -->
        <el-button type="primary" style="margin-right: 5px" @click="onCheckDialog">
          <el-icon><View></View></el-icon>
          查看
        </el-button>
        <el-dropdown>
          <el-button>
            更多操作
            <el-icon class="el-icon--right">
              <arrow-down />
            </el-icon>
          </el-button>

          <template #dropdown>
            <el-dropdown-menu>
              <el-dropdown-item @click="onEditDialog">
                <el-icon><Edit></Edit></el-icon>
                修改
              </el-dropdown-item>
              <el-dropdown-item>
                <el-icon><DeleteFilled></DeleteFilled></el-icon>
                删除
              </el-dropdown-item>
            </el-dropdown-menu>
          </template>
        </el-dropdown>
      </template>

      <!-- form搜索表单区域 -->
      <template #form>
        <el-form-item label="名称">
          <el-input v-model="formData.sampleName"></el-input>
        </el-form-item>
        <el-form-item label="标本代码">
          <el-input v-model="formData.sampleCode"></el-input>
        </el-form-item>
        <el-form-item label="关联码">
          <el-input v-model="formData.contactPerson"></el-input>
        </el-form-item>
        <el-form-item>
          <el-button type="primary">
            <el-icon><Search></Search></el-icon>
            搜索
          </el-button>
        </el-form-item>
        <el-form-item>
          <el-button @click="resetForm">重置</el-button>
        </el-form-item>
      </template>

      <!-- operation功能区域 -->
      <template #operation>
        <div class="operation">
          <!-- <el-button type="primary" style="margin-right: 10px" @click="dialogVisible = true"> -->
          <el-button type="primary" style="margin-right: 10px" @click="onAddDialog">
            <el-icon><Plus></Plus></el-icon>
            新增
          </el-button>

          <el-dropdown>
            <el-button style="margin-right: 8px">
              更多操作
              <el-icon class="el-icon--right"> <arrow-down /> </el-icon
            ></el-button>
            <template #dropdown>
              <el-dropdown-menu>
                <el-dropdown-item>
                  <el-icon><Refresh></Refresh></el-icon>
                  刷新
                </el-dropdown-item>
                <el-dropdown-item>
                  <el-icon><DeleteFilled></DeleteFilled></el-icon>
                  批量删除
                </el-dropdown-item>
                <el-dropdown-item>
                  <el-icon><Bottom></Bottom></el-icon>
                  导出本页数据
                </el-dropdown-item>
              </el-dropdown-menu>
            </template>
          </el-dropdown>
          <el-button @click="closeForm">关闭搜索</el-button>
          <el-button @click="closeHint">关闭提示</el-button>
          <el-dropdown style="position: absolute; right: 8px">
            <el-button @click="dynamicList"
              ><el-icon><Operation /></el-icon
            ></el-button>
            <template #dropdown>
              <el-dropdown-menu>
                <el-dropdown-item> 动态列 </el-dropdown-item>
                <el-dropdown-item divided><input type="checkbox" />名称</el-dropdown-item>
                <el-dropdown-item><input type="checkbox" />条码份数</el-dropdown-item>
                <el-dropdown-item><input type="checkbox" />规格</el-dropdown-item>
                <el-dropdown-item><input type="checkbox" />是否采血</el-dropdown-item>
                <el-dropdown-item><input type="checkbox" />标本代码</el-dropdown-item>
                <el-dropdown-item><input type="checkbox" />排序</el-dropdown-item>
                <el-dropdown-item><input type="checkbox" />是否打印</el-dropdown-item>
                <el-dropdown-item><input type="checkbox" />关联码</el-dropdown-item>
                <el-dropdown-item><input type="checkbox" />容量</el-dropdown-item>
              </el-dropdown-menu>
            </template>
          </el-dropdown>
        </div>
      </template>

      <!-- 多选清除栏 -->
      <template #hint>
        <div v-if="useHint" class="hint">
          <span>
            <el-icon style="color: blue"><InfoFilled></InfoFilled></el-icon>
            已选择{{ selectedTotal }}项
          </span>
          <el-button type="primary" link style="margin-bottom: 3px" @click="clearRows">清空</el-button>
        </div>
      </template>
    </BaseDataList>

    <SampleLibraryDialog ref="openDialogFormRef" :title="title" :handle-submit="handleSubmit"></SampleLibraryDialog>
  </div>
</template>

<script setup>
import { ref, reactive, onMounted } from 'vue'
import { ArrowDown, Search, Plus, InfoFilled, Refresh, DeleteFilled, Bottom, View, Edit, Operation } from '@element-plus/icons-vue'
import BaseDataList from '@/components/basedatalist/BaseDataList.vue'
import SampleLibraryDialog from './SampleLibrary/SampleLibraryDialog.vue'
import { ElMessage } from 'element-plus'

// 弹出对话框相关逻辑
const openDialogFormRef = ref(null)
const title = ref('')
const onAddDialog = () => {
  // openDialogFormRef.value.open([])
  title.value = '新增'
  openDialogFormRef.value.dialogVisible = true
}
const onCheckDialog = () => {
  // openDialogFormRef.value.open(row)
  title.value = '查看'
  openDialogFormRef.value.dialogVisible = true
}
const onEditDialog = () => {
  // openDialogFormRef.value.open(row)
  title.value = '修改'
  openDialogFormRef.value.dialogVisible = true
}

function handelLook(row) {
  console.log(row)
}

const selectValue = ref('')
const useHint = ref(true)
const useForm = ref(true)
const usePagination = ref(true)
const BaseDataRef = ref()
const useFixed = ref(true)

// table列
const tableColumnAttribute = ref([
  { prop: 'sampleName', label: '名称', width: '200', align: 'center' },
  { prop: 'barcodeCopies', label: '条码份数', width: '120', align: 'center' },
  { prop: 'sampleStandards', label: '规格', width: '120', align: 'center' },
  { prop: 'isBloodSampling', label: '是否采血', width: '120', align: 'center' },
  { prop: 'sampleCode', label: '标本代码', width: '120', align: 'center' },
  { prop: 'rank', label: '排序', width: '120', align: 'center' },
  { prop: 'isPrint', label: '是否打印', width: '120', align: 'center' },
  { prop: 'associationCode', label: '关联码', width: '120', align: 'center' },
  { prop: 'capacity', label: '容量', width: '120', align: 'center' }
])
// table数据
const tableData = ref([
  {
    sampleName: '心电图',
    barcodeCopies: '1',
    sampleStandards: '留底',
    isBloodSampling: '1',
    sampleCode: '11',
    rank: '1',
    isPrint: '1',
    associationCode: '411',
    capacity: '--'
  },
  {
    sampleName: '基因-话甘宁',
    barcodeCopies: '1',
    sampleStandards: '留底',
    isBloodSampling: '0',
    sampleCode: '23',
    rank: '0',
    isPrint: '1',
    associationCode: '143',
    capacity: '--'
  },
  {
    sampleName: '驾驶员体检',
    barcodeCopies: '3',
    sampleStandards: ' ',
    isBloodSampling: '1',
    sampleCode: '02',
    rank: '15',
    isPrint: '1',
    associationCode: '155',
    capacity: '--'
  },
  {
    sampleName: '一般检查',
    barcodeCopies: '4',
    sampleStandards: '黄管',
    isBloodSampling: '0',
    sampleCode: ' ',
    rank: '23',
    isPrint: '1',
    associationCode: '244',
    capacity: '--'
  },
  {
    sampleName: '肠镜',
    barcodeCopies: '1',
    sampleStandards: ' ',
    isBloodSampling: '1',
    sampleCode: '13',
    rank: '24',
    isPrint: '1',
    associationCode: '163',
    capacity: '--'
  },
  {
    sampleName: '乐山市峨边盛和矿业',
    barcodeCopies: '--',
    sampleStandards: '健康体检',
    isBloodSampling: '1',
    sampleCode: ' ',
    rank: '2',
    isPrint: '1',
    associationCode: '155',
    capacity: '--'
  },
  {
    sampleName: '乐山市峨边盛和矿业',
    barcodeCopies: '--',
    sampleStandards: '健康体检',
    isBloodSampling: '1',
    sampleCode: '44',
    rank: '国有企业',
    isPrint: '1',
    associationCode: '144',
    capacity: '--'
  }
])

// 表格之上的搜索区域表单
const formData = reactive({
  sampleName: '',
  sampleCode: '',
  contactPerson: ''
})

const closeForm = () => {
  useForm.value = !useForm.value
}
const closeHint = () => {
  useHint.value = !useHint.value
}
// 编辑功能
const handleEdit = (row) => {
  console.log(row)
}

const handleSubmit = () => {
  openDialogFormRef.value.basicFormRef.validate((valid) => {
    if (valid) {
      const params = {
        ...openDialogFormRef.value.basicForm
      }
      params.dialogVisible = params.dialogVisible ? 1 : 0
      if (title.value === '新增') {
        ElMessage({
          message: '添加成功',
          type: 'success'
        })
      } else {
        ElMessage({
          message: '修改成功',
          type: 'success'
        })
      }

      openDialogFormRef.value.dialogVisible = false
    }
  })
}

// 显示选中几项
const selectedTotal = ref(0)
// 选中的row
const selectRows = (selectRows) => {
  selectedTotal.value = selectRows.length
  // console.log(selectRows)
  console.log(BaseDataRef.value.rows)
}
// 清空选中行的方法
const clearRows = () => {
  // 调用子组件的 clearSelectedRows 方法
  BaseDataRef.value.clearSelectedRows()
}
// 重置表单方法
const resetForm = () => {
  ;(formData.sampleName = ''), (formData.sampleStandards = ''), (formData.contactPerson = ''), (formData.contactPhone = '')
}
const total = tableData.value.length
// 分页参数
const paginationData = ref({
  currentPage: 1,
  pageSize: 5
})
const currentTableData = ref()
// 根据分页参数计算当前显示的数据
function getPagedData(pageSize, currentPage) {
  const start = (currentPage - 1) * pageSize
  const end = start + pageSize
  const tables = []
  for (let i = start; i < end; i++) {
    if (tableData.value[i]) tables.push(tableData.value[i])
  }

  return (currentTableData.value = tables)
}
// 更新分页数据
function handlePageChange(pageSize, currentPage) {
  paginationData.value.pageSize = pageSize
  paginationData.value.currentPage = currentPage
  tableData.value = getPagedData(pageSize, currentPage)
}
onMounted(() => {
  handlePageChange(paginationData.value.pageSize, paginationData.value.currentPage)
})
</script>

<style lang="scss" scoped>
.container {
  width: 100%;
  height: 100%;
}
.operation {
  margin-bottom: 10px;
  display: flex;
}
.hint {
  height: 33px;
  line-height: 33px;
  background-color: rgb(242, 250, 254);
  border: 1px solid rgb(193, 226, 252);
  border-radius: 5px;
  margin-bottom: 10px;
}
.avatar-uploader .avatar {
  width: 178px;
  height: 178px;
  display: block;
}
.avatar-uploader .el-upload {
  border: 1px dashed var(--el-border-color);
  border-radius: 6px;
  cursor: pointer;
  position: relative;
  overflow: hidden;
  transition: var(--el-transition-duration-fast);
}

.avatar-uploader .el-upload:hover {
  border-color: var(--el-color-primary);
}

.el-icon.avatar-uploader-icon {
  font-size: 28px;
  color: #8c939d;
  width: 178px;
  height: 178px;
  text-align: center;
}
</style>
