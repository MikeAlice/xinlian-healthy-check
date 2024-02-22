import Request from '@/apis/request.js'
const baseUrl = ''

//获取体检报告列表
export const getReportListApi = (params) => {
    return Request.requestForm(
        Request.GET,
        baseUrl + '/inspection-report/report-list',
        params
    )
}

//获取体检报告详情
export const getReportDetailApi = (params) => {
    return Request.requestForm(
        Request.GET,
        baseUrl + '/inspection-report/download-reportdetail',
        params
    )
}

//获取体检报告详情
export const putReportReviewApi = (params) => {
    return Request.requestJson(
        Request.PUT,
        baseUrl + '/inspection-report/modify-reportreview',
    )
}