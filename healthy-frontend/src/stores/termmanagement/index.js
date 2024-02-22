import { defineStore } from 'pinia'
import { ref } from 'vue'
import {
  getDepartmentNamesApi,
  getOccupationalHazardTreeApi,
  getTermNamesListApi,
  getTermsListApi,
  getTermDetailApi,
  addTermApi,
  deleteTermApi,
  modifyTermApi,
  toggleTermStatusApi
} from '@/apis/medicalregistration/index.js'

export const useMedicalRegistrationStore = defineStore('MedicalRegistration', () => {
  // API方法重写，去除Api后缀
  const getDepartmentNames = async (params) => {
    return await getDepartmentNamesApi(params)
  }

  const getOccupationalHazardTree = async (params) => {
    return await getOccupationalHazardTreeApi(params)
  }

  const getTermNamesList = async (params) => {
    return await getTermNamesListApi(params)
  }

  const getTermsList = async (params) => {
    return await getTermsListApi(params)
  }

  const getTermDetail = async (params) => {
    return await getTermDetailApi(params)
  }

  const addTerm = async (params) => {
    return await addTermApi(params)
  }

  const deleteTerm = async (params) => {
    return await deleteTermApi(params)
  }

  const modifyTerm = async (params) => {
    return await modifyTermApi(params)
  }

  const toggleTermStatus = async (params) => {
    return await toggleTermStatusApi(params)
  }

  // 暴露出的数据和方法
  return {
    getDepartmentNames,
    getOccupationalHazardTree,
    getTermNamesList,
    getTermsList,
    getTermDetail,
    addTerm,
    deleteTerm,
    modifyTerm,
    toggleTermStatus
  }
})
