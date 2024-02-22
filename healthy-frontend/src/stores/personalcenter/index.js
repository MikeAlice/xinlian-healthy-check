import { defineStore } from 'pinia'
import { ref } from 'vue'
import { modifyPersonalInfo, changeMail,changePassword,changePhone,passwordAuthentication,queryEmailCode,querySmsCode } from '@/apis/personalcenter/index.js'
export const usePersonalCenterStores = defineStore('personalCenterStores', () => {
/**
 * 个人中心-j1
 * stores
 * zlw
 * @param {} params 
 * @returns 
 */
  // 重写方法
  const modifyPersonalInfoStore = async (params) => {
    return await modifyPersonalInfo(params)
  }
  const changeMailStore = async (params) => {
    return await changeMail(params)
  }
  const changePasswordStore = async (params) => {
    return await changePassword(params)
  }
  const changePhoneStore = async (params) => {
    return await changePhone(params)
  }
  const passwordAuthenticationStore = async (params) => {
    return await passwordAuthentication(params)
  }
  const queryEmailCodeStore = async (params) => {
    return await queryEmailCode(params)
  }
  const querySmsCodeStore = async (params) => {
    return await querySmsCode(params)
  }
  // 暴露出的数据
  return {
    modifyPersonalInfoStore,
    changeMailStore,
    changePasswordStore,
    changePhoneStore,
    passwordAuthenticationStore,
    queryEmailCodeStore,
    querySmsCodeStore
  }
})
