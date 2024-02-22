import { defineStore } from 'pinia'
import { ref } from 'vue'
import { exportFormDepartment, importUserData,modifyPassword,resetPassword,addUser,
deleteUserList,modifyUserInfo,queryUserData,queryUserList,queryUserNameList,setUserStatus } from '@/apis/usermanagement/index.js'
export const useUserManagementStores = defineStore('userManagementStores', () => {
/**
 * 用户管理-j1
 * stores
 * zlw
 * @param {} params 
 * @returns 
 */
  // 重写方法
  const exportFormDepartmentStore = async (params) => {
    return await exportFormDepartment(params)
  }
  const importUserDataStore = async (params) => {
    return await importUserData(params)
  }
  const modifyPasswordStore = async (params) => {
    return await modifyPassword(params)
  }
  const resetPasswordStore = async (params) => {
    return await resetPassword(params)
  }
  const addUserStore = async (params) => {
    return await addUser(params)
  }
  const deleteUserListStore = async (params) => {
    return await deleteUserList(params)
  }
  const modifyUserInfoStore = async (params) => {
    return await modifyUserInfo(params)
  }
  const queryUserDataStore = async (params) => {
    return await queryUserData(params)
  }
  const queryUserListStore = async (params) => {
    return await queryUserList(params)
  }
  const queryUserNameListStore = async (params) => {
    return await queryUserNameList(params)
  }
  const setUserStatusStore = async (params) => {
    return await setUserStatus(params)
  }

  // 暴露出的数据
  return {
    exportFormDepartmentStore,
    importUserDataStore,
    modifyPasswordStore,
    resetPasswordStore,
    addUserStore,
    deleteUserListStore,
    modifyUserInfoStore,
    queryUserDataStore,
    queryUserListStore,
    queryUserNameListStore,
    setUserStatusStore
  }
})
