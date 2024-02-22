import { defineStore } from 'pinia'
import { ref } from 'vue'
import { getMedicalPersonNameApi, getMedicalPersonInfoApi, putMedicalPersonInfoApi, delMedicalPersonInfoApi, getGroupListApi } from '@/apis/medicalregistration/index.js'
export const useMedicalRegistrationStore = defineStore('MedicalRegistration', () => {
  // 重写方法
  const getMedicalPersonName = async (params) => {
    return await getMedicalPersonNameApi(params)
  }
  const getMedicalPersonInfo = async (params) => {
    return await getMedicalPersonInfoApi(params)
  }
  const putMedicalPersonInfo = async (params) => {
    return await putMedicalPersonInfoApi(params)
  }
  const delMedicalPersonInfo = async (params) => {
    return await delMedicalPersonInfoApi(params)
  }
  const getGroupList = async (params) => {
    return await getGroupListApi(params)
  }
  // 暴露出的数据
  return {
    getMedicalPersonName,
    getMedicalPersonInfo,
    putMedicalPersonInfo,
    delMedicalPersonInfo,
    getGroupList
  }
})
