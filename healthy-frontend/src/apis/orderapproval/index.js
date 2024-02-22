import Request from '@/apis/request.js'
const baseUrl = 'http://localhost:8090'

// 获取订单名称列表（条件+分页）
export const getOrderListApi = (params) => {
  return Request.requestForm(Request.GET, baseUrl + '/sales/query-order', params)
}
// 获取订单详情
export const getOrderDetailApi = (params) => {
  return Request.requestForm(Request.GET, baseUrl + '/sales/order/get-detail/{id}', params)
}
// 获取订单体检项目信息
export const getOrderItemInfoApi = (params) => {
  return Request.requestForm(Request.GET, baseUrl + '/sales/order/get-item', params)
}
// 获取订单体检人员信息
export const getOrderPersonInfoApi = (params) => {
  return Request.requestForm(Request.GET, baseUrl + '/sales/order/get-person', params)
}
// 新增订单
export const addOrderApi = (params) => {
  return Request.requestJson(Request.POST, baseUrl + '/sales/order/add', params)
}
// 修改订单
export const updateOrderApi = (params) => {
  return Request.requestJson(Request.PUT, baseUrl + '/sales/order/update', params)
}
// 删除订单
export const deleteOrderApi = (params) => {
  return Request.requestForm(Request.DELETE, baseUrl + '/sales/order/{id}', params)
}
// 订单确认
export const confirmOrderApi = (params) => {
  return Request.requestForm(Request.PUT, baseUrl + '/sales/order/confirm/{id}', params)
}
// 查看审批信息
export const approvalInfoApi = (params) => {
  return Request.requestForm(Request.GET, baseUrl + '/sales/order/get-approval/{orderId}', params)
}
// 生成导入模板
export const downloadPersonApi = (params) => {
  return Request.requestForm(Request.GET, baseUrl + '/sales/order/download-person/{id}', params)
}
// 导出人员信息
export const exportPersonApi = (params) => {
  return Request.requestForm(Request.GET, baseUrl + '/sales/order/export-person', params)
}
// 下载模板
export const downloadEntrustApi = (params) => {
  return Request.requestForm(Request.GET, baseUrl + '/sales/order/download-entrust/{id}', params)
}
// 附件预览
export const previewEntrustApi = (params) => {
  return Request.requestForm(Request.GET, baseUrl + '/sales/order/preview-entrust/{orderId}', params)
}

// 获取单位名称列表（用于输入表单下拉列表框）
export const getUnitNameListApi = (params) => {
  return Request.requestForm(Request.GET, baseUrl + '/sales/unit/get-name', params)
}
// 获取单位列表（条件+分页）
export const getUnitListApi = (params) => {
  return Request.requestForm(Request.GET, baseUrl + '/sales/unit/get-list', params)
}
// 获取单位详情
export const getUnitDetailApi = (params) => {
  return Request.requestForm(Request.GET, baseUrl + '/sales/unit/get-detail/{id}', params)
}
// 新增单位
export const addUnitApi = (params) => {
  return Request.requestJson(Request.POST, baseUrl + '/sales/unit/add', params)
}
// 修改单位
export const updateUnitApi = (params) => {
  return Request.requestJson(Request.PUT, baseUrl + '/sales/unit/update', params)
}
// 删除单位（支持批量删除）
export const deleteUnitApi = (params) => {
  return Request.requestJson(Request.DELETE, baseUrl + '/sales/unit/delete', params)
}
