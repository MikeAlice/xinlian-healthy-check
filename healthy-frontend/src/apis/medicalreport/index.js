/* 体检登记apis */
import Request from '@/apis/request.js'
const baseUrl = ''

// 获取体检人员名称列表(分页+条件)
export const getMedicalPersonPeopleApi = (params) => {
  return Request.requestJson(Request.GET, baseUrl + '/checks/query-report', params)
}
// 报告预览
export const getPreviewReportApi = (params) => {
  return Request.requestJson(Request.GET, baseUrl + '/previews/preview-report', params)
}
