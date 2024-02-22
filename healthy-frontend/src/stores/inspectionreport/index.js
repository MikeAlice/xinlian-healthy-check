import {defineStore} from 'pinia'
import {ref} from 'vue'

import{
    getReportListApi,
    getReportDetailApi,
    putReportReviewApi,
} from '@/apis/inspectionreport/index.js'

export const useinspectionreportStore = defineStore('inspectionreport',() => {
    //重写方法
    const getReportList = async (params) => {
        return await getReportListApi(params)
    }

    const getReportDetail = async (params) => {
        return await  getReportDetailApi(params)
    }

    const putReportReview = async (params) => {
        return await putReportReviewApi(params)
    }

    //暴露出的数据
    return{
        getReportList,
        getReportDetail,
        putReportReview
    }
})