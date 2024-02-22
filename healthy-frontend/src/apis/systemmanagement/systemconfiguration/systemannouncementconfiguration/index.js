// 系统公告配置api
import Request from '@/apis/request.js'
const baseUrl = ''

// 新增公告
export const addSystemNoticeApi = (params) => {
  return Request.requestForm(Request.POST, baseUrl + '/j3-sysConfig/addSystemNotice', params)
}

// 修改公告
export const updateSystemNoticeApi = (params) => {
  return Request.requestForm(Request.PUT, baseUrl + '/j3-sysConfig/modifySystemNotice', params)
}

// 获取公告
export const querySystemNoticeApi = (params) => {
  return Request.requestJson(Request.POST, baseUrl + '/j3-sysConfig/querySystemNotice', params)
}
