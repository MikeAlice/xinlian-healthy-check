import Request from '@/apis/request.js'
const baseUrl = ''

// 修改基础数据中指定项目的指定参考值
export const modifyreference = (params) => {
    return Request.requestJson(Request.PUT, baseUrl + '/base/modifyReference', params)
  }
  // 删除基础数据中指定项目的指定参考值
  export const removereference = (params) => {
    return Request.requestJson(Request.DELETE, baseUrl + '/base/removereRerence', params)
  }
//   基础项目-配置指定项目-规则-获取指定规则列表（获取一个）
  export const queryall = (params) => {
    return Request.requestForm(Request.GET, baseUrl + '/base-data-project/rules/query-all', params)
  }
//   基础项目-配置指定项目-规则-获取指定规则列表（获取所有）
  export const queryrules = (params) => {
    return Request.requestForm(Request.GET, baseUrl + '/base-data-project/rules/query-rules', params)
  }
//   基础项目-配置指定项目-规则-修改指定规则列表
  export const modifyrules = (params) => {
    return Request.requestJson(Request.PUT, baseUrl + '/base-data-project/rules/modify-rules', params)
  }
//   获取指定项目危机值列表详情
  export const getlistdetails = (params) => {
    return Request.requestForm(Request.GET, baseUrl + '/base-data-project/database', params)
  }
//   新增指定项目危机值
  export const addlistdetails = (params) => {
    return Request.requestJson(Request.POST, baseUrl + '/base-data-project/database', params)
  }
// 基础项目-新增项目
  export const addproject = (params) => {
    return Request.requestJson(Request.POST, baseUrl + '/base-data-project/commen/baseproject/add -baseproject', params)
  }

  export const selectproject = (params) => {
    return Request.requestForm(Request.GET, baseUrl + '/base-data-project/commen/baseproject/select-baseproject', params)
  }
// 基础数据-获取项目列表
export const getproject = (params) => {
    return Request.requestForm(Request.GET, baseUrl + '/base-data-project/commen/baseproject/select-baseprojectlist', params)
  }
//   新增指定项目参考值
export const addvalue = (params) => {
    return Request.requestJson(Request.POST, baseUrl + '/base-data-project/commen/relationProject/AddReferenceValue', params)
  }
// 获取指定项目指定参考值详情
export const getvalue = (params) => {
    return Request.requestForm(Request.GET, baseUrl + '/base-data-project/commen/relationProject/QueryReferenceValue', params)
  }
//   基础项目-新增套餐
export const newpackage = (params) => {
    return Request.requestJson(Request.POST, baseUrl + '/base-data-project/combo/add-pack', params)
  } 
//   基础项目-删除套餐
export const deletepackage = (params) => {
    return Request.requestJson(Request.DELETE, baseUrl + '/base-data-project/combo/del-pack', params)
  } 
//   基础项目-修改套餐
export const modifypackage = (params) => {
    return Request.requestJson(Request.POST, baseUrl + '/base-data-project/combo/update-pack', params)
  } 
// 体检套餐-获取职业禁忌证术语列表
  export const getlist = (params) => {
    return Request.requestForm(Request.GET, baseUrl + '/base-data-project/basis/query-contraindications', params)
  } 
//   体检套餐-获取套餐名称列表
  export const getpackagelist = (params) => {
    return Request.requestForm(Request.GET, baseUrl + '/base-data-project/basis/query-package', params)
  } 
//   基础项目-删除项目
export const deltbp = (params) => {
    return Request.requestJson(Request.DELETE, baseUrl + '/base-data-project/combo/del-TBP', params)
  } 
  // 修改指定项目
  export const updatetbp = (params) => {
    return Request.requestJson(Request.POSTE, baseUrl + '/base-data-project/combo/update-TBP', params)
  } 
//   基础项目-配置指定项目-危机值-删除指定项目指定危机值
  export const deletepackagerisis = (params) => {
    return Request.requestJson(Request.DELETE, baseUrl + '/base-data-project/critical/query-delete-critical', params)
  } 
  //   基础项目-配置指定项目-危机值-修改指定项目指定危机值
  export const modifypackagerisis = (params) => {
    return Request.requestJson(Request.PUT, baseUrl + '/base-data-project/critical', params)
  } 
  