import { defineStore } from 'pinia'
import {
  queryDangerousInfo,
  queryAddConclusionList,
  querySaveInfoInspect,
  queryPreviewReport,
  queryTermsList,
  queryPositiveResultsList,
  queryPositiveResultsDownload,
  queryExaminationItemResult,
  queryEvaluateDetails,
  modifyEvaluateDetails,
  queryEvaluatePDF,
  queryReviewItemList,
  modifyReviewItems,
  deleteReview,
  queryReviewReport,
  addReview,
  updatePersonalReview,
  downloadPersonalReport,
  ignoreAssignedProject,
  queryPersonDetails,
  queryExaminerNameList
} from '@/apis/DoctorInspection/index.js'

export const useDoctorInspectionStore = defineStore('DoctorInspection', () => {
  // 重写方法(顺序参考同名api文件的方法自上而下一一对应)
  // 获取体检项目结果明细（后端缺页面，接口只有危险值提示的参数）  1
  const getDangerousInfo = async (params) => {
    return await queryDangerousInfo(params)
  }
  // 获取添加项目结论列表（分页）  2
  const getAddConclusionList = async (params) => {
    return await queryAddConclusionList(params)
  }
  //保存总检信息  3
  const getSaveInfoInspect = async (params) => {
    return await querySaveInfoInspect(params)
  }
  // 报告预览  4
  const getPreviewReport = async (params) => {
    return await queryPreviewReport(params)
  }
  // 获取术语名称列表(条件+分页)(公共)  5
  const getTermsList = async (params) => {
    return await queryTermsList(params)
  }
  // 获取阳性结果列表(分页+条件)  6
  const getPositiveResultsList = async (params) => {
    return await queryPositiveResultsList(params)
  }
  // 获取阳性结果列表(excel导出执行)  7
  const getPositiveResultsDownload = async (params) => {
    return await queryPositiveResultsDownload(params)
  }
  // 获取体检项目结果明细  8
  const getExaminationItemResult = async (params) => {
    return await queryExaminationItemResult(params)
  }
  //获取问诊明细  9
  const getEvaluateDetails = async (params) => {
    return await queryEvaluateDetails(params)
  }
  // 获取问诊明细（修改） 10
  const putEvaluateDetails = async (params) => {
    return await modifyEvaluateDetails(params)
  }
  // 获取问诊明细（pdf） 11
  const getEvaluatePDF = async (params) => {
    return await queryEvaluatePDF(params)
  }
  //复查(获取复查项目列表)  12
  const getReviewItemList = async (params) => {
    return await queryReviewItemList(params)
  }
  //复查(修改复查项目)  13
  const postReviewItems = async (params) => {
    return await modifyReviewItems(params)
  }
  //复查(删除复查项目)  14
  const deleteReviewItems = async (params) => {
    return await deleteReview(params)
  }
  //复查(复查报告查看)  15
  const getReviewReport = async (params) => {
    return await queryReviewReport(params)
  }
  //复查(新增复查项目)  16
  const addReviewItems = async (params) => {
    return await addReview(params)
  }
  // 审查  17
  const postPersonalReview = async (params) => {
    return await updatePersonalReview(params)
  }
  // 下载个人报告word  18
  const getDownloadPersonalReport = async (params) => {
    return await downloadPersonalReport(params)
  }
  //忽略指定基础项目  19
  const postAssignedProject = async (params) => {
    return await ignoreAssignedProject(params)
  }
  // 获取人员详情  20
  const getPersonDetails = async (params) => {
    return await queryPersonDetails(params)
  }
  //获取体检人员名称列表(条件+分页)  21
  const getExaminerNameList = async (params) => {
    return await queryExaminerNameList(params)
  }

  // 暴露出数据
  return {
    getDangerousInfo,
    getAddConclusionList,
    getSaveInfoInspect,
    getPreviewReport,
    getTermsList,
    getPositiveResultsList,
    getPositiveResultsDownload,
    getExaminationItemResult,
    getEvaluateDetails,
    putEvaluateDetails,
    getEvaluatePDF,
    getReviewItemList,
    postReviewItems,
    deleteReviewItems,
    getReviewReport,
    addReviewItems,
    postPersonalReview,
    getDownloadPersonalReport,
    postAssignedProject,
    getPersonDetails,
    getExaminerNameList
  }
})
