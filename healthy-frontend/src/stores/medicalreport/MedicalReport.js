import { defineStore } from 'pinia'
import { ref } from 'vue'
import { getMedicalPersonPeopleApi, getPreviewReportApi } from '@/apis/medicalreport/index.js'
export const useMedicalRegistrationStore = defineStore('MedicalRegistration', () => {
  // 重写方法
  const getMedicalPersonPeople = async (params) => {
    return await getMedicalPersonPeopleApi(params)
  }
  const getPreviewReport = async (params) => {
    return await getPreviewReportApi(params)
  }
  // 暴露出的数据
  return {
    getMedicalPersonPeople,
    getPreviewReport
  }
})
