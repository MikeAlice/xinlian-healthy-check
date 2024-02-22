/* 组合项目apis */
import Request from '@/apis/request.js'
const baseUrl = '/portfolioitems'

// 科室名称列表
export const getDepartmentNamesListApi = (params) => {
  return Request.requestForm(Request.GET, baseUrl + '/query-section-name-list', params)
}
// 获取基础项目列表(条件+分页)
export const getBasePortfolioListApi = (params) => {
  return Request.requestForm(Request.GET, baseUrl + '/query-base-portfolio-list', params)
}
// 获取项目名称列表(用于输入表单下拉列表)
export const getProjectNameListForDropdownApi = (params) => {
  return Request.requestForm(Request.GET, baseUrl + '/query-project-name-list', params)
}
// 获取项目列表(条件+分页)
export const getProjectListWithConditionsApi = (params) => {
  return Request.requestForm(Request.GET, baseUrl + '/query-lists', params)
}
// 获取指定项目详情
export const getProjectDetailApi = (params) => {
  return Request.requestForm(Request.GET, baseUrl + '/{id}', params)
}
// 新增项目
export const addProjectApi = (params) => {
  return Request.requestJson(Request.POST, baseUrl + '/addproject', params)
}
// 删除项目(支持批量删除)
export const deleteProjectApi = (params) => {
  return Request.requestForm(Request.POST, baseUrl + '/deletePproject', params)
}
// 修改指定项目
export const updateProjectApi = (params) => {
  return Request.requestJson(Request.POST, baseUrl + '/updatePproject', params)
}
