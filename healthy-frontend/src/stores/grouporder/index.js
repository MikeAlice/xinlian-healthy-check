import {defineStore} from 'pinia'
import {ref} from 'vue'
import{
    importPersonApi,
    uploadEntrustApi,
    medicalPersonInfoApi,
} from '@/apis/grouporder/index.js'
export const useGroupOrderStore = defineStore('healthcertificatemanage',() => {
    //重写方法
    const importPerson = async (params) => {
        return await importPersonApi(params)
    }

    const uploadEntrust = async (params) => {
        return await uploadEntrustApi(params)
    }

    const medicalPersonInfo = async (params) => {
        return await medicalPersonInfoApi(params)
    }

    //暴露出的数据
    return{
        importPerson,
        uploadEntrust,
        medicalPersonInfo,
    }
})