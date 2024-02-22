import Request from '@/apis/request.js'
const baseUrl = 'http://localhost:8090/'

/* 该接口文件的封装顺序参考接口文档网址从上到下排列 */

// ？？？
export const queryUnit = (params) => {
  return Request.requestJson(Request.GET, baseUrl + '/query_people', params)
}

// ？？？
export const addPeople = (params) => {
  return Request.requestJson(Request.POST, baseUrl + '/add', params)
}
