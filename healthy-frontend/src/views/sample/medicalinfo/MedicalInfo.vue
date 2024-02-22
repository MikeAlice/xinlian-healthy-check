<template>
  <MedicalInfo :current-progress="currentProgress" :progress-steps="progressSteps" :person-info="personInfo" />
</template>

<script setup>
import { ref } from 'vue'

import MedicalInfo from '@/components/medicalinfo/MedicalInfo.vue'
// 后端返回的数据
const currentProgress = ref(1)
const progressSteps = ref(['登记', '在检', '总检', '已完成'])
const personInfo = ref({
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
</script>
