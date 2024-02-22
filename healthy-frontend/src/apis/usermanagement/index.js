import Request from '@/apis/request.js'
// const baseUrl = 'http://47.115.229.44:10101'
// const baseUrl = '/sysmanager'
const baseUrl = ''

/**
 * 用户管理 
 * API接口服务 
 * zlw
 */

//用户管理
// 导入导出
export const exportFormDepartment = (params) => {
  return Request.requestForm(
    Request.GET,
    baseUrl + '/user-data/export-form-department',
    params
  )
}

// 导入用户数据
export const importUserData = (params) => {
  return Request.requestForm(
    Request.POST,
    baseUrl + '/user-data/import-user-data',
    params
  )
}

// 用户密码
// 更改密码接口
export const modifyPassword = (params) => {
    return Request.requestJson(
      Request.POST,
      baseUrl + '/user-data/modify-password',
      params
    )
  }

  
  //重置密码
export const resetPassword = (params) => {
    return Request.requestJson(
      Request.POST,
      baseUrl + '/user-data/reset-password',
      params
    )
  }


//新增用户
export const addUser = (params) => {
    return Request.requestJson(
      Request.POST,
      baseUrl + '/user-data/add-user',
      params
    )
  }

//批量删除用户
export const deleteUserList = (params) => {
    return Request.requestForm(
      Request.DELETE,
      baseUrl + '/user-data/delete-user-list',
      params
    )
  }

//修改用户信息
export const modifyUserInfo = (params) => {
    return Request.requestJson(
      Request.PUT,
      baseUrl + '/user-data/modify-user-info',
      params
    )
  }

//获取用户详情
export const queryUserData = (params) => {
    return Request.requestForm(
      Request.GET,
      baseUrl + '/user-data/query-user-data/' + params
    )
  }

//获取用户列表（条件 + 分页）
export const queryUserList = (params) => {
    return Request.requestForm(
      Request.GET,
      baseUrl + '/user-data/query-user-list',
      params
    )
  }

//获取用户名称列表（用于输入表单下拉列表框）
export const queryUserNameList = (params) => {
    return Request.requestJson(
      Request.GET,
      baseUrl + '/user-data/query-username-list',
      params
    )
  }

//设置用户状态
export const setUserStatus = (params) => {
    return Request.requestJson(
      Request.GET,
      baseUrl + '/user-data/set-user-status/' + params,
    )
  }

