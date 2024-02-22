/* 模板管理apis */
import Request from '@/apis/request.js'
const baseUrl = '/template'
// 获取组合项目名称列表
export const getProjectListApi = (params) => {
  return Request.requestForm(Request.GET, baseUrl + '/query-project-list', params)
}
// 获取模板列表（条件+分页）
export const getTemplateListApi = (params) => {
  return Request.requestForm(Request.GET, baseUrl + '/query-list', params)
}
// 获取模板详情
export const getTemplateDetailApi = (params) => {
  return Request.requestForm(Request.GET, baseUrl + '/query-term-detail/{templateId}', params)
}
// 新增模板
export const addTemplateApi = (params) => {
  return Request.requestJson(Request.POST, baseUrl + '/add-template', params)
}
// 删除模板（支持批量删除）
export const deleteTemplateApi = (params) => {
  return Request.requestForm(Request.DELETE, baseUrl + '/delete', params)
}
// 修改模板
export const updateTemplateApi = (params) => {
  return Request.requestJson(Request.POST, baseUrl + '/update', params)
}
// 启用-禁用状态
export const modifyTemplateStatusApi = (params) => {
  return Request.requestForm(Request.POST, baseUrl + '/modify-status', params)
}
// 预览模板
export const previewTemplateApi = (params) => {
  return Request.requestForm(Request.GET, baseUrl + '/query-content', params)
}
