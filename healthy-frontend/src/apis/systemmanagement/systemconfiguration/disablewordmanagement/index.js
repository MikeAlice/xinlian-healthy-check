// 禁用词管理api
import Request from '@/apis/request.js'
const baseUrl = ''

// 添加禁用词
export const addStopWordApi = (params) => {
  return Request.requestForm(Request.POST, baseUrl + '/j3-stopWord/addStopWord', params)
}

// 批量删除禁用词
export const deleteWordsByIdsApi = (params) => {
  return Request.requestForm(Request.DELETE, baseUrl + '/j3-stopWord/deleteWordsByIds', params)
}

// 获取禁用词列表(分页+条件)
export const queryStopWordApi = (params) => {
  return Request.requestForm(Request.GET, baseUrl + '/j3-stopWord/queryStopWord', params)
}

// 修改禁用词
export const updateStopWordApi = (params) => {
  return Request.requestForm(Request.PUT, baseUrl + '/j3-stopWord/updateWord', params)
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
