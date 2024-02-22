<!-- 团检单位 -->
<template>
  <div class="contain">
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
              <el-dropdown-item>
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

      <!-- form表单区域 -->
      <template #form>
        <el-form-item label="单位名称">
          <el-input v-model="formData.unitName"></el-input>
        </el-form-item>
        <el-form-item label="信用代码">
          <el-input v-model="formData.creditCode"></el-input>
        </el-form-item>
        <el-form-item label="联系人">
          <el-input v-model="formData.contactPerson"></el-input>
        </el-form-item>
        <el-form-item label="联系电话">
          <el-input v-model="formData.contactPhone" :style="{ width: '140px' }"></el-input>
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
            <!-- 标签页区域 -->
            <el-tabs v-model="activeName" type="card" class="demo-tabs" @tab-click="handleClick">
              <!-- 基础信息 -->
              <el-tab-pane label="基础信息" name="first">
                <el-row>
                  <el-col :span="20">
                    <el-form :model="basicForm" inline>
                      <el-form-item label="单位名称" :label-width="labelWidth">
                        <el-input v-model="basicForm.unitName" style="width: 232px"></el-input>
                      </el-form-item>
                      <el-form-item label="体检类型" :label-width="labelWidth">
                        <el-select v-model="basicForm.examinationType" style="width: 232px"></el-select>
                      </el-form-item>
                      <el-form-item label="统一社会信用代码" :label-width="labelWidth">
                        <el-input v-model="basicForm.creditCode" style="width: 232px"></el-input>
                      </el-form-item>
                      <el-form-item label="行业类型" :label-width="labelWidth">
                        <el-select v-model="basicForm.workType" style="width: 232px"></el-select>
                      </el-form-item>
                      <el-form-item label="所属地区" :label-width="labelWidth">
                        <el-select v-model="basicForm.region" style="width: 232px"></el-select>
                      </el-form-item>
                      <el-form-item label="经济类型" :label-width="labelWidth">
                        <el-select v-model="basicForm.ecoType" style="width: 232px"></el-select>
                      </el-form-item>
                      <el-form-item label="单位注册地址" :label-width="labelWidth">
                        <el-input v-model="basicForm.location" style="width: 232px"></el-input>
                      </el-form-item>
                      <el-form-item label="企业规模" :label-width="labelWidth">
                        <el-select v-model="basicForm.scale" style="width: 232px"></el-select>
                      </el-form-item>
                      <el-form-item label="职工人数" :label-width="labelWidth">
                        <el-input v-model="basicForm.number" style="width: 232px"></el-input>
                      </el-form-item>
                      <el-form-item label="接触职业病危害因素人数" :label-width="labelWidth">
                        <el-input v-model="basicForm.dangerousNum" style="width: 232px"></el-input>
                      </el-form-item>
                    </el-form>
                  </el-col>
                  <el-col :span="4">
                    <!-- 上传图片 -->
                    <el-upload
                      class="avatar-uploader"
                      action="https://run.mocky.io/v3/9d059bf9-4660-45f2-925d-ce80ad6c4d15"
                      :show-file-list="false"
                      :on-success="handleAvatarSuccess"
                      :before-upload="beforeAvatarUpload"
                    >
                      <img v-if="imageUrl" :src="imageUrl" class="avatar" />
                      <el-icon v-else class="avatar-uploader-icon"><Plus /></el-icon>
                    </el-upload>
                  </el-col>
                </el-row>
                <el-form :model="contactForm" inline>
                  <el-form-item label="体检联系人姓名" :label-width="130">
                    <el-input v-model="contactForm.people" style="width: 260px"></el-input>
                  </el-form-item>
                  <el-form-item label="体检联系人电话" :label-width="130">
                    <el-input v-model="contactForm.phone" style="width: 260px"></el-input>
                  </el-form-item>
                </el-form>
              </el-tab-pane>
              <!-- 其他信息 -->
              <el-tab-pane label="其他信息" name="second">
                <el-form :model="elseInfoForm" inline>
                  <el-form-item label="法人姓名" :label-width="labelWidth">
                    <el-input v-model="elseInfoForm.frName" style="width: 250px"></el-input>
                  </el-form-item>
                  <el-form-item label="法人电话" :label-width="labelWidth">
                    <el-input v-model="elseInfoForm.frPhone" style="width: 250px"></el-input>
                  </el-form-item>
                  <el-form-item label="生产工人数" :label-width="labelWidth">
                    <el-input v-model="elseInfoForm.scgNum" style="width: 250px"></el-input>
                  </el-form-item>
                  <el-form-item label="接触职业病危害因素女工人数" :label-width="labelWidth">
                    <el-input v-model="elseInfoForm.nvNum" style="width: 250px"></el-input>
                  </el-form-item>
                  <el-form-item label="单位注册邮编" :label-width="labelWidth">
                    <el-input v-model="elseInfoForm.ybCode" style="width: 250px"></el-input>
                  </el-form-item>
                  <el-form-item label="经营面积" :label-width="labelWidth">
                    <el-input v-model="elseInfoForm.area" style="width: 250px"></el-input>
                  </el-form-item>
                  <el-form-item label="注册资金" :label-width="labelWidth">
                    <el-input v-model="elseInfoForm.money" style="width: 250px"></el-input>
                  </el-form-item>
                  <el-form-item label="职业卫生安全负责人" :label-width="labelWidth">
                    <el-input v-model="elseInfoForm.resPeople" style="width: 250px"></el-input>
                  </el-form-item>
                  <el-form-item label="建档日期" :label-width="labelWidth">
                    <el-input v-model="elseInfoForm.jdDate" style="width: 250px"></el-input>
                  </el-form-item>
                  <el-form-item label="建厂日期" :label-width="labelWidth">
                    <el-input v-model="elseInfoForm.jcDate" style="width: 250px"></el-input>
                  </el-form-item>
                  <el-form-item label="检测联系人" :label-width="labelWidth">
                    <el-input v-model="elseInfoForm.jcPeople" style="width: 250px"></el-input>
                  </el-form-item>
                  <el-form-item label="检测联系电话" :label-width="labelWidth">
                    <el-input v-model="elseInfoForm.jcPhone" style="width: 250px"></el-input>
                  </el-form-item>
                  <el-form-item label="检测联系人职务" :label-width="labelWidth">
                    <el-input v-model="elseInfoForm.jcRole" style="width: 250px"></el-input>
                  </el-form-item>
                  <el-form-item label="体检联系人职务" :label-width="labelWidth">
                    <el-input v-model="elseInfoForm.tjRole" style="width: 250px"></el-input>
                  </el-form-item>
                  <el-form-item label="安全联系人职务" :label-width="labelWidth">
                    <el-input v-model="elseInfoForm.safeRole" style="width: 250px"></el-input>
                  </el-form-item>
                  <el-form-item label="安全联系人电话" :label-width="labelWidth">
                    <el-input v-model="elseInfoForm.safePhone" style="width: 250px"></el-input>
                  </el-form-item>
                  <el-form-item label="隶属关系" :label-width="labelWidth">
                    <el-input v-model="elseInfoForm.relation" style="width: 250px"></el-input>
                  </el-form-item>
                  <el-form-item label="作业场所地址" :label-width="labelWidth">
                    <el-input v-model="elseInfoForm.place" style="width: 250px"></el-input>
                  </el-form-item>
                  <el-form-item label="作业场所邮编" :label-width="labelWidth">
                    <el-input v-model="elseInfoForm.workCode" style="width: 250px"></el-input>
                  </el-form-item>
                  <el-form-item label="职业卫生管理机构" :label-width="labelWidth">
                    <el-input v-model="elseInfoForm.institution" style="width: 250px"></el-input>
                  </el-form-item>
                </el-form>
              </el-tab-pane>
              <!-- 检测信息 -->
              <el-tab-pane label="检测信息" name="third">
                <!-- 按钮 -->
                <el-button type="primary">
                  <el-icon><Plus></Plus></el-icon>
                  新增
                </el-button>
                <span style="color: red; margin-left: 5px">职业性有害因素检测结果</span>
                <!-- 表格 -->
                <el-table :data="checkInfoTable" border style="margin-top: 7px">
                  <el-table-column label="#"></el-table-column>
                  <el-table-column label="职业有害因素" width="150"></el-table-column>
                  <el-table-column label="其他有害因素" width="150"></el-table-column>
                  <el-table-column label="在岗状态" width="150"></el-table-column>
                  <el-table-column label="工种" width="150"></el-table-column>
                  <el-table-column label="其他工种" width="150"></el-table-column>
                  <el-table-column label="浓度(强度)范围" width="150"></el-table-column>
                  <el-table-column label="检测时间" width="150"></el-table-column>
                  <el-table-column fixed="right" label="操作" width="120">
                    <template #default>
                      <el-button>删除</el-button>
                    </template>
                  </el-table-column>
                </el-table>
              </el-tab-pane>
            </el-tabs>
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
// 上传图片
const imageUrl = ref('')

const handleAvatarSuccess = (response, uploadFile) => {
  imageUrl.value = URL.createObjectURL(uploadFile.raw)
}

const beforeAvatarUpload = (rawFile) => {
  if (rawFile.type !== 'image/jpeg') {
    ElMessage.error('Avatar picture must be JPG format!')
    return false
  } else if (rawFile.size / 1024 / 1024 > 2) {
    ElMessage.error('Avatar picture size can not exceed 2MB!')
    return false
  }
  return true
}
const selectValue = ref('')
const useHint = ref(true)
const useForm = ref(true)
const usePagination = ref(true)
const BaseDataRef = ref()
const dialogVisible = ref(false)
const useFixed = ref(true)
const labelWidth = '125px'
const activeName = ref('first')

// table列
const tableColumnAttribute = ref([
  { prop: 'name', label: '单位名称', width: '240', align: 'center' },
  { prop: 'credit', label: '信用代码', width: '120', align: 'center' },
  { prop: 'examination', label: '体检类型', width: '120', align: 'center' },
  { prop: 'address', label: '所属地区', width: '120', align: 'center' },
  { prop: 'category', label: '行业类别', width: '120', align: 'center' },
  { prop: 'etype', label: '经济类型', width: '120', align: 'center' },
  { prop: 'scale', label: '企业规模', width: '120', align: 'center' },
  { prop: 'contact', label: '联系人', width: '120', align: 'center' },
  { prop: 'phone', label: '联系电话', width: '120', align: 'center' }
])

// table数据
const tableData = ref([
  {
    name: '乐山市峨边盛和矿业',
    credit: '--',
    examination: '健康体检',
    address: '--',
    category: '铁矿采选*',
    etype: '国有企业',
    scale: '--',
    contact: '--',
    phone: '--'
  },
  {
    name: '---',
    credit: '--',
    examination: '健康体检',
    address: '--',
    category: '铁矿采选*',
    etype: '国有企业',
    scale: '--',
    contact: '--',
    phone: '--'
  },
  {
    name: '乐山市峨边盛和矿业',
    credit: '--',
    examination: '健康体检',
    address: '--',
    category: '铁矿采选*',
    etype: '国有企业',
    scale: '--',
    contact: '--',
    phone: '--'
  },
  {
    name: '乐山市峨边盛和矿业',
    credit: '--',
    examination: '健康体检',
    address: '--',
    category: '铁矿采选*',
    etype: '国有企业',
    scale: '--',
    contact: '--',
    phone: '--'
  },
  {
    name: '乐山市峨边盛和矿业',
    credit: '--',
    examination: '健康体检',
    address: '--',
    category: '铁矿采选*',
    etype: '国有企业',
    scale: '--',
    contact: '--',
    phone: '--'
  },
  {
    name: '乐山市峨边盛和矿业',
    credit: '--',
    examination: '健康体检',
    address: '--',
    category: '铁矿采选*',
    etype: '国有企业',
    scale: '--',
    contact: '--',
    phone: '--'
  },
  {
    name: '乐山市峨边盛和矿业',
    credit: '--',
    examination: '健康体检',
    address: '--',
    category: '铁矿采选*',
    etype: '国有企业',
    scale: '--',
    contact: '--',
    phone: '--'
  }
])

function handelLook(row) {
  console.log(row)
}

// form表单数据
const formData = reactive({
  unitName: '',
  creditCode: '',
  contactPerson: '',
  contactPhone: ''
})

// 基础信息表单
const basicForm = reactive({
  unitName: '',
  examinationType: '',
  creditCode: '',
  region: '',
  ecoType: '',
  location: '',
  scale: '',
  number: '',
  dangerousNum: ''
})

// 联系人表单
const contactForm = reactive({
  people: '',
  phone: ''
})

// 其他信息表单
const elseInfoForm = reactive({
  frName: '',
  frPhone: '',
  scgNum: '',
  nvNum: '',
  ybCode: '',
  area: '',
  money: '',
  resPeople: '',
  jdDate: '',
  jcDate: '',
  jcPeople: '',
  jcPhone: '',
  jcRole: '',
  tjRole: '',
  safeRole: '',
  safePhone: '',
  relation: '',
  place: '',
  workCode: '',
  institution: ''
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
  ;(formData.unitName = ''), (formData.creditCode = ''), (formData.contactPerson = ''), (formData.contactPhone = '')
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
