import { defineStore } from 'pinia'
import { setRolePermissionApi, addRoleApi, deleteRoleApi, getRoleNameListApi, updateRoleApi, getRoleListApi, getRoleMenuPermissionApi } from '@/apis/systemmanagement/rolemanagement/index.js'
export const useRoleManagementStore = defineStore('rolemanagement', () => {
  // 将接口返回的数据存储到仓库中

  // 设置角色数据权限
  const setRolePermission = async (params) => {
    return await setRolePermissionApi(params)
  }

  // 新增角色
  const addRole = async (params) => {
    return await addRoleApi(params)
  }
  //删除角色
  const deleteRole = async (params) => {
    return await deleteRoleApi(params)
  }
  // 获取角色名称列表
  const getRoleNameList = async (params) => {
    return await getRoleNameListApi(params)
  }
  //修改角色
  const updateRole = async (params) => {
    return await updateRoleApi(params)
  }
  //获取角色列表(分页+条件)
  const getRoleList = async (params) => {
    return await getRoleListApi(params)
  }

  //获取角色菜单权限
  const getRoleMenuPermission = async (params) => {
    return await getRoleMenuPermissionApi(params)
  }

  // 将保存好的数据暴露出去，方便页面调用
  return {
    setRolePermission,
    addRole,
    deleteRole,
    getRoleNameList,
    updateRole,
    getRoleList,
    getRoleMenuPermission
  }
})
