<!--
 * @Author: setti5 2283356040@qq.com
 * @Date: 2024-01-31 17:10:36
 * @LastEditors: setti5 2283356040@qq.com
 * @LastEditTime: 2024-02-02 17:11:29
 * @FilePath: \zero-one-healthy-check\healthy-frontend\src\views\basicdata\SampleLibrary\SampleLibraryForm.vue
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
-->
<template>
  <div class="SampleLibraryDialog">
    <!-- 保留备用代码 -->
    <!-- <el-dialog v-model="dialogVisible" title="新增" width="50%" :before-close="handleClose"> -->

    <el-dialog
      v-model="dialogVisible"
      width="50%"
      @close="
        () => {
          if (props.title === '新增') {
            basicForm = {
              sampleName: '',
              barcodeCopies: 0,
              sampleStandards: '',
              isBloodSampling: '否',
              sampleCode: '',
              rank: 30,
              isPrint: '否',
              associationCode: '',
              capacity: ''
            }
          }
          dialogVisible = false
          basicFormRef.clearValidate()
        }
      "
    >
      <template #header>
        <h4>{{ props.title }}</h4>
      </template>
      <el-col>
        <el-form ref="basicFormRef" :model="basicForm" :rules="rules" label-width="120px" inline>
          <el-form-item label="名称" prop="sampleName">
            <el-input v-model="basicForm.sampleName" placeholder="请输入名称" style="width: 200px"></el-input>
          </el-form-item>
          <el-form-item label="条码份数" prop="barcodeCopies">
            <el-input v-model="basicForm.barcodeCopies" style="width: 200px"></el-input>
          </el-form-item>
          <el-form-item label="规格" prop="sampleStandards">
            <el-input v-model="basicForm.sampleStandards" placeholder="请输入规格" style="width: 200px"></el-input>
          </el-form-item>
          <el-form-item label="是否采血" prop="isBloodSampling">
            <el-radio-group v-model="basicForm.isBloodSampling" style="width: 200px">
              <el-radio label="是" />
              <el-radio label="否" />
            </el-radio-group>
          </el-form-item>
          <el-form-item label="标本代码" prop="sampleCode">
            <el-input v-model="basicForm.sampleCode" placeholder="请输入标本代码" style="width: 200px"></el-input>
          </el-form-item>
          <el-form-item label="排序" prop="rank">
            <el-input v-model="basicForm.rank" style="width: 200px"></el-input>
          </el-form-item>
          <el-form-item label="是否打印" prop="isPrint">
            <el-radio-group v-model="basicForm.isPrint" style="width: 200px">
              <el-radio label="是" />
              <el-radio label="否" />
            </el-radio-group>
          </el-form-item>
          <el-form-item label="关联码" prop="associationCode">
            <el-input v-model="basicForm.associationCode" placeholder="请输入关联码" style="width: 200px"></el-input>
          </el-form-item>
          <el-form-item label="容量" prop="capacity">
            <el-input v-model="basicForm.capacity" placeholder="请输入容量" style="width: 200px"></el-input>
          </el-form-item>
        </el-form>
      </el-col>
      <template #footer>
        <span class="dialog-footer">
          <el-button @click="dialogVisible = false">取消</el-button>
          <!-- <el-button type="primary" @click="dialogVisible = false">提交</el-button> -->
          <el-button type="primary" @click="props.handleSubmit">提交</el-button>
        </span>
      </template>
    </el-dialog>
  </div>
</template>

<script setup>
import { ref } from 'vue'
const dialogVisible = ref(false)
const basicFormRef = ref()

// 基础信息表单
const basicForm = ref({
  sampleName: '',
  barcodeCopies: 0,
  sampleStandards: '',
  isBloodSampling: '否',
  sampleCode: '',
  rank: 30,
  isPrint: '否',
  associationCode: '',
  capacity: ''
})

const rules = ref({
  sampleName: [{ required: true, message: '名称不能为空!', trigger: 'blur' }],
  barcodeCopies: [{ required: false, trigger: 'blur' }],
  sampleStandards: [{ required: true, message: '规格不能为空!', trigger: 'blur' }],
  isBloodSampling: [{ required: false, trigger: 'blur' }],
  sampleCode: [{ type: 'date', required: true, message: '标本代码不能为空!', trigger: 'blur' }],
  rank: [{ required: true, trigger: 'blur' }],
  isPrint: [{ required: false, trigger: 'blur' }],
  associationCode: [{ required: false, trigger: 'blur' }],
  capacity: [{ required: false, trigger: 'blur' }]
})

const open = (row) => {
  console.log(row)
  dialogVisible.value = true
}

const props = defineProps({
  handleSubmit: {
    type: Function,
    default: () => {
      console.log('submit')
    }
  },
  title: {
    type: String,
    default: '新增'
  }
})

defineExpose({
  dialogVisible,
  basicForm,
  basicFormRef,
  open
})
</script>
