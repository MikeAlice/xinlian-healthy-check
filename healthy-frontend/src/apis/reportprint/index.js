import Request from '@/apis/request.js'
const baseUrl = 'http://localhost:8090/'

/* 该接口文件的封装顺序参考接口文档网址从上到下排列 */

// 查询报告预览
export const queryPreviewReport = (params) => {
  return Request.requestJson(Request.GET, baseUrl + '/preview', params)
}

// 获取体检人员报告
export const queryMedExamPrintReport = (params) => {
  return Request.requestJson(Request.GET, baseUrl + '/medexamprint', params)
}

// 报告下载
export const downloadFile = (params) => {
  return Request.requestJson(Request.GET, baseUrl + '/downloadReport', params)
}

// 报告打印
export const modifyPrintReport = (params) => {
  return Request.requestJson(Request.PUT, baseUrl + '/printConfire', params)
}

// 报告打印
// export const downloadFile = (params) => {
//   return Request.requestJson(Request.PUT, baseUrl + '/downloadSampleCode', params)
// }
