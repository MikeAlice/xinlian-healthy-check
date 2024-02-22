import Request from '@/apis/request.js'
const baseUrl = ''

//获取健康证详情
export const getHelthcertidetailApi = (params) => {
    return Request.requestForm(
        Request.GET,
        baseUrl + '/healthcertificate-manage/download-helthcertidetail',
        params
    )
}

//获取健康证列表
export const getHerlthcertiListApi = (params) => {
    return Request.requestForm(
        Request.GET,
        baseUrl + '/healthcertificate-manage/query-herlthcertilist',
        params
    )
}

//打印确认（支持批量）
export const putPrintConfirmApi = (params) => {
    return Request.requestJson(
        Request.PUT,
        baseUrl + '/healthcertificate-manage/modify-printconfirm',
    )
}

//批量打印（批量打印）
export const putHelthcertiListApi = (params) => {
    return Request.requestJson(
        Request.PUT,
        baseUrl + '​/healthcertificate-manage​/modify-printmore',
    )
}

//批量上传
export const postMoreApi = (params) => {
    return Request.requestJson(
        Request.POST,
        baseUrl + '/healthcertificate-manage/upload-more',
    )
}

//查看异常
export const getViewExceptionApi = (params) => {
    return Request.requestJson(
        Request.GET,
        baseUrl + '/healthcertificate-manage/query-viewexception',
    )
}