import Request from '@/apis/request.js'
const baseUrl = 'http://localhost:8090/'

/* 该接口文件的封装顺序参考接口文档网址从上到下排列 */

// 获取列表
export const queryCheckReport = (params) => {
  return Request.requestJson(Request.GET, baseUrl + '/checks/query-report', params)
}

// 获取word、pdf
export const queryPreviewReport = (params) => {
  return Request.requestJson(Request.GET, baseUrl + '/previews/preview-report', params)
}
