import { defineStore } from 'pinia'
import {
  addStopWordApi,
  deleteWordsByIdsApi,
  queryStopWordApi,
  updateStopWordApi,
  updateMessageApi,
  queryDataTitleApi,
  queryDictDataByConditionApi
} from '@/apis/systemmanagement/systemconfiguration/disablewordmanagement/index.js'
export const useDisableWordManagementStore = defineStore('disablewordmanagement', () => {
  // 将接口返回的数据存储到仓库中

  // 添加禁用词
  const addStopWord = async (params) => {
    return await addStopWordApi(params)
  }

  // 批量删除禁用词
  const deleteWordsByIds = async (params) => {
    return await deleteWordsByIdsApi(params)
  }
  //获取禁用词列表
  const queryStopWord = async (params) => {
    return await queryStopWordApi(params)
  }
  // 修改禁用词
  const updateStopWord = async (params) => {
    return await updateStopWordApi(params)
  }
  //更新信息
  const updateMessage = async (params) => {
    return await updateMessageApi(params)
  }
  //查询字典数据名称列表
  const queryDataTitle = async (params) => {
    return await queryDataTitleApi(params)
  }

  //查询字典数据列表
  const queryDictDataByCondition = async (params) => {
    return await queryDictDataByConditionApi(params)
  }

  // 将保存好的数据暴露出去，方便页面调用
  return {
    addStopWord,
    deleteWordsByIds,
    queryStopWord,
    updateStopWord,
    updateMessage,
    queryDataTitle,
    queryDictDataByCondition
  }
})
