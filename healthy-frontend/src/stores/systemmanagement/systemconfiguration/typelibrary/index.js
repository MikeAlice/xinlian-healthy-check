import { defineStore } from 'pinia'
import { addTypeApi, updateTypeApi } from '@/apis/systemmanagement/systemconfiguration/typelibrary/index.js'
export const usetypelibraryStore = defineStore('typelibrary', () => {
  // 将接口返回的数据存储到仓库中

  // 添加类型库
  const addType = async (params) => {
    return await addTypeApi(params)
  }

  // 修改类型库
  const updateType = async (params) => {
    return await updateTypeApi(params)
  }

  // 将保存好的数据暴露出去，方便页面调用
  return {
    addType,
    updateType
  }
})
