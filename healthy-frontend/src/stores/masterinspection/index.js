import { defineStore } from 'pinia'
import { ref } from 'vue'
import {
  getMedicalPersonNameApi,
  getMedicalPersonDetailsApi,
  ignoreProjectApi,
  downloadReportApi,
  reviewApi,
  addReviewItemApi,
  reviewPdfApi,
  getReviewItemsListApi,
  deleteReviewItemApi,
  updateReviewItemApi,
  getInquiryDetailsApi,
  getMedicalExaminationResultsApi,
  getPositiveResultsListApi,
  previewReportApi,
  storageInspectorReportApi,
  getAddedProjectConclusionsListApi,
  getMedicalExaminationResultsListApi
} from '@/apis/masterinspection/index.js'
export const useMasterInspectionStore = defineStore('masterinspection', () => {
  // 将接口返回的数据存储到仓库中

  // 获取体检人员名称列表
  const getMedicalPersonName = async (params) => {
    return await getMedicalPersonNameApi(params)
  }

  // 获取体检人员详情
  const getMedicalPersonDetails = async (params) => {
    return await getMedicalPersonDetailsApi(params)
  }
  //忽略指定项目
  const ignoreProject = async (params) => {
    return await ignoreProjectApi(params)
  }
  // TODO下载个人报告word
  const downloadReport = async (params) => {
    return await downloadReportApi(params)
  }
  //审查项目
  const review = async (params) => {
    return await reviewApi(params)
  }
  //添加复查项目
  const addReviewItem = async (params) => {
    return await addReviewItemApi(params)
  }

  //复查页面预览
  const reviewPdf = async (params) => {
    return await reviewPdfApi(params)
  }
  //获取复查项目列表
  const getReviewItemsList = async (params) => {
    return await getReviewItemsListApi(params)
  }
  //复查（删除复查项目）
  const deleteReviewItem = async (params) => {
    return await deleteReviewItemApi(params)
  }
  //复查（修改复查项目）
  const updateReviewItem = async (params) => {
    return await updateReviewItemApi(params)
  }
  //获取问诊明细
  const getInquiryDetails = async (params) => {
    return await getInquiryDetailsApi(params)
  }
  //获取体检项目结果明细
  const getMedicalExaminationResults = async (params) => {
    return await getMedicalExaminationResultsApi(params)
  }
  //获取阳性结果列表
  const getPositiveResultsList = async (params) => {
    return await getPositiveResultsListApi(params)
  }
  //报告预览
  const previewReport = async (params) => {
    return await previewReportApi(params)
  }
  //保存总检报告
  const getAddedProjectConclusionsList = async (params) => {
    return await getAddedProjectConclusionsListApi(params)
  }
  //获取添加项目结论列表
  const getMedicalExaminationResultsList = async (params) => {
    return await getMedicalExaminationResultsListApi(params)
  }
  //获取体检项目结果明细
  const storageInspectorReport = async (params) => {
    return await storageInspectorReportApi(params)
  }
  // 将保存好的数据暴露出去，方便页面调用
  return {
    getMedicalPersonName,
    getMedicalPersonDetails,
    ignoreProject,
    downloadReport,
    review,
    addReviewItem,
    reviewPdf,
    getReviewItemsList,
    deleteReviewItem,
    updateReviewItem,
    getInquiryDetails,
    getMedicalExaminationResults,
    getPositiveResultsList,
    previewReport,
    storageInspectorReport,
    getAddedProjectConclusionsList,
    getMedicalExaminationResultsList
  }
})
