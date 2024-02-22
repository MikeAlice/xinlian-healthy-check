/*
 * @Author: setti5 2283356040@qq.com
 * @Date: 2024-02-01 18:29:20
 * @LastEditors: setti5 2283356040@qq.com
 * @LastEditTime: 2024-02-05 14:08:40
 * @FilePath: \zero-one-healthy-check\healthy-frontend\src\apis\PrimaryInspectionEvaluation\index.js
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
import Request from '@/apis/request.js'
const baseUrl = 'http://106.15.202.126:8090'

/* 该接口文件的封装顺序参考接口文档网址从上到下排列 */
/* 对应亿图脑图中的主检评价接口，页面对应医生总检 */

// 获取体检项目结果明细（后端缺页面，接口只有危险值提示的参数）  1
export const queryDangerousInfo = (params) => {
  return Request.requestJson(Request.GET, baseUrl + '/Dangerous/query-depart', params)
}

// 获取添加项目结论列表（分页）  2
export const queryAddConclusionList = (params) => {
  return Request.requestJson(Request.GET, baseUrl + '/result/depart-result', params)
}

//保存总检信息  3
export const querySaveInfoInspect = (params) => {
  return Request.requestJson(Request.GET, baseUrl + '/info/save-info-inspect', params)
}

// 报告预览  4
export const queryPreviewReport = (params) => {
  return Request.requestJson(Request.GET, baseUrl + '/report', params)
}

// 获取术语名称列表(条件+分页)(公共)  5
export const queryTermsList = (params) => {
  return Request.requestJson(Request.GET, baseUrl + '/Term/query-term', params)
}

// 获取阳性结果列表(分页+条件)  6
export const queryPositiveResultsList = (params) => {
  return Request.requestJson(Request.GET, baseUrl + '/positive/query-positive', params)
}

// 获取阳性结果列表(excel导出执行)  7
export const queryPositiveResultsDownload = (params) => {
  return Request.requestJson(Request.GET, baseUrl + '/positive/positive-download', params)
}

// 获取体检项目结果明细  8
export const queryExaminationItemResult = (params) => {
  return Request.requestJson(Request.GET, baseUrl + '/item-result', params)
}

//获取问诊明细  9
export const queryEvaluateDetails = (params) => {
  return Request.requestJson(Request.GET, baseUrl + '/evalue/inquiry-detail', params)
}
// 获取问诊明细（修改） 10
export const modifyEvaluateDetails = (params) => {
  return Request.requestJson(Request.PUT, baseUrl + '/evalue/inquiry-detail', params)
}
// 获取问诊明细（pdf） 11
export const queryEvaluatePDF = (params) => {
  return Request.requestJson(Request.PUT, baseUrl + '/evalue/pdf-InquiryDetail', params)
}

//复查(获取复查项目列表)  12
export const queryReviewItemList = (params) => {
  return Request.requestJson(Request.GET, baseUrl + '/review/query-review', params)
}

//复查(修改复查项目)  13
export const modifyReviewItems = (params) => {
  return Request.requestJson(Request.PUT, baseUrl + '/review', params)
}

//复查(删除复查项目)  14
export const deleteReview = (params) => {
  return Request.requestJson(Request.DELETE, baseUrl + '/review/{id}', params)
}

//复查(复查报告查看)  15
export const queryReviewReport = (params) => {
  return Request.requestJson(Request.GET, baseUrl + '/review/pdf-review', params)
}

//复查(新增复查项目)  16
export const addReview = (params) => {
  return Request.requestJson(Request.POST, baseUrl + '/review/post-addNewItems', params)
}

// 审查  17
export const updatePersonalReview = (params) => {
  return Request.requestJson(Request.PUT, baseUrl + '/healthy-c7-common/update-personal-review', params)
}

// 下载个人报告word  18
export const downloadPersonalReport = (params) => {
  return Request.requestJson(Request.PUT, baseUrl + '/healthy-c7一common/ download-word', params)
}

//忽略指定基础项目  19
export const ignoreAssignedProject = (params) => {
  return Request.requestJson(Request.PUT, baseUrl + '/healthy-c7-common/update-depart-item-result', params)
}

// 获取人员详情  20
export const queryPersonDetails = (params) => {
  return Request.requestJson(Request.GET, baseUrl + '/personDetail/query-detail', params)
}

//获取体检人员名称列表(条件+分页)  21
export const queryExaminerNameList = (params) => {
  return Request.requestJson(Request.GET, baseUrl + '/getUserName/query-unit', params)
}
