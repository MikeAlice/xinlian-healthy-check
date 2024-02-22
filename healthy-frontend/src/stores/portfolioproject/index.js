import { defineStore } from 'pinia'
import { ref } from 'vue'
import {
  getDepartmentNamesListApi,
  getBasePortfolioListApi,
  getProjectNameListForDropdownApi,
  getProjectListWithConditionsApi,
  getProjectDetailApi,
  addProjectApi,
  deleteProjectApi,
  updateProjectApi
} from '@/apis/medicalregistration/index.js'

export const useMedicalRegistrationStore = defineStore('MedicalRegistration', () => {
  // 获取科室名称列表
  const getDepartmentNamesList = async (params) => {
    return await getDepartmentNamesListApi(params)
  }

  // 获取基础项目列表(条件+分页)
  const getBasePortfolioList = async (params) => {
    return await getBasePortfolioListApi(params)
  }

  // 获取项目名称列表(用于输入表单下拉列表)
  const getProjectNameListForDropdown = async (params) => {
    return await getProjectNameListForDropdownApi(params)
  }

  // 获取项目列表(条件+分页)
  const getProjectListWithConditions = async (params) => {
    return await getProjectListWithConditionsApi(params)
  }

  // 获取指定项目详情
  const getProjectDetail = async (params) => {
    return await getProjectDetailApi(params)
  }

  // 新增项目
  const addProject = async (params) => {
    return await addProjectApi(params)
  }

  // 删除项目(支持批量删除)
  const deleteProject = async (params) => {
    return await deleteProjectApi(params)
  }

  // 修改指定项目
  const updateProject = async (params) => {
    return await updateProjectApi(params)
  }

  // 暴露出的数据和方法
  return {
    getDepartmentNamesList,
    getBasePortfolioList,
    getProjectNameListForDropdown,
    getProjectListWithConditions,
    getProjectDetail,
    addProject,
    deleteProject,
    updateProject
  }
})
