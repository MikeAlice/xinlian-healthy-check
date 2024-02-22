import { defineStore } from 'pinia'
import {
  getDepartmentNamesWithPaginationApi,
  getDepartmentsListWithPaginationApi,
  getDepartmentDetailApi,
  addDepartmentApi,
  deleteDepartmentApi,
  modifyDepartmentApi
} from '@/apis/medicalregistration/index.js'

export const useMedicalRegistrationStore = defineStore('MedicalRegistration', () => {
  // 重写方法并去除Api后缀
  const getDepartmentNamesWithPagination = async (params) => {
    return await getDepartmentNamesWithPaginationApi(params)
  }

  const getDepartmentsListWithPagination = async (params) => {
    return await getDepartmentsListWithPaginationApi(params)
  }

  const getDepartmentDetail = async (params) => {
    return await getDepartmentDetailApi(params)
  }

  const addDepartment = async (params) => {
    return await addDepartmentApi(params)
  }

  const deleteDepartment = async (params) => {
    return await deleteDepartmentApi(params)
  }

  const modifyDepartment = async (params) => {
    return await modifyDepartmentApi(params)
  }

  // 暴露出的数据
  return {
    getDepartmentNamesWithPagination,
    getDepartmentsListWithPagination,
    getDepartmentDetail,
    addDepartment,
    deleteDepartment,
    modifyDepartment
  }
})
