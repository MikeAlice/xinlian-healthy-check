/* 科室管理apis */
import Request from '@/apis/request.js'
const baseUrl = '/sectionoffice'

// 获取科室名称列表(条件+分页)
export const getDepartmentNamesWithPaginationApi = (params) => {
  return Request.requestForm(Request.GET, baseUrl + '/query-allsection-office-name', params)
}
// 获取科室列表(分页+条件)
export const getDepartmentsListWithPaginationApi = (params) => {
  return Request.requestForm(Request.GET, baseUrl + '/query-allsection-office', params)
}
// 获取科室详情
export const getDepartmentDetailApi = (params) => {
  return Request.requestForm(Request.GET, baseUrl + '/query-section-office-detail', params)
}
// 新增科室
export const addDepartmentApi = (params) => {
  return Request.requestJson(Request.POST, baseUrl + '/add-section-office', params)
}
// 删除科室
export const deleteDepartmentApi = (params) => {
  return Request.requestForm(Request.DELETE, baseUrl + '/remove-section-office', params)
}
// 修改科室
export const modifyDepartmentApi = (params) => {
  return Request.requestJson(Request.PUT, baseUrl + '/modify-section-office', params)
}
