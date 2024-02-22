/* 术语管理apis */
import Request from '@/apis/request.js'
const baseUrl = '/terms'

// 获取科室名称列表
export const getDepartmentNamesApi = (params) => {
  return Request.requestForm(Request.GET, baseUrl + '/query-secion-name-list', params)
}
// 获取职业危害因素树
export const getOccupationalHazardTreeApi = (params) => {
  return Request.requestJson(Request.POST, baseUrl + '/query-occupational-hazard-tree', params)
}
// 获取术语名称列表
export const getTermNamesListApi = (params) => {
  return Request.requestForm(Request.GET, baseUrl + '/query-termname-list', params)
}
// 获取术语列表
export const getTermsListApi = (params) => {
  return Request.requestForm(Request.GET, baseUrl + '/query-term-list', params)
}
// 获取术语详情
export const getTermDetailApi = (params) => {
  return Request.requestForm(Request.GET, baseUrl + '/query-term-detail/{id}', params)
}
// 新增术语
export const addTermApi = (params) => {
  return Request.requestForm(Request.GET, baseUrl + '/add—term', params)
}
// 删除术语
export const deleteTermApi = (params) => {
  return Request.requestForm(Request.DELETE, baseUrl + '/delete-termanagement', params)
}
// 修改术语
export const modifyTermApi = (params) => {
  return Request.requestJson(Request.POST, baseUrl + '/modify-term', params)
}
// 启用-禁用术语
export const toggleTermStatusApi = (params) => {
  return Request.requestForm(Request.POST, baseUrl + '/switch-term', params)
}
