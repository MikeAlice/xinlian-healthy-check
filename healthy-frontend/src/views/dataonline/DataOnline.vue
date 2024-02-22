<!-- 数据网报 -->
<!-- 数据网报 -->
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
      <!-- 表格后面的操作选项群 -->
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
        <el-form-item label="企业名称" :style="{ width: '260px' }">
            <el-select v-model="formData.unitName" placeholder="请选择">
            <el-option label="乐山市峨边盛和矿业" value="乐山市峨边盛和矿业" />
            <el-option label="乐山市峨边盛和农业" value="乐山市峨边盛和农业" />
          </el-select>
        </el-form-item>


        <el-form-item label="体检日期">
          <el-radio-group v-model="formData.checkdate" label="体检日期" size="small">
           <el-date-picker
           v-model="formData.checkdate"
           type="daterange"
           start-placeholder="开始时间"
           end-placeholder="结束时间"
           :size="size"
          />
        </el-radio-group>
        </el-form-item>
        <el-form-item label="网传状态">
          <el-select
          v-model="formData.webstate"
          class="m-2"
          placeholder="请选择"
          style="width: 240px"
        >
            <el-option
              v-for="item in webstateoptions"
              :key="item.value"
              :label="item.label"
              :value="item.value"
            />
        </el-select>
        </el-form-item>
        <el-form-item label="是否复查" :style="{ width: '200px' }">
          <el-select
          v-model="formData.ifcheck"
          class="m-2"
          placeholder="请选择"
          style="width: 240px"
        >
            <el-option
              v-for="item in ifcheckoptions"
              :key="item.value"
              :label="item.label"
              :value="item.value"
            />
        </el-select>
        </el-form-item>
     <div  v-if="isShowInput" class="expend">
      <el-form-item label="订单编号">
          <el-input v-model="formData.checkid" :style="{ width: '200px' }"></el-input>
        </el-form-item>
        <el-form-item label="人员姓名">
          <el-input v-model="formData. checkname" :style="{ width: '200px' }"></el-input>
        </el-form-item>
        <el-form-item label="证件号码">
          <el-input v-model="formData.identity" :style="{ width: '200px' }"></el-input>
        </el-form-item>
        <el-form-item label="体检结论">
          <el-input v-model="formData.checkresult" :style="{ width: '230px' }"></el-input>
        </el-form-item>
        <el-form-item label="主检建议">
          <el-input v-model="formData.maincheckadvise" :style="{ width: '230px' }"></el-input>
        </el-form-item>
      </div>
        
        <el-form-item>
          <el-button type="primary">
            <el-icon><Search></Search></el-icon>
            搜索
          </el-button>
        </el-form-item>
        <el-form-item>
          <el-button @click="resetForm">重置</el-button>

          <el-button type="text" style="margin-left: 20px" @click="toggleCollapse"
            >{{ isShowInput ? '收起' : '展开' }}
            <el-icon v-show="isShowInput === true"><ArrowUp /></el-icon>
            <el-icon v-show="isShowInput === false"><ArrowDown /></el-icon>
          </el-button>
        </el-form-item>
      </template>                               

      <!-- operation功能区域 -->
      <template #operation>
        <div class="operation">
          <!-- <el-button type="primary" style="margin-right: 10px" @click="dialogVisible = true">
            <el-icon><Plus></Plus></el-icon>
            新增
          </el-button> -->
          <!-- 新增对话框区域 -->
          <el-dialog v-model="dialogVisible" title="新增" width="60%" :before-close="handleClose">
            <el-row>
              <el-col :span="20">
                <el-form :model="basicForm" inline>
                  <el-form-item label="单位名称" :label-width="labelWidth">
                    <el-input v-model="basicForm.unitName" placeholder="请输入单位名称" style="width: 232px"></el-input>
                  </el-form-item>
                  <el-form-item label="体检类型" :label-width="labelWidth">
                    <el-select v-model="basicForm.examinationType" style="width: 232px"></el-select>
                  </el-form-item>
                  <el-form-item label="统一社会信用代码" :label-width="labelWidth">
                    <el-input v-model="basicForm.creditCode" placeholder="请输入统一社会信用代码" style="width: 232px"></el-input>
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
            <template #footer>
              <span class="dialog-footer">
                <el-button @click="dialogVisible = false">取消</el-button>
                <el-button type="primary" @click="dialogVisible = false">提交</el-button>
              </span>
            </template>
          </el-dialog>

          
            <el-button type="primary">
              <el-icon><Refresh></Refresh></el-icon>数据同步</el-button>
            <el-button type="success" dark="true">
              <el-icon><Refresh></Refresh></el-icon>按企业上报</el-button>
            <el-button type="success">
              <el-icon><Refresh></Refresh></el-icon>自定义上报</el-button>
            <el-button type="success"  dark="true" style="margin-right: 10px;">
              <el-icon><Refresh></Refresh></el-icon>智能网报</el-button>
          
          

          <!-- 下拉按钮 -->
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
import {ArrowUp,ArrowDown, Search, Plus, InfoFilled, Refresh, DeleteFilled, Bottom, View, Edit} from '@element-plus/icons-vue'
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
// table列
const tableColumnAttribute = ref([
  { prop: 'name', label: '企业名称', width: '240', align: 'center' },
  { prop: 'credit', label: '订单编号', width: '120', align: 'center' },
  { prop: 'examination', label: '人员姓名', width: '120', align: 'center' },
  { prop: 'address', label: '性别', width: '120', align: 'center' },
  { prop: 'category', label: '证件号码', width: '120', align: 'center' },
  { prop: 'etype', label: '年龄', width: '120', align: 'center' },
  { prop: 'scale', label: '婚否', width: '120', align: 'center' },
  { prop: 'contact', label: '人员联系电话', width: '120', align: 'center' },
  { prop: 'harmfulfactors', label: '接害因素', width: '120', align: 'center' },
  { prop: 'harmfulfactorsyears', label: '接害工龄年数', width: '120', align: 'center' },
  { prop: 'harmfulfactorsmonths', label: '接害工龄月数', width: '120', align: 'center' },
  { prop: 'othernames', label: '工种其他名称', width: '120', align: 'center' },
  { prop: 'datecheck', label: '体检日期', width: '120', align: 'center' },
  { prop: 'resultcheck', label: '体检结果', width: '120', align: 'center' },
  { prop: 'maindoctor', label: '主检医师', width: '120', align: 'center' },
  { prop: 'begindate', label: '开始接害日期', width: '120', align: 'center' },
  { prop: 'webstate', label: '网传状态', width: '120', align: 'center' },
  { prop: 'ifcheck', label: '是否复查', width: '120', align: 'center' },
])
// table数据
const tableData = ref([
  {
    name: '乐山市峨边盛和矿业',
    credit: '3456356',
    examination: '姓名1',
    address: '男',
    category: '123412354*',
    etype: '18',
    scale: '否',
    contact: '1234353456',
    phone: '无-'
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
])
function handelLook(row) {
  console.log(row)
}

const formData = reactive({
  unitName: '',
  checkdate: '',
  webstate: '',
  ifcheck: '',
  checkid:'',
  checkname:'',
  identity:'',
  checkresult:'',
  maincheckadvise:''
})

const webstateoptions = [
  {
    value: '未上传',
    label: '未上传',
  },
  {
    value: '上传成功',
    label: '上传成功',
  },
  {
    value: '上传失败',
    label: '上传失败',
  },
  {
    value: '已删除',
    label: '已删除',
  },
]

const ifcheckoptions = [
  {
    value: '是',
    label: '是',
  },
  {
    value: '否',
    label: '否',
  }
]



// 点击展开按钮按钮的折叠逻辑
const isShowInput = ref(false)
const toggleCollapse = () => {
  isShowInput.value = !isShowInput.value
}

// 新增部分的内容
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
</script>

<style lang="scss" scoped>
.expend{
  display:isShowInput
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

