<!-- 体检登记 -->
<template>
  <el-container style="height: 100vh">
    <!-- 侧边栏 -->
    <el-aside :style="{ maxWidth: isCollapsed ? '0px' : '300px' }">
      <PeopleList
        :style="isCollapsed ? 'display: none;' : 'min-width: 300px;'"
        :title="title"
        :checkbox-item="checkboxItem"
        :is-date-visible="isDateVisible"
        :external-form-items="formConfig.formItems"
      >
      </PeopleList>
    </el-aside>
    <!-- 伸缩按钮 -->
    <div class="shrink-button">
      <!-- 伸缩按钮 -->
      <el-icon style="cursor: pointer; width: 20px" @click="isCollapsed = !isCollapsed">
        <ArrowRightBold v-if="isCollapsed" />
        <ArrowLeftBold v-else />
      </el-icon>
    </div>
    <!-- 主要内容 -->
    <el-main>
      <!-- 登记信息 -->
      <MedicalInfo
        ref="medicalInfoRef"
        :current-progress="currentProgress"
        :progress-steps="progressSteps"
        :person-info="personInfo"
        :field-config="fieldConfig"
        :required-fields="requiredFields"
        :on-input-click="checkJob"
      />
      <!-- 按钮区域 -->
      <div style="margin-bottom: 10px">
        <el-button type="primary" v-if="!isShow" @click="handleEditInfo" style="background-color: #ffad33; border-color: #ffad33">
          <el-icon style="margin-right: 2px"> <Edit /> </el-icon>修改信息
        </el-button>
        <el-button type="primary" v-if="!isShow" @click="handleSingleAdd">
          <el-icon style="margin-right: 2px"> <Plus /> </el-icon>零星新增
        </el-button>
        <el-button type="primary" v-if="!isShow" @click="handleTeamAdd">
          <el-icon style="margin-right: 2px"> <Plus /> </el-icon>团检新增
        </el-button>
        <el-button type="primary" v-if="!isShow" style="background-color: #f16643; border-color: #f16643" disabled
          ><el-icon style="margin-right: 2px"> <Delete /> </el-icon>删除
        </el-button>
        <el-button type="primary" v-if="isShow" @click="readIdCard">
          <el-icon style="margin-right: 2px">
            <Loading v-if="isLoading" class="icon-loading" />
            <Plus v-else /> </el-icon
          >读取二代身份证
        </el-button>
        <el-button type="primary" v-if="!isShow" @click="printSheet">
          <el-icon style="margin-right: 2px"> <Printer /> </el-icon>打印导检单
        </el-button>
        <el-button type="primary" v-if="isShow" @click="savePersonInfo"
          ><el-icon style="margin-right: 2px"> <CaretRight /> </el-icon>保存信息</el-button
        >
      </div>
      <!-- 体检项目选择 -->
      <div class="card-header">
        <span>体检项目</span>
        <CheckItems bottonTitle="套餐选择" tableTitle="套餐选择" :isShowSelectDown="false" :tableLieForTc="tableLieForTc" :tableDataForTc="tableDataForTc">
          <el-icon style="margin-right: 2px">
            <Plus />
          </el-icon>
        </CheckItems>
        <CheckItems bottonTitle="选检项目" tableTitle="套餐项目" :tableLieForTc="tableLieForTc2" :tableDataForTc="tableDataForTc2" :selectDown="selectDown">
          <el-icon style="margin-right: 2px">
            <Plus />
          </el-icon>
        </CheckItems>
      </div>
      <!-- 数据列表显示 -->
      <BaseDataList ref="baseDataListRef" :use-form="false" :form-data="formData" :table-column-attribute="tableColumnAttribute" :table-data="tableData" :use-fixed="true">
        <template #fixed="{ row }">
          <el-button type="primary" @click="deleteProject(row)" style="background-color: #f16643; border-color: #f16643">
            <el-icon style="margin-right: 2px"> <Delete /> </el-icon>删除
          </el-button>
        </template>
      </BaseDataList>
      <!-- 折扣选择 -->
      <div style="display: flex; margin-top: 20px">
        <el-form-item label="必检项折扣：">
          <el-input-number v-model="requiredItemDiscount" :min="0" :max="100"></el-input-number>
        </el-form-item>
        <el-form-item label="选检项折扣：">
          <el-input-number v-model="optionalItemDiscount" :min="0" :max="100"></el-input-number>
        </el-form-item>
        <el-form-item label="优惠价：">
          <el-input-number v-model="discountPrice" :min="0"></el-input-number>
        </el-form-item>
      </div>
      <!-- 操作提示 -->
      <div class="card-content">
        <span>操作说明</span>
        <p>第一步：点击新增</p>
        <p>第二步：填写信息（填写体检人员信息和选择体检项目）</p>
        <p>第三步：点击保存（保存体检人员和体检项目信息）</p>
        <p>第四步：采集人像（采集体检人员头像）</p>
        <p>第五步：确认登记</p>
        <p>第六步：打印导检单（体检人员可以根据导检单进行体检）</p>
        <p>或执行第四、五、六步</p>
      </div>
      <!-- 默认隐藏的组件 -->
      <CheckItems
      v-if="isCheckItemsVisible"
      tableTitle="工种名称"
      :hideButton="true"
      :openDrawer="true"
      :isShowSelectDown="false"
      :tableLieForTc="jobNameLie"
      :tableDataForTc="jobNameData"
      @submitTc="getJobNameData" />
      <el-dialog v-model="isPdfObjectVisible" title="打印导检单" style="width: 80%">
        <div class="dialog-content">
          <!-- 头部容器 -->
          <div class="header-container">
            <Head name="体检导检单" style="width: 70%; font-size: 15px" />

            <Head name="样本条码" style="width: 25%; font-size: 15px">
              <el-button type="primary" @click="printBarcode" style="height: 30px; margin-left: 100px">
                <el-icon style="margin-right: 2px"> <Printer /> </el-icon>打印样本条码
              </el-button>
            </Head>
          </div>
          <!-- PDF容器 -->
          <PdfObject />
        </div>
      </el-dialog>
      <el-dialog v-model="isEditInfoVisible" title="人员信息修改" style="width: 60%">
        <div class="editInfoCard-header">
          <span class="header-title">基本信息</span>
          <el-button type="primary" @click="readIdCard">
            <el-icon style="margin-right: 2px">
              <Loading v-if="isLoading" class="icon-loading" />
              <Plus v-else />
            </el-icon>
            读取二代身份证
          </el-button>
        </div>
        <el-form :rules="editRules" class="two-column-form">
          <div class="form-container">
          <div class="form-row">
            <el-form-item label="人员姓名" prop="personName">
            <el-input v-model="editData.name" placeholder="请输入姓名" />
          </el-form-item>
          <el-form-item label="证件号码" prop="idNumber">
            <el-input v-model="editData.idNumber" placeholder="请输入证件号码" />
          </el-form-item>
          <el-form-item label="性别" prop="sex">
            <el-radio-group v-model="editData.sex">
              <el-radio label="male">男</el-radio>
              <el-radio label="female">女</el-radio>
            </el-radio-group>
          </el-form-item>
          <el-form-item label="出生日期" prop="birth">
            <el-date-picker
              v-model="editData.checkTime"
              type="date"
              placeholder="选择日期"
              />
          </el-form-item>
          <el-form-item label="年龄" prop="age">
            <el-input v-model="editData.age" placeholder="请输入年龄"/>
          </el-form-item>
          <el-form-item label="结婚状况" prop="isMarry">
            <el-select v-model="editData.isMarry" placeholder="请选择">
              <el-option label="未婚" value="single"></el-option>
              <el-option label="已婚" value="married"></el-option>
              <el-option label="离异" value="divorced"></el-option>
              <el-option label="丧偶" value="widowed"></el-option>
            </el-select>
          </el-form-item>
          <el-form-item label="手机号码" prop="mobile">
            <el-input v-model="editData.mobile" placeholder="请输入手机号"/>
          </el-form-item>
          <el-form-item label="危害因素" prop="harmName">
            <el-input v-model="editData.harmName" placeholder="请输入危害因素"/>
          </el-form-item>
          <el-form-item label="工种名称" prop="jobName">
            <el-input v-model="editData.jobName" placeholder="请输入工种名称"/>
          </el-form-item>
          <el-form-item label="在岗状态" prop="workStatus">
            <el-select v-model="editData.workStatus" placeholder="请选择">
              <el-option label="在岗" value="online"></el-option>
            </el-select>
          </el-form-item>
          <el-form-item label="监测类型" prop="monitorType">
            <el-select v-model="editData.monitorType" placeholder="请选择">
              <el-option label="常规监测" value="usually"></el-option>
            </el-select>
          </el-form-item>
          <el-form-item label="登记时间" prop="checkTime">
            <el-date-picker
              v-model="editData.checkTime"
              type="date"
              placeholder="选择日期"
              />
          </el-form-item>
          <el-form-item label="单位名称" prop="untiName">
            <el-select v-model="editData.unitName" placeholder="请选择">
              <el-option label="测试单位" value="test"></el-option>
            </el-select>
          </el-form-item>
          <el-form-item label="分组" prop="groupName">
            <el-select v-model="editData.groupName" placeholder="请选择">
              <el-option label="测试分组" value="test2"></el-option>
            </el-select>
          </el-form-item>
          </div>
          <div class="button-group">
            <el-button @click="cancelButton">取消</el-button>
            <el-button type="primary">提交</el-button>
          </div>
        </div>
        </el-form>
      </el-dialog>
    </el-main>
  </el-container>
</template>

<script setup>
import PeopleList from '@/components/peoplelist/PeopleList.vue'
import MedicalInfo from '@/components/medicalinfo/MedicalInfo.vue'
import BaseDataList from '@/components/basedatalist/BaseDataList.vue'
import CheckItems from '@/components/checkitems/CheckItems.vue'
import PdfObject from '@/components/pdfobject/PdfObject.vue'
import Head from '@/components/head/Head.vue'
import { ref, nextTick } from 'vue'
import { ElMessage } from 'element-plus'
import { ArrowRightBold, ArrowLeftBold, Edit, Plus, Delete, Printer, CaretRight, Loading } from '@element-plus/icons-vue'
import { useMedicalRegistrationStore } from '@/stores/MedicalRegistration/index.js'
import { usePublicStore } from '@/stores/Public/index.js'
/* Stores中的方法 */
const MedicalRegistrationStore = useMedicalRegistrationStore()
const PublicStore = usePublicStore()

/* PeopleList的变量 */
const title = ref('人员查询')
const checkboxItem = ref(['未登记', '已登记'])
const isDateVisible = ref(false)
const formConfig = ref({
  formItems: [
    {
      type: 'input',
      name: '',
      placeholder: '请输入身份证号'
    },
    {
      type: 'input',
      name: '',
      placeholder: '请输入体检编号'
    },
    {
      type: 'input',
      name: '',
      placeholder: '请输入单位名称'
    }
  ]
})
/* MedicalInfo的变量 */
const currentProgress = ref(1)
const progressSteps = ref(['登记', '在检', '总检', '已完成'])
const fieldConfig = ref([
  { prop: 'physical_id', label: '体检编号', type: 'input', placeholder: '提交后系统自动生成', disabled: true },
  { prop: 'id_card', label: '身份证号', type: 'input', placeholder: '请输入身份证号', readonly: true },
  { prop: 'person_name', label: '姓名', type: 'input', placeholder: '请输入姓名', readonly: true },
  { prop: 'sex', label: '性别', type: 'input', placeholder: '性别', readonly: true },
  { prop: 'age', label: '年龄', type: 'input', placeholder: '年龄', readonly: true },
  { prop: 'physical_type', label: '体检类型', type: 'input', placeholder: '体检类型', readonly: true },
  { prop: 'mobile', label: '联系电话', type: 'input', placeholder: '联系电话', readonly: true },
  { prop: 'unit_name', label: '单位名称', type: 'input', placeholder: '单位名称', readonly: true },
  { prop: 'hazardous_factors', label: '危害因素', type: 'input', placeholder: '选择套餐后自动生成', disabled: true },
  { prop: 'job_name', label: '工种名称', type: 'input', placeholder: '工种名称', readonly: true, methodBound: true },
  { prop: 'check_type', label: '检查种类', type: 'input', placeholder: '选择套餐后自动生成', disabled: true },
  {
    prop: 'type_name',
    label: '分组名称',
    type: 'select',
    placeholder: '选择套餐后自动生成',
    disabled: true,
    options: [
      { label: '男', value: '男' },
      { label: '女', value: '女' }
    ]
  },
  {
    prop: 'marry_type',
    label: '婚姻状态',
    type: 'select',
    placeholder: '请选择',
    options: [
      { label: '未婚', value: '未婚' },
      { label: '已婚', value: '已婚' },
      { label: '离异', value: '离异' },
      { label: '丧偶', value: '丧偶' },
      { label: '其他', value: '其他' }
    ]
  }
])
const requiredFields = ref(['id_card', 'person_name', 'sex', 'age', 'physical_type', 'mobile', 'unit_name', 'job_name'])
const personInfo = ref({
  physical_id: '',
  id_card: '',
  person_name: '',
  sex: '',
  age: '',
  physical_type: '',
  mobile: '',
  unit_name: '',
  hazardous_factors: '',
  job_name: '',
  check_type: '',
  type_name: '',
  marry_type: ''
})
/* CheckItems的变量 */
// 套餐选择
const jobNameLie = ref([
  {
    prop: 'id',
    label: '#'
  },
  {
    prop: 'job_name',
    label: '工种名称'
  }
])
const jobNameData = ref([
  {
    id: '1',
    job_name: '护士'
  },
  {
    id: '2',
    job_name: '护师'
  }
])
const tableLieForTc = ref([
  {
    prop: 'id',
    label: '#'
  },
  {
    prop: 'combo_name',
    label: '套餐名称'
  }
])
const tableDataForTc = ref([
  {
    id: '1',
    combo_name: '1,2-二氯乙烷-上岗前'
  },
  {
    id: '2',
    combo_name: '1,2-二氯乙烷-上岗前'
  }
])
// 选检项目
const tableLieForTc2 = ref([
  {
    prop: 'id',
    label: '#'
  },
  {
    prop: 'project_name',
    label: '名称'
  },
  {
    prop: 'price',
    label: '销售价'
  }
])
const tableDataForTc2 = ref([
  {
    id: '1',
    project_name: 'test',
    price: 554
  }
])
const selectDown = ref([
  {
    value: 'inquiry',
    label: '问诊科'
  },
  {
    value: 'facial_features',
    label: '五官科'
  }
])
// 获取数据
const getJobNameData = (row) =>{
  const jobNameField = fieldConfig.value.find(field => field.prop === 'job_name');
  if (jobNameField) {
    personInfo.value.job_name = row[0].job_name // 更新 job_name 的值
  }
}
/* BaseDataList的变量 */
const tableColumnAttribute = ref([
  { prop: 'id', label: '#', width: 150, align: 'center' },
  { prop: 'projectName', label: '项目名称', width: 100, align: 'center' },
  { prop: 'originalPrice', label: '原价', width: 150, align: 'center' },
  { prop: 'discount', label: '折扣', width: 250, align: 'center' },
  { prop: 'discountPrice', label: '折扣价', width: 250, align: 'center' },
  { prop: 'projectType', label: '项目类型', width: 250, align: 'center' }
])
const tableData = ref([
  { id: '1', projectName: '肝炎筛查', originalPrice: 188, discount: 0.8, discountPrice: 150.4, projectType: '一号套餐' },
  { id: '2', projectName: '肝炎筛查', originalPrice: 188, discount: 0.8, discountPrice: 150.4, projectType: '一号套餐' },
  { id: '1', projectName: '肝炎筛查', originalPrice: 188, discount: 0.8, discountPrice: 150.4, projectType: '一号套餐' },
  { id: '1', projectName: '肝炎筛查', originalPrice: 188, discount: 0.8, discountPrice: 150.4, projectType: '一号套餐' }
])
// 计算总和
const totalOriginalPrice = tableData.value.reduce((sum, row) => sum + (row.originalPrice || 0), 0)
const totalDiscountPrice = tableData.value.reduce((sum, row) => sum + (row.discountPrice || 0), 0)
tableData.value.push({
  id: '合计',
  projectName: '-',
  originalPrice: totalOriginalPrice,
  discount: '-',
  discountPrice: totalDiscountPrice,
  projectType: '-'
})
const formData = ref({
  id: '',
  projectName: '',
  originalPrice: '',
  discount: '',
  discountPrice: '',
  projectType: ''
})
const baseDataListRef = ref(null)
// 编辑及删除函数
const deleteProject = (row) => {
  console.log(row)
}
/* 本界面变量及函数 */
const isCollapsed = ref(false) // 是否收缩侧边栏
const isShow = ref(false) // 是否展示按钮
const isCheckItemsVisible = ref(false) // 是否展示抽屉
const isLoading = ref(false) // 读取身份证图标显示
const isPdfObjectVisible = ref(false) // 是否显示pdf弹窗
const requiredItemDiscount = ref(100) // 必检项
const optionalItemDiscount = ref(100) // 选检项
const discountPrice = ref(0) // 优惠价
const isEditInfoVisible = ref(false) // 是否显示修改信息弹窗
const medicalInfoRef = ref(null) // 调用子组件传递的方法
const editRules= ref( {
      personName: [
        { required: true, message: '请输入人员姓名', trigger: 'blur' }
      ],
      sex: [
        { required: true, message: '请选择性别', trigger: 'blur' }
      ],
      age: [
        { required: true, message: '请输入年龄', trigger: 'blur' }
      ],
      mobile: [
        { required: true, message: '请输入手机号', trigger: 'blur' }
      ],
      harmName: [
        { required: true, message: '请输入危害因素', trigger: 'blur' }
      ],
      jobName: [
        { required: true, message: '请输入工种名称', trigger: 'blur' }
      ],
      workStatus: [
        { required: true, message: '请输入在岗状态', trigger: 'blur' }
      ],
      monitorType: [
        { required: true, message: '请输入监测类型', trigger: 'blur' }
      ],
      groupName: [
        { required: true, message: '请输入分组', trigger: 'blur' }
      ],
})
const editData = ref({
  personName: '',
  sex: '',
  birth: '',
  age: '',
  isMarry: '',
  mobile: '',
  harmName: '',
  jobName: '',
  workStatus: '',
  monitorType: '',
  checkTime: '',
  unitName: '',
  groupName: ''
})
// 选择工种名称
const checkJob = () => {
  isCheckItemsVisible.value = false // 首先设置为 false
  // 使用 nextTick 确保 DOM 更新后再设置为 true
  nextTick(() => {
    isCheckItemsVisible.value = true
  })
}
// 零星新增
const handleSingleAdd = () => {
  isShow.value = true
  fieldConfig.value.forEach((field) => {
    if (field.readonly) {
      field.readonly = false
    }
  })
}
// 团检新增
const handleTeamAdd = () => {
  isShow.value = true
  fieldConfig.value.forEach((field) => {
    if (field.readonly) {
      field.readonly = false
    }
  })
}
// 读取身份证
const readIdCard = () => {
  // 设置 isLoading 为 true
  isLoading.value = true
  // 3秒后重置 isLoading 状态
  setTimeout(() => {
    isLoading.value = false
    ElMessage.error('请安装身份证读卡器服务！')
  }, 3000)
}
// 打印导检单
const printSheet = () => {
  isPdfObjectVisible.value = false
  nextTick(() => {
    isPdfObjectVisible.value = true
  })
}
// 保存信息
const savePersonInfo = async () => {
  // 假设 formRef 是子组件的引用
  const isValid = await medicalInfoRef.value.validate();
  if (!isValid) {
    // 表单验证失败
    ElMessage.error('表单验证失败，请检查输入');
    return;
  }
  // 表单验证成功，继续执行保存逻辑
  isShow.value = false
  fieldConfig.value.forEach((field) => {
    if (!field.readonly) {
      field.readonly = true
    }
  })
}
// 打印样本条码
const printBarcode = () => {
  ElMessage.warning('正在打印条码...')
}
// 修改信息
const handleEditInfo = () => {
  isEditInfoVisible.value = false
  nextTick(() => {
    isEditInfoVisible.value = true
  })
}
// 修改的取消按钮
const cancelButton = () => {
  isEditInfoVisible.value = false
}
</script>
<style scoped>
.shrink-button {
  display: flex;
  align-items: center;
  height: 100%;
}
.card-header {
  padding-left: 10px;
  margin-bottom: 10px;
  display: flex;
  justify-content: left;
  align-items: center;
  text-align: center;
  background-color: rgb(240, 250, 255);
  border: 1px solid #abdcff;
  height: 40px;

  span {
    color: rgb(81, 90, 110);
    font-weight: 550;
  }
}
.card-content {
  margin-top: 10px;
  padding: 10px 0 10px 40px;
  text-align: left;
  background-color: rgb(240, 250, 255);
  border: 1px solid #abdcff;

  span {
    color: rgb(81, 90, 110);
    font-weight: 550;
  }
}
.icon-loading {
  animation: rotating 2s infinite linear;
}
@keyframes rotating {
  to {
    transform: rotate(1turn);
  }
}
.dialog-content {
  display: flex;
  flex-direction: column;
}

.header-container {
  display: flex;
  justify-content: space-between;
  margin-bottom: 20px;
}
.editInfoCard-header {
  padding-bottom: 4px;
  margin-bottom: 10px;
  display: flex;
  justify-content: space-between;
  align-items: center;
  border-bottom: 1px solid #ccc; /* 添加底部边框 */
}
.header-title {
  position: relative;
  color: rgb(41, 136, 243);
  font-size: 14px;
}
.header-title::after {
  content: '';
  position: absolute;
  bottom: -10px; /* 调整下划线位置 */
  left: 0;
  right: 0;
  height: 2px;
  background-color: rgb(41, 136, 243); /* 下划线颜色 */
  display: block;
}

.two-column-form .form-row {

  display: flex;
  flex-wrap: wrap;
  gap: 10px; /* 添加间隙 */
  align-items: flex-start; /* 对齐表单项 */
}

.two-column-form .el-form-item {
  flex: 1 1 47%; /* 灵活性调整，考虑间隙 */
  min-width: 250px; /* 最小宽度，用于响应式 */
}
.button-group {
  text-align: right; /* 按钮向右对齐 */
  padding: 10px; /* 添加一些内边距 */
}

</style>
