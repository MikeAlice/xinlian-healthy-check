import { defineStore } from 'pinia'
import { addSystemNoticeApi, updateSystemNoticeApi, querySystemNoticeApi } from '@/apis/systemmanagement/systemconfiguration/systemannouncementconfiguration/index.js'
export const useSystemAnnouncementConfigurationStore = defineStore('systemannouncementconfiguration', () => {
  // 将接口返回的数据存储到仓库中

  // 新增公告
  const addSystemNotice = async (params) => {
    return await addSystemNoticeApi(params)
  }

  // 修改公告
  const updateSystemNotice = async (params) => {
    return await updateSystemNoticeApi(params)
  }
  //获取公告
  const querySystemNotice = async (params) => {
    return await querySystemNoticeApi(params)
  }

  // 将保存好的数据暴露出去，方便页面调用
  return {
    addSystemNotice,
    updateSystemNotice,
    querySystemNotice
  }
})
