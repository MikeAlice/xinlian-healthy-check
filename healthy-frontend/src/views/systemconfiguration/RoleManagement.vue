<template>
  <div class="contain">
    <!-- 添加角色dialog -->
    <el-dialog v-model="dialogVisible" title="添加角色" width="40%" :before-close="handleClose">
      <el-row>
        <el-col :span="20">
          <el-form :model="basicForm">
            <el-form-item label="角色名称" :label-width="labelWidth">
              <el-input v-model="basicForm.title" placeholder="请输入"></el-input>
            </el-form-item>
            <el-form-item label="备注" :label-width="labelWidth">
              <el-input v-model="basicForm.title" placeholder="请输入"></el-input>
            </el-form-item>
          </el-form>
        </el-col>
      </el-row>
      <template #footer>
        <span class="dialog-footer">
          <el-button @click="dialogVisible = false">取消</el-button>
          <el-button type="primary" @click="dialogVisible = false">提交</el-button>
        </span>
      </template>
    </el-dialog>
    <!-- 编辑角色dialog -->
    <el-dialog v-model="editVisiable" title="编辑角色" width="40%" :before-close="handleClose">
      <el-row>
        <el-col :span="20">
          <el-form :model="basicForm">
            <el-form-item label="角色名称" :label-width="labelWidth">
              <el-input v-model="basicForm.title" placeholder="请输入"></el-input>
            </el-form-item>
            <el-form-item label="备注" :label-width="labelWidth">
              <el-input v-model="basicForm.title" placeholder="请输入"></el-input>
            </el-form-item>
          </el-form>
        </el-col>
      </el-row>
      <template #footer>
        <span class="dialog-footer">
          <el-button @click="editVisiable = false">取消</el-button>
          <el-button type="primary" @click="editVisiable = false">提交</el-button>
        </span>
      </template>
    </el-dialog>

    <BaseDataList ref="BaseDataRef" :use-form="useForm" :form-data="formData" :table-data="tableData"
      :table-column-attribute="tableColumnAttribute" :total="total" :use-pagination="usePagination"
      :pagination-data="paginationData" :handle-edit="handleEdit" :use-fixed="useFixed"
      @update-table-data="handlePageChange" @update-selected-rows="selectRows">
      <!-- fixed固定列 -->
      <!-- 表格后面的操作选项群 -->
      <template #fixed="{ row }">

        <el-button type="primary" style="margin-right: 5px" @click="handleEditDialog(row)">编辑</el-button>
        <el-dropdown>
          <el-button style="margin-right: 8px">
            更多操作
            <el-icon class="el-icon--right"> <arrow-down /> </el-icon></el-button>
          <template #dropdown>
            <el-dropdown-menu>
              <el-dropdown-item>菜单权限</el-dropdown-item>
              <el-dropdown-item>收合所有</el-dropdown-item>
              <el-dropdown-item>仅展开一级</el-dropdown-item>
              <el-dropdown-item>删除</el-dropdown-item>
            </el-dropdown-menu>
          </template>
        </el-dropdown>
      </template>

      <!-- form表单区域 -->
      <template #form>
        <el-form-item>
          <el-input v-model="input2" style="width: 400px" placeholder="请输入关键词搜索" :suffix-icon="Search" />
        </el-form-item>
        <el-form-item>
          <el-button type="primary">
            <el-icon>
              <Search></Search>
            </el-icon>
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
          <el-button :icon="Plus" type="primary" @click="dialogVisible = true">添加角色</el-button>
          <el-button :icon="Delete" type="danger" @click="open">批量删除</el-button>
          <el-button :icon="Refresh" type="primary">刷新</el-button>

          <el-button @click="closeForm">关闭搜索</el-button>
          <el-button @click="closeHint">关闭提示</el-button>
        </div>
      </template>

      <!-- 多选清除栏 -->
      <template #hint>
        <div v-if="useHint" class="hint">
          <span>
            <el-icon style="color: blue">
              <InfoFilled></InfoFilled>
            </el-icon>
            已选择{{ selectedTotal }}项
          </span>
          <el-button type="primary" link style="margin-bottom: 3px" @click="clearRows">清空</el-button>
        </div>
      </template>
    </BaseDataList>
  </div>
</template>

<script setup>
import { ref, reactive, onMounted } from 'vue'
import { ElMessage } from 'element-plus'
import { ArrowUp, Delete, Plus, ArrowDown, Search, InfoFilled, Refresh, DeleteFilled, Bottom, View, Edit } from '@element-plus/icons-vue'
import BaseDataList from '@/components/basedatalist/BaseDataList.vue'
import CheckItems from '@/components/checkItems/CheckItems.vue'

const useHint = ref(true)
const useForm = ref(true)
const usePagination = ref(true)
const BaseDataRef = ref()
const dialogVisible = ref(false)
const useFixed = ref(true)
const labelWidth = '125px'
// table列
const tableColumnAttribute = ref([
  { prop: 'title', label: '消息标题' },
  { prop: 'content', label: '消息内容' },
  { prop: 'type', label: '消息类型' },
  { prop: 'push', label: '新创建账号推送' },
  { prop: 'range', label: '发送范围' },
  { prop: 'date', label: '创建时间' }
])
// table数据
const tableData = ref([
  {
    title: 'test title',
    content: 'test content',
    type: 'one',
    push: 'yes',
    range: 'test1',
    date: '2233-12-2'
  },
  {
    title: 'test title',
    content: 'test content',
    type: 'one',
    push: 'yes',
    date: '2233-12-2'
  }
])
function handelLook(row) {
  console.log(row)
}

function handleCancel(row) {
  console.log(row)
  open()
}
function handleEditDialog(row) {
  console.log(row)
  openEditDialog()
}
const editVisiable = ref(false)
function openEditDialog() {
  editVisiable.value = true
}
const formData = reactive({
  title: '',
  content: '',
  type: ''
})

// 点击展开按钮按钮的折叠逻辑
const isShowInput = ref(false)
const toggleCollapse = () => {
  isShowInput.value = !isShowInput.value
}

// 新增消息
// 基础信息表单
const basicForm = ref({
  title: '',
  content: '',
  push: false,
  range: '1',
  type: ''
})

const style = ref('hide')
function showPeople() {
  style.value = 'show'
}
function hidePeople() {
  style.value = 'hide'
}

const peopleNum = ref(0)

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
  BaseDataRef.value.clearForm()
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

const open = () => {
  // eslint-disable-next-line no-undef
  ElMessageBox.confirm(
    '你确定删除吗',
    '提示',
    {
      confirmButtonText: '确定',
      cancelButtonText: '取消',
      type: 'warning'
    }
  )
    .then(() => {
      ElMessage({
        type: 'success',
        message: '删除成功'
      })
    })
    .catch(() => {
      ElMessage({
        type: 'info',
        message: '取消删除'
      })
    })
}
</script>

<style lang="scss" scoped>
.expend {
  display: isShowInput;
}

.operation {
  margin-bottom: 10px;
}

.hide {
  display: none;
}

.show {
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
