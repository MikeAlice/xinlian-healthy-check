import { defineStore } from 'pinia'
import { queryCheckReport, queryPreviewReport } from '@/apis/reportcheck/index.js'

export const useCheckPeopleStore = defineStore('checkpeople', () => {
  const useCheckReport = async (params) => {
    return await queryCheckReport(params)
  }

  const usePreviewReport = async (params) => {
    return await queryPreviewReport(params)
  }

  return {
    useCheckReport,
    usePreviewReport
  }
})
