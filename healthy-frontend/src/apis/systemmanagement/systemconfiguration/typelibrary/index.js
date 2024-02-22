// 类型库api  等待后端修改
import Request from '@/apis/request.js'
const baseUrl = ''

// 添加类型库
export const addTypeApi = (params) => {
  return Request.requestJson(Request.POST, baseUrl + '/j3-typeLib/addType', params)
}

// 修改类型库
export const updateTypeApi = (params) => {
  return Request.requestForm(Request.PUT, baseUrl + '/j3-typeLib/updateType', params)
}
