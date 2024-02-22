// 角色管理api
import Request from '@/apis/request.js'
const baseUrl = ''

// 设置角色数据权限
export const setRolePermissionApi = (params) => {
  return Request.requestJson(Request.POST, baseUrl + '/role/t-role/RolePermission', params)
}

// 新增角色
export const addRoleApi = (params) => {
  return Request.requestJson(Request.POST, baseUrl + '/role/t-role/add-role', params)
}

// 删除角色
export const deleteRoleApi = (params) => {
  return Request.requestJson(Request.PUT, baseUrl + '/role/t-role/delete-role', params)
}

// 获取角色名称列表
export const getRoleNameListApi = (params) => {
  return Request.requestJson(Request.GET, baseUrl + '/role/t-role/get-role-names', params)
}

// 修改角色
export const updateRoleApi = (params) => {
  return Request.requestForm(Request.POST, baseUrl + '/healthy-c7-common/update-personal-review', params)
}

// 获取角色列表(分页+条件)
export const getRoleListApi = (params) => {
  return Request.requestForm(Request.GET, baseUrl + '/role/t-role/query-by-condition', params)
}

// 获取角色菜单权限
export const getRoleMenuPermissionApi = (params) => {
  return Request.requestJson(Request.GET, baseUrl + '/role/t-role-permission/permission', params)
}
