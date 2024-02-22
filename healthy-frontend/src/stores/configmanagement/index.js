import { defineStore } from 'pinia'
import { ref } from 'vue'
import {
  getProjectListApi,
  getTemplateListApi,
  getTemplateDetailApi,
  addTemplateApi,
  deleteTemplateApi,
  updateTemplateApi,
  modifyTemplateStatusApi,
  previewTemplateApi
} from '@/apis/configmanagement/index.js'

export const useConfigManagementStore = defineStore('ConfigManagement', () => {
  // 定义重写的方法
  const getProjectList = async (params) => {
    return await getProjectListApi(params)
  }

  const getTemplateList = async (params) => {
    return await getTemplateListApi(params)
  }

  const getTemplateDetail = async (params) => {
    return await getTemplateDetailApi(params)
  }

  const addTemplate = async (params) => {
    return await addTemplateApi(params)
  }

  const deleteTemplate = async (params) => {
    return await deleteTemplateApi(params)
  }

  const updateTemplate = async (params) => {
    return await updateTemplateApi(params)
  }

  const modifyTemplateStatus = async (params) => {
    return await modifyTemplateStatusApi(params)
  }

  const previewTemplate = async (params) => {
    return await previewTemplateApi(params)
  }

  // 暴露出的数据和方法
  return {
    getProjectList,
    getTemplateList,
    getTemplateDetail,
    addTemplate,
    deleteTemplate,
    updateTemplate,
    modifyTemplateStatus,
    previewTemplate
  }
})
