/* 体检登记apis */
import Request from '@/apis/request.js'
const baseUrl = ''

// 获取体检人员名称列表(分页+条件)
export const getMedicalPersonNameApi = (params) => {
  return Request.requestJson(Request.GET, baseUrl + '/Exalanding/query-peoplelist', params)
}
// 获取体检人员详情
export const getMedicalPersonInfoApi = (params) => {
  return Request.requestJson(Request.GET, baseUrl + '/GetPD', params)
}
// 修改人员信息
export const putMedicalPersonInfoApi = (params) => {
  return Request.requestJson(Request.PUT, baseUrl + '/exalanding/modify-information', params)
}
// 删除人员
export const delMedicalPersonInfoApi = (params) => {
  return Request.requestJson(Request.DELETE, baseUrl + '/questatistics/remove-personList', params)
}
// 获取可选团单列表
export const getGroupListApi = (params) => {
  return Request.requestJson(Request.GET, baseUrl + '/exalanding', params)
}
