import { defineStore } from 'pinia'
import { ref } from 'vue'
import { MessageQueryAll, removeByIds, MessageSendQuery, MessageSendUnRead, addUpdateMessageSender } from '@/apis/messagemodule/index.js'
export const useMessageModuleStores = defineStore('messageModuleStores', () => {
  /**
   * 消息模块-j2
   * stores
   * zlw
   * @param {} params
   * @returns
   */
  // 重写方法
  const MessageQueryAllStore = async (params) => {
    return await MessageQueryAll(params)
  }
  const removeByIdsStore = async (params) => {
    return await removeByIds(params)
  }
  const MessageSendQueryStore = async (params) => {
    return await MessageSendQuery(params)
  }
  const MessageSendUnReadStore = async (params) => {
    return await MessageSendUnRead(params)
  }
  const addUpdateMessageSenderStore = async (params) => {
    return await addUpdateMessageSender(params)
  }

  // 暴露出的数据
  return {
    MessageQueryAllStore,
    removeByIdsStore,
    MessageSendQueryStore,
    MessageSendUnReadStore,
    addUpdateMessageSenderStore
  }
})
