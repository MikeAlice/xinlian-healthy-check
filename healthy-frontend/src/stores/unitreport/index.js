import { defineStore } from 'pinia'

import { queryMedExamUnitOrder, queryUnitReport, queryUnit, queryPhysicalExaminationPersonnel, queryReviewPersonnel, queryReviewResults, reportCheck } from '@/apis/unitreport/index.js'

export const useUnitreportStore = defineStore('unitreport', () => {
  const useMedExamUnitOrder = async (params) => {
    return await queryMedExamUnitOrder(params)
  }

  const useUnitReport = async (params) => {
    return await queryUnitReport(params)
  }
  const useUnit = async (params) => {
    return await queryUnit(params)
  }
  const usePhysicalExaminationPersonnel = async (params) => {
    return await queryPhysicalExaminationPersonnel(params)
  }
  const useReviewPersonnel = async (params) => {
    return await queryReviewPersonnel(params)
  }
  const useReviewResults = async (params) => {
    return await queryReviewResults(params)
  }
  const useReportCheck = async (params) => {
    return await reportCheck(params)
  }

  return {
    useMedExamUnitOrder,
    useUnitReport,
    useUnit,
    usePhysicalExaminationPersonnel,
    useReviewPersonnel,
    useReviewResults,
    useReportCheck
  }
})
