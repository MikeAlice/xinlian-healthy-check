<!-- 组合项目 -->
<template>
  <el-container>
    <!-- 侧边栏 -->
    <el-aside :width="leftWidth" style="margin-left: 10px">
      <div v-if="leftVisible" class="left">
        <div class="choice">
          <el-icon style="color: rgb(45, 140, 240)"><InfoFilled></InfoFilled></el-icon>
          <span> 当前选择:</span>
        </div>
        <div class="search">
          <el-input v-model="searchInput" placeholder="输入搜索科室" style="width: 100%"> </el-input>
        </div>
        <el-scrollbar height="630px">
          <div class="department">
            <ul class="departmentUl">
              <li v-for="item in departmentArr" :key="item" class="departmentLi">
                <span class="departmentItem">{{ item.name }}</span>
              </li>
            </ul>
          </div>
        </el-scrollbar>
      </div>
    </el-aside>
    <div class="expend" style="margin-right: 10px">
      <i>
        <el-icon v-if="leftGo" @click="collectLeft"><ArrowLeftBold></ArrowLeftBold></el-icon>
      </i>
      <i>
        <el-icon v-if="leftBack" @click="returnLeft"><ArrowRightBold></ArrowRightBold></el-icon>
      </i>
    </div>
    <el-main>
      <BaseDataList
        ref="BaseDataRef"
        :use-form="useForm"
        :form-data="searchForm"
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
        <!-- 搜索表单区域 -->
        <template #form>
          <el-form-item label="名称">
            <el-input v-model="searchForm.projectName" placeholder="请输入名称"></el-input>
          </el-form-item>
          <el-form-item label="简称">
            <el-input v-model="searchForm.projectCode" placeholder="请输入简称"></el-input>
          </el-form-item>
          <el-form-item>
            <el-button type="primary">
              <el-icon style="margin-right: 5px"><Search></Search></el-icon>
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
              <el-icon style="margin-right: 5px"><Plus></Plus></el-icon>
              新增
            </el-button>
            <!-- 新增对话框区域 -->
            <el-dialog v-model="dialogVisible" title="新增" width="60%" :before-close="handleClose">
              <el-row>
                <el-col :span="20">
                  <el-form :model="addForm" inline>
                    <el-form-item label="所属科室" :label-width="labelWidth">
                      <el-select v-model="addForm.department" placeholder="请选择" style="width: 232px" clearable>
                        <el-option label="测试单位" value="测试单位" />
                      </el-select>
                    </el-form-item>
                    <el-form-item label="项目代码" :label-width="labelWidth">
                      <el-input v-model="addForm.projectCode" style="width: 232px" placeholder="请输入项目代码"></el-input>
                    </el-form-item>
                    <el-form-item label="项目名称" :label-width="labelWidth">
                      <el-input v-model="addForm.projectName" style="width: 232px" placeholder="请输入项目名称"></el-input>
                    </el-form-item>
                    <el-form-item label="项目简称" :label-width="labelWidth">
                      <el-input v-model="addForm.projectAbb" style="width: 232px" placeholder="请输入项目简称"></el-input>
                    </el-form-item>
                    <el-form-item label="排序" :label-width="labelWidth">
                      <el-input v-model="addForm.sort" style="width: 232px" placeholder="请输入排序序号"></el-input>
                    </el-form-item>
                    <el-form-item label="结果类型" :label-width="labelWidth">
                      <el-select v-model="addForm.resultType" style="width: 232px" placeholder="请选择">
                        <el-option label="测试单位" value="测试单位" />
                      </el-select>
                    </el-form-item>
                    <el-form-item label="项目单位" :label-width="labelWidth">
                      <el-select v-model="addForm.projectUnit" style="width: 232px" placeholder="请选择">
                        <el-option label="测试单位" value="测试单位" />
                      </el-select>
                    </el-form-item>
                    <el-form-item label="默认值" :label-width="labelWidth">
                      <el-input v-model="addForm.defaultValue" style="width: 232px" placeholder="请输入默认值"></el-input>
                    </el-form-item>
                    <el-form-item label="进入小结" :label-width="labelWidth">
                      <el-select v-model="addForm.summary" style="width: 232px" placeholder="请选择">
                        <el-option label="测试单位" value="测试单位" />
                      </el-select>
                    </el-form-item>
                    <el-form-item label="进入报告" :label-width="labelWidth">
                      <el-select v-model="addForm.report" style="width: 232px" placeholder="请选择">
                        <el-option label="测试单位" value="测试单位" />
                      </el-select>
                    </el-form-item>
                    <el-form-item label="LIS关联码" :label-width="labelWidth">
                      <el-input v-model="addForm.lis" style="width: 232px" placeholder="请输入LIS关联码"></el-input>
                    </el-form-item>
                  </el-form>
                </el-col>
              </el-row>
              <!-- 对话框脚部 -->
              <template #footer>
                <span class="dialog-footer">
                  <el-button @click="dialogVisible = false">取消</el-button>
                  <el-button type="primary" @click="dialogVisible = false">提交</el-button>
                </span>
              </template>
            </el-dialog>
            <!-- 更多操作下拉框 -->
            <el-dropdown>
              <el-button style="margin-right: 8px">
                更多操作
                <el-icon class="el-icon--right" style="margin-right: 5px"> <arrow-down /> </el-icon
              ></el-button>
              <template #dropdown>
                <el-dropdown-menu>
                  <el-dropdown-item>
                    <el-icon style="margin-right: 5px"><Refresh></Refresh></el-icon>
                    刷新
                  </el-dropdown-item>
                  <el-dropdown-item>
                    <el-icon style="margin-right: 5px"><DeleteFilled></DeleteFilled></el-icon>
                    批量删除
                  </el-dropdown-item>
                  <el-dropdown-item>
                    <el-icon style="margin-right: 5px"><Bottom></Bottom></el-icon>
                    导出本页数据
                  </el-dropdown-item>
                </el-dropdown-menu>
              </template>
            </el-dropdown>
            <el-button @click="closeForm">{{ closeSearch }}</el-button>
            <el-button @click="closeHint">{{ closeTips }}</el-button>
          </div>
        </template>

        <!-- 多选清除栏 -->
        <template #hint>
          <div v-if="useHint" class="hint">
            <span>
              <el-icon style="color: blue; margin-right: 5px"><InfoFilled></InfoFilled></el-icon>
              已选择{{ selectedTotal }}项
            </span>
            <el-button type="primary" link style="margin-bottom: 3px" @click="clearRows">清空</el-button>
          </div>
        </template>

        <!-- 数据列表固定列 -->
        <template #fixed="{ row }">
          <el-button type="primary" style="margin-right: 5px" @click="handelLook(row)">
            <el-icon style="margin-right: 5px"><View></View></el-icon>
            查看
          </el-button>
          <el-dropdown>
            <el-button>
              更多操作
              <el-icon class="el-icon--right" style="margin-right: 5px">
                <arrow-down />
              </el-icon>
            </el-button>
            <template #dropdown>
              <el-dropdown-menu>
                <el-dropdown-item>
                  <el-icon style="margin-right: 5px"><Edit></Edit></el-icon>
                  修改
                </el-dropdown-item>
                <el-dropdown-item>
                  <el-icon style="margin-right: 5px"><DeleteFilled></DeleteFilled></el-icon>
                  删除
                </el-dropdown-item>
              </el-dropdown-menu>
            </template>
          </el-dropdown>
        </template>
      </BaseDataList>
    </el-main>
  </el-container>
</template>

<script setup>
import { ref, reactive, onMounted } from 'vue'
import { ElMessage } from 'element-plus'
import { ArrowDown, Search, Plus, InfoFilled, Refresh, DeleteFilled, Bottom, View, Edit, Setting, ArrowRightBold, ArrowLeftBold } from '@element-plus/icons-vue'
import BaseDataList from '@/components/basedatalist/BaseDataList.vue'
import PeopleList from '@/components/peoplelist/PeopleList.vue'

const isCollapsed = ref(false) // 是否收缩侧边栏
const useHint = ref(true)
const useForm = ref(true)
const usePagination = ref(true)
const BaseDataRef = ref()
const dialogVisible = ref(false)
const useFixed = ref(true)
const labelWidth = '125px'

/* 左侧侧边栏 */
// 控制箭头方向
const leftGo = ref(true)
const leftBack = ref(false)
// 控制左部显隐
const leftVisible = ref(true)
// 动态控制左部宽度
const leftWidth = ref('150px')
// 收起左部
const collectLeft = () => {
  leftWidth.value = '0'
  leftGo.value = false
  leftBack.value = true
}
// 展开左部
const returnLeft = () => {
  leftWidth.value = '150px'
  leftGo.value = true
  leftBack.value = false
}
// 表格列属性
const tableColumnAttribute = ref([
  { prop: 'projectName', label: '名称', width: '120', align: 'center' },
  { prop: 'projectAbb', label: '简称', width: '120', align: 'center' },
  { prop: 'sort', label: '排序', width: '120', align: 'center' },
  { prop: 'sellingPrice', label: '销售价（元）', width: '120', align: 'center' },
  { prop: 'costPrice', label: '成本价（元）', width: '120', align: 'center' },
  { prop: 'department', label: '科室名称', width: '120', align: 'center' },
  { prop: 'address', label: '检查地址', width: '120', align: 'center' }
])
// 表格数据
const tableData = ref([
  {
    projectName: '--',
    projectAbb: '健康体检',
    sort: '--',
    sellingPrice: '铁矿采选*',
    costPrice: '国有企业',
    department: '--',
    address: '--'
  }
])
// 搜索信息表单
const searchForm = reactive({
  projectName: '',
  projectCode: ''
})

// 查看
const handelLook = (row) => {
  console.log(row)
}
// 基础信息表单
const addForm = reactive({
  department: '',
  projectCode: '',
  projectName: '',
  projectAbb: '',
  sort: '',
  resultType: '',
  projectUnit: '',
  defaultValue: '',
  summary: '',
  report: '',
  lis: ''
})
// 关闭搜索及关闭提示
const closeSearch = ref('关闭搜索')
const closeTips = ref('关闭提示')
const closeForm = () => {
  useForm.value = !useForm.value
  if (useForm.value) {
    closeSearch.value = '关闭搜索'
  } else {
    closeSearch.value = '开启搜索'
  }
}
const closeHint = () => {
  useHint.value = !useHint.value
  if (useHint.value) {
    closeTips.value = '关闭提示'
  } else {
    closeTips.value = '开启提示'
  }
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
  searchForm.projectName = ''
  searchForm.projectCode = ''
}

// 数据总条数
const total = tableData.value.length
// 分页参数
const paginationData = ref({
  currentPage: 1,
  pageSize: 5
})
// 当前页数据
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
.shrink-button {
  display: flex;
  align-items: center;
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
// 左侧侧边栏
.left {
  width: 150px;
}
.choice {
  margin-top: 15px;
  height: 40px;
  line-height: 40px;
  border: 1px solid rgb(171, 220, 255);
  border-radius: 5px;
  background-color: rgb(240, 250, 255);
}

.search {
  margin-top: 10px;
}
.departmentUl {
  padding-left: 10px;
  list-style-type: none;
  color: rgb(97, 98, 110);
}

.departmentLi {
  margin-top: 10px;
}

.departmentItem {
  cursor: pointer;
}
.departmentItem:hover {
  background-color: rgb(234, 244, 254);
}

.expend {
  padding-top: 363px;
  cursor: pointer;
}
</style>
<style>
.el-form-item__label {
  font-weight: 700;
  margin-left: 20px;
}
</style>
