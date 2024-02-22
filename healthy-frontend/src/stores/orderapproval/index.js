import { defineStore } from 'pinia'
import { ref } from 'vue'
import { getOrderListApi, getOrderDetailApi, getOrderItemInfoApi, addOrderApi, updateOrderApi, deleteOrderApi, confirmOrderApi, approvalInfoApi, downloadPersonApi, exportPersonApi, downloadEntrustApi, previewEntrustApi } from '@/apis/orderapproval/index.js'
import { getOrderPersonInfoApi } from '../../apis/orderapproval'
import { getUnitListApi, getUnitNameListApi, getUnitDetailApi, addUnitApi, updateUnitApi, deleteUnitApi } from '../../apis/orderapproval'
export const useOrderApprovalStore = defineStore('OrderApproval', () => {
  // 重写方法
  const getOrderList = async (params) => {
    return await getOrderDetailApi(params)
  }
  const getOrderDetail = async (params) => {
    return await getOrderDetailApi(params)
  }
  const getOrderItemInfo = async (params) => {
    return await getOrderItemInfoApi(params)
  }
  const getOrderPersonInfo = async (params) => {
    return await getOrderPersonInfoApi(params)
  }
  const addOrder = async (params) => {
    return await addOrderApi(params)
  }
  const updateOrder = async (params) => {
    return await updateOrderApi(params)
  }
  const deleteOrder = async (params) => {
    return await deleteOrderApi(params)
  }
  const confirmOrder = async (params) => {
    return await confirmOrderApi(params)
  }
  const approvalInfo = async (params) => {
    return await approvalInfoApi(params)
  }
  const downloadPerson = async (params) => {
    return await downloadPersonApi(params)
  }
  const exportPerson = async (params) => {
    return await exportPersonApi(params)
  }
  const downloadEntrust = async (params) => {
    return await downloadEntrustApi(params)
  }
  const previewEntrust = async (params) => {
    return await previewEntrustApi(params)
  }

  const getUnitList = async (params) => {
    return await getUnitListApi(params)
  }
  const getUnitNameList = async (params) => {
    return await getUnitNameListApi(params)
  }
  const getUnitDetail = async (params) => {
    return await getUnitDetailApi(params)
  }
  const addUnit = async (params) => {
    return await addUnitApi(params)
  }
  const updateUnit = async (params) => {
    return await updateUnitApi(params)
  }
  const deleteUnit = async (params) => {
    return await deleteUnitApi(params)
  }

  // 暴露出的数据
  return {
    getqueryOrder,
    getMedicalPersonInfo
  }
})
