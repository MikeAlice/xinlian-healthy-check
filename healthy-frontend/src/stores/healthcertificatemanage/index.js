import {defineStore} from 'pinia'
import {ref} from 'vue'
import{
    getHelthcertidetailApi,
    getHerlthcertiListApi,
    putPrintConfirmApi,
    putHelthcertiListApi,
    postMoreApi,
    getViewExceptionApi
} from '@/apis/healthcertificatemanage/index.js'
export const usehealthcertificatemanageStore = defineStore('healthcertificatemanage',() => {
    //重写方法
    //获取健康证详情
    const getHelthcertidetail = async (params) => {
        return await getHelthcertidetailApi(params)
    }
    //获取健康证列表
    const getHerlthcertiList = async (params) => {
        return await getHerlthcertiListApi(params)
    }
    //打印确认（支持批量）
    const putPrintConfirm = async (params) => {
        return await putPrintConfirmApi(params)
    }
    //批量打印（批量打印）
    const putHelthcertiList = async (params) => {
        return await putHelthcertiListApi(params)
    }
    //批量上传
    const postMore = async (params) => {
        return await postMoreApi(params)
    }

    const  getViewException = async (params) => {
        return await getViewExceptionApi(params)
    }
    //暴露出的数据
    return{
        getHelthcertidetail,
        getHerlthcertiList,
        putPrintConfirm,
        putHelthcertiList,
        postMore,
        getViewException
    }
})