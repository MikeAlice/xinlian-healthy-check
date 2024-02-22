// 消息管理api
import Request from '@/apis/request.js'
const baseUrl = ''

// 批量删除消息
export const deleteMessagesByIdsApi = (params) => {
  return Request.requestForm(Request.DELETE, baseUrl + '/j3-message/deleteByIds', params)
}

// 获取消息详情页列表
export const queryMessageDetailApi = (params) => {
  return Request.requestJson(Request.GET, baseUrl + '/j3-message/queryMessageDetail', params)
}

// 获取消息列表
export const queryMsgListApi = (params) => {
  return Request.requestForm(Request.GET, baseUrl + '/j3-message/queryMsgList', params)
}

// 发送信息
export const sendMessageApi = (params) => {
  return Request.requestForm(Request.POST, baseUrl + '/j3-message/sendMessage', params)
}

// 更新信息
export const updateMessageApi = (params) => {
  return Request.requestForm(Request.PUT, baseUrl + '/j3-message/updateMessage', params)
}

// 获取工种名称列表(分页+条件)
// export const queryByWordTypeApi = (params) => {
//   return Request.requestForm(Request.GET, baseUrl + '/j3-directSource/queryByWordType', params)
// }

// 查询字典数据名称列表
export const queryDataTitleApi = (params) => {
  return Request.requestForm(Request.GET, baseUrl + '/j3-directSource/queryDataTitle', params)
}

// 查询字典数据列表
export const queryDictDataByConditionApi = (params) => {
  return Request.requestForm(Request.GET, baseUrl + '/j3-directSource/queryDictDataByCondition', params)
}
