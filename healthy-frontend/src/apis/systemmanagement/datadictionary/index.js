// 数据字典api
import Request from '@/apis/request.js'
const baseUrl = ''

// 添加字典
export const addDictApi = (params) => {
  return Request.requestForm(Request.POST, baseUrl + '/j3-dict/addDict', params)
}

// 分页获取全部字典
export const getAllDictApi = (params) => {
  return Request.requestJson(Request.GET, baseUrl + '/j3-dict/getAllDict', params)
}

// 新增字典数据
export const addDictDataApi = (params) => {
  return Request.requestForm(Request.POST, baseUrl + '/j3-directSource/addDictData', params)
}

// 根据id批量删除字典数据
export const deleteByIdsApi = (params) => {
  return Request.requestForm(Request.Delete, baseUrl + '/j3-directSource/deleteByIds', params)
}

// 修改字典数据
export const updateDictDataApi = (params) => {
  return Request.requestForm(Request.POST, baseUrl + '/j3-directSource/modifyDictData', params)
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
