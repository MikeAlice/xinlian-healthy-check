import { defineStore } from 'pinia'
import { ref } from 'vue'
import {
  queryDictnameList,
  queryJobnameList,
  queryPackageProlist,
  queryPackagePronamelist,
  queryPlannameList,
  queryPlanProlist,
  querySelectionnameList,
  queryTermnameList,
  queryTypeTree,
  queryUesrnameList
} from '@/apis/public/index.js'

export const usePublicStore = defineStore('public', () => {
  // 重写方法
  //获取字典数据名称列表（用于输入表单下拉列表）
  const getDictnameList = async (params) => {
    return await queryDictnameList(params)
  }
  //获取工种名称列表（分页＋条件）
  const getJobnameList = async (params) => {
    return await queryJobnameList(params)
  }
  //获取组合项目列表（条件＋分页）
  const getPackageProlist = async (params) => {
    return await queryPackageProlist(params)
  }
  //获取组合项目名称列表（用于输入表单下拉列表）
  const getPackagePronamelist = async (params) => {
    return await queryPackagePronamelist(params)
  }
  //获取套餐名称列表（条件+分页）
  const getPlannameList = async (params) => {
    return await queryPlannameList(params)
  }
  //获取套餐组合项目列表
  const getPlanProlist = async (params) => {
    return await queryPlanProlist(params)
  }
  //科室名称列表
  const getSelectionnameList = async (params) => {
    return await querySelectionnameList(params)
  }
  const getTermnameList = async (params) => {
    return await queryTermnameList(params)
  }
  const getTypeTree = async (params) => {
    return await queryTypeTree(params)
  }
  const getUesrnameList = async (params) => {
    return await queryUesrnameList(params)
  }

  // 暴露出的数据
  return {
    getDictnameList,
    getJobnameList,
    getPackageProlist,
    getPackagePronamelist,
    getPlannameList,
    getPlanProlist,
    getSelectionnameList,
    getTermnameList,
    getTypeTree,
    getUesrnameList
  }
})
