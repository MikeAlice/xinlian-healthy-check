<!-- 体检套餐 -->
<template>
  <el-container style="height: 100%">
    <!-- 侧边栏 -->
    <el-aside width="250px">
      <PeopleListCG style="height: 100%; width: 100%">
        <!-- 表单 -->
        <template #form>
          <el-form :model="form">
            <el-form-item>
              <el-radio-group v-model="radio">
                <el-radio :label="1" style="margin-right: 10px">职</el-radio>
                <el-radio :label="2" style="margin-right: 10px">健</el-radio>
                <el-radio :label="3" style="margin-right: 10px">从</el-radio>
                <el-radio :label="4" style="margin-right: 10px">放</el-radio>
              </el-radio-group>
            </el-form-item>
            <el-form-item prop="name">
              <el-input v-model="form.name" placeholder="请输入关键字" clearable />
            </el-form-item>
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
    <el-main>
      <div style="margin-bottom: 10px">
        <el-button type="primary">
          <el-icon style="margin-right: 5px"><CirclePlus /></el-icon>新增套餐
        </el-button>
        <el-button type="danger">
          <el-icon style="margin-right: 5px"><CircleCloseFilled /></el-icon>删除
        </el-button>
        <el-button type="primary">
          <el-icon style="margin-right: 5px"><CirclePlus /></el-icon>添加项目
        </el-button>
        <el-button type="primary">
          <el-icon style="margin-right: 5px"><Position /></el-icon>提交
        </el-button>
      </div>
      <BaseDataList
        ref="BaseDataRef"
        :use-form="useForm"
        :form-data="dataForm"
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
          <el-row>
            <el-col :span="8">
              <el-form-item label="套餐类别">
                <el-input v-model="dataForm.packageCategory" placeholder="请输入" readonly></el-input>
              </el-form-item>
            </el-col>
            <el-col :span="8">
              <el-form-item label="危害因素">
                <el-input v-model="dataForm.harmfulFactors" placeholder="请输入" readonly></el-input>
              </el-form-item>
            </el-col>
            <el-col :span="8">
              <el-form-item label="在岗状态">
                <el-input v-model="dataForm.dutyStatus" placeholder="请输入" readonly></el-input>
              </el-form-item>
            </el-col>
          </el-row>
          <el-row>
            <el-col :span="8">
              <el-form-item label="适合性别">
                <el-input v-model="dataForm.fitSex" placeholder="请输入" readonly></el-input>
              </el-form-item>
            </el-col>
            <el-col :span="8">
              <el-form-item label="套餐名称">
                <el-input v-model="dataForm.packageName" placeholder="请输入" readonly></el-input>
              </el-form-item>
            </el-col>
            <el-col :span="8">
              <el-form-item label="简拼">
                <el-input v-model="dataForm.simpleWord" placeholder="请输入" readonly></el-input>
              </el-form-item>
            </el-col>
          </el-row>
          <el-row>
            <el-col :span="12">
              <el-form-item label="职业病">
                <el-input v-model="dataForm.occupationalDiseases" type="textarea" placeholder="多条数据请以分号（“；”）结尾， 如中度贫血；多发性周围神经病；" readonly></el-input>
              </el-form-item>
            </el-col>
            <el-col :span="12">
              <el-form-item label="职业禁忌证">
                <el-input v-model="dataForm.professionalTaboos" :rows="5" type="textarea" placeholder="多条数据请以分号（“；”）结尾， 如中度贫血；多发性周围神经病；" readonly></el-input>
              </el-form-item>
            </el-col>
          </el-row>
          <el-row>
            <el-col :span="12">
              <el-form-item label="诊断标准">
                <el-input v-model="dataForm.diagnosticCriteria" :rows="5" type="textarea" placeholder="多条数据请以分号（“；”）结尾， 如中度贫血；多发性周围神经病；" readonly></el-input>
              </el-form-item>
            </el-col>
            <el-col :span="12">
              <el-form-item label="症状询问">
                <el-input v-model="dataForm.symptomInquiry" :rows="5" type="textarea" placeholder="多条数据请以分号（“；”）结尾， 如中度贫血；多发性周围神经病；" readonly></el-input>
              </el-form-item>
            </el-col>
          </el-row>
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
import { ArrowDown, Search, CirclePlus, DeleteFilled, View, Edit, ArrowRightBold, ArrowLeftBold, CircleCloseFilled, Position } from '@element-plus/icons-vue'
import BaseDataList from '@/components/basedatalist/BaseDataList.vue'
import PeopleListCG from '@/components/peoplelist/PeopleList-CG.vue'
import List from '@/components/peoplelist/List.vue'
import Head from '@/components/head/Head.vue'

/* PeopleListCG所用变量及方法 */
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
/* 本界面所用变量及方法 */
const radio = ref(1)
const isCollapsed = ref(false) // 是否收缩侧边栏
const useHint = ref(true)
const useForm = ref(true)
const usePagination = ref(true)
const BaseDataRef = ref()
const dialogVisible = ref(false)
const useFixed = ref(true)
const labelWidth = '125px'

// 表格列属性
const tableColumnAttribute = ref([
  { prop: 'id', label: '#', width: '120', align: 'center' },
  { prop: 'projectName', label: '名称', width: '120', align: 'center' },
  { prop: 'projectAbb', label: '简称', width: '120', align: 'center' },
  { prop: 'sellingPrice', label: '销售价（元）', width: '120', align: 'center' },
  { prop: 'discount', label: '折扣（%）', width: '120', align: 'center' },
  { prop: 'discountPrice', label: '折扣价（元）', width: '120', align: 'center' },
  { prop: 'address', label: '检查地址', width: '120', align: 'center' }
])
// 表格数据
const tableData = ref([
  {
    id: '--',
    projectName: '健康体检',
    projectAbb: '--',
    sellingPrice: '铁矿采选*',
    discount: '国有企业',
    discountPrice: '--',
    address: '--'
  }
])
// 搜索信息表单
const dataForm = reactive({
  packageCategory: '',
  harmfulFactors: '',
  dutyStatus: '',
  fitSex: '',
  packageName: '',
  simpleWord: '',
  occupationalDiseases: '',
  professionalTaboos: '',
  diagnosticCriteria: '',
  symptomInquiry: ''
})

// 查看
const handelLook = (row) => {
  console.log(row)
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
</style>
<style>
.el-form-item__label {
  font-weight: 700;
  margin-left: 20px;
}
</style>
