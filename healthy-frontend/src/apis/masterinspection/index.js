//主检评价接口
import Request from '@/apis/request.js'
const baseUrl = ''

// 获取体检人员名称列表(分页+条件)
export const getMedicalPersonNameApi = (params) => {
  return Request.requestForm(Request.GET, baseUrl + '/getUserName/query-unit', params)
}

// 获取体检人员详情
export const getMedicalPersonDetailsApi = (params) => {
  return Request.requestJson(Request.GET, baseUrl + '/personDetail/query-detail', params)
}

// 忽略指定基础项目
export const ignoreProjectApi = (params) => {
  return Request.requestJson(Request.PUT, baseUrl + '/healthy-c7-common/update-depart-item-result', params)
}

// TODO下载个人报告word
export const downloadReportApi = (params) => {
  return Request.requestForm(Request.GET, baseUrl + '/healthy-c7-common/download-word', params)
}

// 审查
export const reviewApi = (params) => {
  return Request.requestJson(Request.PUT, baseUrl + '/healthy-c7-common/update-personal-review', params)
}

// 新增复查项目
export const addReviewItemApi = (params) => {
  return Request.requestForm(Request.POST, baseUrl + '/review/post-addNewItems', params)
}

// 复查报告查看
export const reviewPdfApi = (params) => {
  return Request.requestForm(Request.GET, baseUrl + '/review/pdf-review', params)
}

// 获取复查项目列表
export const getReviewItemsListApi = (params) => {
  return Request.requestForm(Request.GET, baseUrl + '/review/query-review', params)
}

// 复查（删除复查项目）
export const deleteReviewItemApi = (params) => {
  return Request.requestForm(Request.GET, baseUrl + '/review/{id}', params)
}

// 复查（修改复查项目）
export const updateReviewItemApi = (params) => {
  return Request.requestJson(Request.GET, baseUrl + '/review', params)
}

// 获取问诊明细
export const getInquiryDetailsApi = (params) => {
  return Request.requestForm(Request.GET, baseUrl + '/evalue/inquiry-detail', params)
}

// 获取体检项目结果明细
export const getMedicalExaminationResultsApi = (params) => {
  return Request.requestForm(Request.GET, baseUrl + '/item-result', params)
}

// 获取阳性结果列表
export const getPositiveResultsListApi = (params) => {
  return Request.requestForm(Request.GET, baseUrl + '/positive/query-positive', params)
}

//报告预览
export const previewReportApi = (params) => {
  return Request.requestForm(Request.GET, baseUrl + '/report', params)
}

// 保存总检报告
export const storageInspectorReportApi = (params) => {
  return Request.requestForm(Request.GET, baseUrl + '/info/save-info-inspect', params)
}

// 获取添加项目结论列表
export const getAddedProjectConclusionsListApi = (params) => {
  return Request.requestForm(Request.GET, baseUrl + '/result/depart-result', params)
}

// 获取体检项目结果明细
export const getMedicalExaminationResultsListApi = (params) => {
  return Request.requestForm(Request.GET, baseUrl + '/Dangerous/query-depart', params)
}
