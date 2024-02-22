<template>
  <div class="container">
    <!-- 人脸采集 -->
    <div class="shoting">
      <div class="pic" @click="showDialog">
        <div class="pic-box">
          <img :src="previewImage || '/src/assets/medicalinfo/pic-icon.svg'" :style="previewImage ? previewImageStyle : defaultImageStyle" />
          <span v-if="!previewImage" class="pic-title">人脸采集</span>
        </div>
      </div>
      <!-- 弹窗组件 -->
      <el-dialog v-model="isDialogVisible" title="人脸采集" @close="hideDialog">
        <div class="dialog-content">
          <!-- 上方图片编辑区域 -->
          <div class="pic-cropper">
            <!-- 上传按钮 -->
            <img v-if="cropperImage" :src="cropperImage" :style="cropperImageStyle" />
            <el-upload :before-upload="handleBeforeUpload" list-type="picture-card" accept="image/png, image/jpeg, image/jpg">
              <el-button> 上传 </el-button>
            </el-upload>
          </div>
          <!-- 底部按钮 -->
          <div class="pic-options">
            <!-- 重新上传按钮 -->
            <span style="color: #409eff; cursor: pointer; padding-right: 15px" @click="editAction"> 重新上传 </span>
            <!-- 确认按钮 -->
            <el-button type="primary" @click="confirmAction"> 确认 </el-button>
            <!-- 取消按钮 -->
            <el-button @click="cancelAction"> 取消 </el-button>
          </div>
        </div>
      </el-dialog>
    </div>
    <!-- 右侧卡片 -->
    <div class="right-card">
      <!-- 完成进度(登记、在检、总检、已完成) -->
      <div class="step">
        <ul>
          <li v-for="(item, index) in progressSteps" :key="index">
            <img :src="getImagePath(index)" />
            <span>{{ item }}</span>
          </li>
        </ul>
      </div>
      <!-- 个人信息 -->
      <el-form ref="medicalInfoRdivef" :model="personInfo" label-width="80px" :rules="rules" class="flex-form">
        <div v-for="field in props.fieldConfig">
          <el-form-item v-if="field.type === 'input'" :label="field.label" :prop="field.prop">
            <el-input
              v-model="personInfo[field.prop]"
              :placeholder="field.placeholder"
              :readonly="field.readonly"
              :disabled="field.disabled"
              @click.native="field.methodBound ? onInputClick() : null"
            />
          </el-form-item>
          <el-form-item v-if="field.type === 'select'" :label="field.label" :prop="field.prop">
            <el-select v-model="personInfo[field.prop]" :placeholder="field.placeholder" :readonly="field.readonly" :disabled="field.disabled">
              <el-option v-for="option in field.options" :label="option.label" :value="option.value" />
            </el-select>
          </el-form-item>
        </div>
      </el-form>
    </div>
  </div>
</template>
<script setup>
import { ref, computed, watch, toRefs, defineEmits, defineExpose } from 'vue'
import { ElDialog, ElUpload, ElButton, ElMessageBox, ElMessage } from 'element-plus'
/* 向父组件传递的数据 */
const props = defineProps({
  // 当前流程
  currentProgress: {
    type: Number,
    required: true,
    default: 1
  },
  // 共有哪些流程
  progressSteps: {
    type: Array,
    required: true,
    default: () => ['登记', '在检', '总检', '已完成']
  },
  // 个人信息
  personInfo: {
    type: Object,
    required: false,
    default: () => ({
      physical_id: '2202401120016',
      id_card: '510521199304017011',
      person_name: 'test-rom',
      sex: '男',
      age: '30',
      physical_type: '健康体检',
      mobile: '18980504604',
      unit_name: 'test-rom',
      marry_type: '',
      type_name: ''
    })
  },
  // 字段配置数组
  fieldConfig: {
    type: Array,
    required: false,
    default: () => [
      { prop: 'physical_id', label: '体检编号', type: 'input', placeholder: '提交后系统自动生成', disabled: true },
      { prop: 'id_card', label: '身份证号', type: 'input', readonly: true },
      { prop: 'person_name', label: '姓名', type: 'input', readonly: true },
      { prop: 'sex', label: '性别', type: 'input', readonly: true },
      { prop: 'age', label: '年龄', type: 'input', readonly: true },
      { prop: 'physical_type', label: '体检类型', type: 'input', readonly: true },
      { prop: 'mobile', label: '联系电话', type: 'input', readonly: true },
      { prop: 'unit_name', label: '单位名称', type: 'input', readonly: true },
      {
        prop: 'marry_type',
        label: '婚姻状态',
        type: 'select',
        options: [
          { label: '未婚', value: '未婚' },
          { label: '已婚', value: '已婚' },
          { label: '离异', value: '离异' }
        ]
      },
      {
        prop: 'type_name',
        label: '分组名称',
        type: 'select',
        options: [
          { label: '男', value: '男' },
          { label: '女', value: '女' }
        ]
      }
    ]
  },
  // 输入框中必填的信息(须与prop值一致)
  requiredFields: {
    type: Array,
    required: false,
    default: () => ['id_card']
  },
  onInputClick: Function,
  // 暴露出输入框的值
  modelValue: Object
})
const medicalInfoRef = ref(null)
// 方法来执行表单验证
const validate = async () => {
  try {
    await formRef.value.validate()
    return true // 验证通过
  } catch (error) {
    return false // 验证失败
  }
}
// 暴露 validate 方法供父组件调用
defineExpose({ validate })

const emit = defineEmits(['update:modelValue'])
watch(
  () => props.modelValue,
  (newValue) => {
    emit('update:modelValue', newValue)
  },
  { deep: true }
)

// 根据当前流程判断展示的图片
function getImagePath(index) {
  if (index === 0) return props.currentProgress > 0 ? '/src/assets/medicalinfo/start_check.png' : '/src/assets/medicalinfo/start_nomal.png'
  if (index === props.progressSteps.length - 1) return props.currentProgress === props.progressSteps.length ? '/src/assets/medicalinfo/end_check.png' : '/src/assets/medicalinfo/end_nomal.png'
  return props.currentProgress > 1 && index < props.currentProgress ? '/src/assets/medicalinfo/mid_check.png' : '/src/assets/medicalinfo/mid_nomal.png'
}
// 动态创建验证规则
const rules = ref({})
watch(
  () => props.requiredFields,
  (newFields) => {
    const newRules = {}
    newFields.forEach((field) => {
      newRules[field] = [{ required: true, message: '', trigger: 'blur' }]
    })
    rules.value = newRules
  },
  { immediate: true }
)

/* 弹窗展示 */
// 用来控制弹窗的显示
const isDialogVisible = ref(false)
// 显示弹窗的方法
const showDialog = () => {
  isDialogVisible.value = true
}
// 隐藏弹窗的方法
const hideDialog = () => {
  isDialogVisible.value = false
}

/* 上传图片处理 */
// 用于存储图片预览的URL
const previewImage = ref('')
const cropperImage = ref('')
// 图片上传前处理
const handleBeforeUpload = (file) => {
  // 创建一个FileReader对象，用于读取文件
  const reader = new FileReader()
  // 读取成功后触发...
  reader.onload = (e) => {
    // 将读取到的图片存储到previewImage中
    cropperImage.value = e.target.result
  }
  // 将文件内容读取为Data URL（base64格式）
  reader.readAsDataURL(file)
  // 返回false阻止文件自动上传
  return false
}
// 处理重新上传操作的方法
const editAction = () => {
  ElMessageBox.confirm('确定要重新上传吗？', '提示', {
    confirmButtonText: '确定',
    cancelButtonText: '取消',
    type: 'warning'
  })
    .then(() => {
      // 用户点击确定后的操作
      cropperImage.value = ''
      previewImage.value = ''
    })
    .catch(() => {
      // 用户点击取消或关闭对话框时的操作
    })
}
// 处理确认操作的方法
const confirmAction = () => {
  previewImage.value = cropperImage.value
  isDialogVisible.value = false
}
// 处理取消操作的方法
const cancelAction = () => {
  cropperImage.value = ''
  isDialogVisible.value = false
}
// 默认图片样式
const defaultImageStyle = computed(() => ({
  display: 'block',
  margin: '0 auto',
  paddingTop: '40px'
}))
// 当上传图片时展示该样式
const previewImageStyle = computed(() => ({
  display: 'block',
  width: '100%',
  height: '100%',
  objectFit: 'cover', // 确保图片不失真
  position: 'absolute', // 绝对定位
  zIndex: 2
}))
// 当上传图片时展示该样式
const cropperImageStyle = computed(() => ({
  display: 'block',
  height: '100%',
  objectFit: 'cover', // 确保图片不失真
  position: 'absolute', // 绝对定位
  zIndex: 2
}))
</script>
<!-- 局内样式 -->
<style scoped>
/* 控制整体布局 */
.container {
  display: flex;
  justify-content: space-between;
}
.shoting .right-card {
  flex: 1; /* 调整 flex 基础大小，或使用具体的宽度，例如 flex: 0 0 300px; */
}
.shoting {
  flex: 1 1 12%; /* 让.shoting占据更多的空间 */
}
.right-card {
  flex: 1 1 90%; /* 让.right-card占据更多的空间 */
}

/* 人脸采集 */
.pic {
  cursor: pointer;
  padding: 0 20px 20px 20px;
}
.pic-box {
  border: 1px dashed #2988f3;
  width: 130px;
  height: 150px;
  text-align: center;
}
.pic-title {
  height: auto;
  line-height: 0;
  margin-top: 30px;
  color: rgb(41, 136, 243);
}
.pic-cropper,
.pic-options {
  display: flex;
  justify-content: center; /* 水平居中 */
  align-items: center; /* 垂直居中 */
  padding: 10px;
}

/* 当前流程(登记、在检查...) */
.step {
  ul {
    list-style: none;
    display: flex;
    padding: 0;
    margin: 0;

    li {
      position: relative;
      width: 100px;
      height: 30px;
      margin-right: -10px;

      span {
        position: absolute;
        top: 50%;
        left: 50%;
        transform: translate(-50%, -50%);
        z-index: 10;
        white-space: nowrap;
        color: #fff;
        font-size: 13px;
        font-weight: 600;
      }
    }
  }
}
/* 个人信息表单 */
.flex-form {
  padding-top: 20px;
  display: flex;
  flex-wrap: wrap; /* 允许表单项换行 */
  align-items: flex-start; /* 对齐表单项 */
}
.flex-form .el-form-item {
  flex: 1 1 25%; /* 每个表单项的基础大小和增长因子 */
}
</style>
<style>
.el-dialog {
  width: 35%;
}
.el-upload {
  padding: 100px;
}
.el-input,
.el-select {
  width: 180px;
}
.el-form-item__label {
  font-weight: 700;
  margin-left: 20px;
}
.el-form-item__label::before {
  font-family: SimSun;
  font-weight: 700;
}
</style>
