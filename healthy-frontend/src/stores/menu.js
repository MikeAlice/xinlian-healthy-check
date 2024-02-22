import { defineStore } from 'pinia'
import { basicdata } from './menus/basicdata.js'
import { marketingmanagement } from './menus/marketingmanagement.js'
import { medicalregistration } from './menus/medicalregistration.js'
import { resultsinput } from './menus/resultsinput.js'
import { masterinspection } from './menus/masterinspection.js'
import { inspectionstatistics } from './menus/inspectionstatistics.js'
import { configurationmanagement } from './menus/configurationmanagement.js'
import { systemconfiguration } from './menus/systemconfiguration.js'
import { dataonline } from './menus/dataonline.js'
import { personalcentre } from './menus/personalcentre.js'
export const useMenuStore = defineStore('menu', () => {
  const judegeRouter = (path) => {
    // 使用 split 方法分割路径
    const parts = path.split('/')
    // 仅保留前两个有效路径部分
    // 注意：因为路径以 / 开头，所以第一个元素是空字符串，有效路径从索引 1 开始
    const desiredParts = parts.slice(1, 2) // 使用 slice 获取第一个元素
    // 重新组合所需部分，确保结果以 / 开头
    const newPath = '/' + desiredParts.join('/')
    return newPath
  }
  return {
    basicdata,
    marketingmanagement,
    medicalregistration,
    resultsinput,
    masterinspection,
    inspectionstatistics,
    configurationmanagement,
    systemconfiguration,
    dataonline,
    personalcentre,
    judegeRouter
  }
})
