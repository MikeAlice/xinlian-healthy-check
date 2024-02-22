import Request from '@/apis/request.js'
const baseUrl = 'http://localhost:10100/api'

/**
 * 个人中心 
 * API接口服务 
 * zlw
 */

//基本信息
// 修改个人基础信息
export const modifyPersonalInfo = (params) => {
  return Request.requestJson(
    Request.POST,
    baseUrl + '/base-info/modify-personal-info',
    params
  )
}

//安全设置
// 修改邮箱
export const changeMail = (params) => {
  return Request.requestJson(
    Request.POST,
    baseUrl + '/security-setting/change-mail',
    params
  )
}

// 修改密码-1
export const changePassword = (params) => {
    return Request.requestJson(
      Request.POST,
      baseUrl + '/security-setting/change-password',
      params
    )
  }

  
  //修改手机号
export const changePhone = (params) => {
    return Request.requestJson(
      Request.POST,
      baseUrl + '/security-setting/change-phone',
      params
    )
  }


//密码身份验证
export const passwordAuthentication = (params) => {
    return Request.requestForm(
      Request.GET,
      baseUrl + '/security-setting/password-authentication',
      params
    )
  }

//获取邮箱验证码
export const queryEmailCode = (params) => {
    return Request.requestForm(
      Request.GET,
      baseUrl + '/security-setting/query-email-code',
      params
    )
  }

//获取短信验证码
export const querySmsCode = (params) => {
    return Request.requestForm(
      Request.GET,
      baseUrl + '/security-setting/query-sms-code',
      params
    )
  }

  

