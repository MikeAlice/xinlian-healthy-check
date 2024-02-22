import Request from '@/apis/request.js'
const baseUrl = 'http://localhost:8090'

/* 该接口文件的封装顺序参考接口文档网址从上到下排列 */

// 分页查询团检单位名称列表
export const queryMedExamUnitOrder = (params) => {
  return Request.requestJson(Request.GET, baseUrl + '/MedExamUnitOrder', params)
}

// 获取单位报告
export const queryUnitReport = (params) => {
  return Request.requestJson(Request.GET, baseUrl + '/UnitReport', params)
}

// 获取单位订单
export const queryUnit = (params) => {
  return Request.requestJson(Request.GET, baseUrl + '/unitreportlist/query-unit', params)
}

// 获取体检人员汇总表
export const queryPhysicalExaminationPersonnel = (params) => {
  return Request.requestJson(Request.GET, baseUrl + '/ReportStatistics/PhysicalExaminationPersonnel', params)
}

// 获取复查人员汇总表
export const queryReviewPersonnel = (params) => {
  return Request.requestJson(Request.GET, baseUrl + '/ReportStatistics/ReviewPersonnel', params)
}

// 获取复查结果汇总表
export const queryReviewResults = (params) => {
  return Request.requestJson(Request.GET, baseUrl + '/ReportStatistics/ReviewResults', params)
}

// 获取选择报告
export const reportCheck = (params) => {
  return Request.requestJson(Request.GET, baseUrl + '/report-choice', params)
}
