import Request from '@/apis/request.js'
const baseUrl = 'http://localhost:10100/api'

/**
 * 消息模块
 * API接口服务
 * zlw
 */

//消息列表
// 获取消息列表
export const MessageQueryAll = (params) => {
  return Request.requestForm(Request.GET, baseUrl + '/message/t-message/MessageQueryAll', params)
}

// 删除消息
export const removeByIds = (params) => {
  return Request.requestForm(Request.DELETE, baseUrl + '/message/t-message/remove-by-ids', params)
}

//消息详情
// 获取消息详情
export const MessageSendQuery = (params) => {
  return Request.requestForm(Request.GET, baseUrl + '/message/t-message-send/MessageSendQuery/' + params)
}

//查询未读消息
export const MessageSendUnRead = (params) => {
  return Request.requestForm(Request.GET, baseUrl + '/message/t-message-send/MessageSendUnRead', params)
}

//修改消息状态
export const addUpdateMessageSender = (params) => {
  return Request.requestForm(Request.GET, baseUrl + '/message/t-message-send/updateMessageSend', params)
}
