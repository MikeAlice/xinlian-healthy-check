<!--
 * @Author: setti5 2283356040@qq.com
 * @Date: 2024-01-30 15:48:01
 * @LastEditors: setti5 2283356040@qq.com
 * @LastEditTime: 2024-01-30 21:08:00
 * @FilePath: \zero-one-healthy-check\healthy-frontend\src\views\basicdata\SampleLibrary.vue
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
-->
<!-- 样本库 -->
<template>
  <div class="container">
    <BaseDataList
      ref="BaseDataRef"
      :use-form="useForm"
      :childrenData="childrenData"
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
      @update-selected-row="selectRow"
    >
      <!-- fixed固定列 -->
      <template #fixed="{ row }">
        <el-button type="primary" style="margin-right: 5px" @click="handelLook(row)">
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
              <el-dropdown-item @click.native="editLxk(row)">
                <el-icon><Edit></Edit></el-icon>
                修改
              </el-dropdown-item>
              <el-dropdown-item @click.native="delLxk">
                <el-icon><DeleteFilled></DeleteFilled></el-icon>
                删除
              </el-dropdown-item>
            </el-dropdown-menu>
          </template>
        </el-dropdown>
      </template>

      <!-- form表单区域 -->
      <template #form>
        <el-form-item label="类型名称">
          <el-input v-model="formData.SampleName"></el-input>
        </el-form-item>
        <el-form-item label="类型编码">
          <el-input v-model="formData.SampleCode"></el-input>
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
          <el-button type="primary" style="margin-right: 10px" @click="dialogVisible = true">
            <el-icon><Plus></Plus></el-icon>
            新增
          </el-button>
          <!-- 新增对话框区域 -->
          <el-dialog v-model="dialogVisible" title="新增" width="60%" :before-close="handleClose">
            <el-row data="rowData">
              <el-col :span="20">
                <el-form :model="basicForm" inline>
                  <el-form-item >
                    <el-input type="hidden" v-model="basicForm.id"  style="width: 232px" disabled=isDisabled></el-input>
                  </el-form-item>
                  <el-form-item label="类型名称" :label-width="labelWidth">
                    <el-input v-model="basicForm.lxmc" placeholder="请输入类型名称" style="width: 232px" disabled=isDisabled></el-input>
                  </el-form-item>
                  <el-form-item label="类型编码" :label-width="labelWidth">
                    <el-input v-model="basicForm.lxbm" placeholder="请输入类型编码" style="width: 232px" disabled=isDisabled></el-input>
                  </el-form-item>
                  <el-form-item label="上级类型" :label-width="labelWidth">
                    <el-select v-model="basicForm.sjlx" style="width: 232px" disabled=isDisabled></el-select>
                  </el-form-item>
                  <el-form-item label="排序" :label-width="labelWidth">
                    <el-input v-model="basicForm.px" default="0" style="width: 232px" disabled=isDisabled></el-input>
                  </el-form-item>
                  <el-form-item label="备注" :label-width="labelWidth">
                    <el-input type="textarea" v-model="basicForm.bz" style="width: 232px" placeholder="请输入备注" disabled=isDisabled></el-input>
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
                  <el-icon><Bottom></Bottom></el-icon>
                  导出本页数据
                </el-dropdown-item>
              </el-dropdown-menu>
            </template>
          </el-dropdown>
          <el-button @click="closeForm">关闭搜索</el-button>
          <el-button @click="closeHint">关闭提示</el-button>
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
  </div>
</template>

<script setup>
import { ref, reactive, onMounted } from 'vue'
import { ElMessage } from 'element-plus'
import { ArrowDown, Search, Plus, InfoFilled, Refresh, DeleteFilled, Bottom, View, Edit } from '@element-plus/icons-vue'
import BaseDataList from '@/components/basedatalist/BaseDataList.vue'

const isDisabled = ref(false)
const childrenData = ref(true)
const selectValue = ref('')
const useHint = ref(true)
const useForm = ref(true)
const usePagination = ref(true)
const BaseDataRef = ref()
const dialogVisible = ref(false)
const useFixed = ref(true)
const labelWidth = '125px'
// table列
const tableColumnAttribute = ref([
  { prop: 'lxmc', label: '类型名称', width: '360', align: 'center' },
  { prop: 'lxbm', label: '类型编码', width: '360', align: 'center' },
  { prop: 'px', label: '排序', width: '360', align: 'center' },
  { prop: 'bz', label: '备注', width: '360', align: 'center' }
])
// table数据
const tableData = ref([
  {
    id: 1,
    lxmc: '经济类型',
    lxbm: 'TYPE_002',
    px: '2',
    bz: '--',
    children: [
      {
        id: 11,
        lxmc: '内资企业',
        lxbm: '100',
        px: '--',
        bz: '--'
      },
      {
        id: 12,
        lxmc: '港,澳,台商投资企业',
        lxbm: '200',
        px: '--',
        bz: '--'
      },
      {
        id: 13,
        lxmc: '外资投商投资企业',
        lxbm: '300',
        px: '--',
        bz: '--'
      }
    ]
  },
  {
    id: 2,
    lxmc: '职业危害因素类型',
    lxbm: 'TYPE_001',
    px: '1',
    bz: '--'
  },
  {
    id: 3,
    lxmc: '行业类别',
    lxbm: 'TYPE_003',
    px: '3',
    bz: '--'
  }
])
function handelLook(row) {

   for(const key in row){
    basicForm[key] = row[key]
   }
   isDisabled.value = true
   dialogVisible.value = true
}

//修改单条数据
function editLxk(row) {

for(const key in row){
 basicForm[key] = row[key]
}
isDisabled.value = false
dialogVisible.value = true
}

const formData = reactive({
  SampleName: '',
  SampleCode: '',
  contactPerson: '',
  contactPhone: ''
})
// 基础信息表单
const basicForm = reactive({
  id:'',
  lxmc: '',
  lxbm: '',
  sjlx: '',
  px: '',
  bz: ''
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
  ;(formData.SampleName = ''), (formData.SampleCode = ''), (formData.contactPerson = ''), (formData.contactPhone = '')
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
  padding: 16px;
}
.operation {
  margin-bottom: 10px;
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
