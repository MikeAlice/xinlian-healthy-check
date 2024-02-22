import { defineStore } from 'pinia'
import { ref } from 'vue'
import {
  addDepartRes,
  addRPProCheck,
  modifywaiveCheck,
  queryList,
  clAbanProj,
  queryBasicInfoMation,
  queryLifeHistory,
  queryPastMedicalHistory,
  queryProfessionalHistory,
  Interro,
  barcod,
  report,
  baseProject,
  queryPerson,
  uploadxxx,
  info
} from '@/apis/resultentry/index.js'
export const useResultentryStores = defineStore('resultentryStores', () => {
  /**
   * 结果录入-c6
   * stores
   * zlw
   * @param {} params
   * @returns
   */
  // 重写方法
  const addDepartResStore = async (params) => {
    return await addDepartRes(params)
  }
  const addRPProCheckStore = async (params) => {
    return await addRPProCheck(params)
  }
  const modifywaiveCheckdStore = async (params) => {
    return await modifywaiveCheck(params)
  }
  const queryListStore = async (params) => {
    return await queryList(params)
  }
  const clAbanProjStore = async (params) => {
    return await clAbanProj(params)
  }
  const queryBasicInfoMationStore = async (params) => {
    return await queryBasicInfoMation(params)
  }
  const queryLifeHistoryStore = async (params) => {
    return await queryLifeHistory(params)
  }
  const queryPastMedicalHistoryStore = async (params) => {
    return await queryPastMedicalHistory(params)
  }
  const queryProfessionalHistoryStore = async (params) => {
    return await queryProfessionalHistory(params)
  }
  const InterroStore = async (params) => {
    return await Interro(params)
  }
  const barcodStore = async (params) => {
    return await barcod(params)
  }

  const reportStore = async (params) => {
    return await report(params)
  }
  const baseProjectStore = async (params) => {
    return await baseProject(params)
  }
  const queryPersonStore = async (params) => {
    return await queryPerson(params)
  }
  const uploadxxxStore = async (params) => {
    return await uploadxxx(params)
  }
  const infoStore = async (params) => {
    return await info(params)
  }

  // 暴露出的数据
  return {
    addDepartResStore,
    addRPProCheckStore,
    modifywaiveCheckdStore,
    queryListStore,
    clAbanProjStore,
    queryBasicInfoMationStore,
    queryLifeHistoryStore,
    queryPastMedicalHistoryStore,
    queryProfessionalHistoryStore,
    InterroStore,
    barcodStore,
    reportStore,
    baseProjectStore,
    queryPersonStore,
    uploadxxxStore,
    infoStore
  }
})
