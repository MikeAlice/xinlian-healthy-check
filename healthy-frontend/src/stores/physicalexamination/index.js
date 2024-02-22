import {defineStore} from 'pinia'
import{
modifyreference,
removereference,
queryall,
queryrules,
modifyrules,
getlistdetails,
addlistdetails,
addproject,
selectproject,
getproject,
addvalue,
getvalue,
newpackage,
deletepackage,
modifypackage,
deltbp,
updatetbp,
deletepackagerisis,
modifypackagerisis
}from '@/apis/physicalexamination/index.js'
export const usephysicalexaminationStore = defineStore('healthcertificatemanage',() => {
    const modifyreference = async (params) => {
        return await modifyreference(params)
    }
    const removereference = async (params) => {
        return await removereference(params)
    }
    const queryall = async (params) => {
        return await queryall(params)
    }
    const queryrules = async (params) => {
        return await queryrules(params)
    }
    const modifyrules = async (params) => {
        return await modifyrules(params)
    }
    const getlistdetails = async (params) => {
        return await getlistdetails(params)
    }
    const addlistdetails = async (params) => {
        return await addlistdetails(params)
    }
    const addproject = async (params) => {
        return await addproject(params)
    }
    const selectproject = async (params) => {
        return await selectproject(params)
    }
    const getproject = async (params) => {
        return await getproject(params)
    }
    const addvalue = async (params) => {
        return await addvalue(params)
    }
    const getvalue = async (params) => {
        return await getvalue(params)
    }
    const newpackage = async (params) => {
        return await newpackage(params)
    }
    const deletepackage = async (params) => {
        return await deletepackage(params)
    }
    const modifypackage = async (params) => {
        return await downloadhelthcertidetail(params)
    }
    const deltbp = async (params) => {
        return await deltbp(params)
    }
    const updatetbp = async (params) => {
        return await updatetbp(params)
    }
    const deletepackagerisis = async (params) => {
        return await deletepackagerisis(params)
    }
    const modifypackagerisis = async (params) => {
        return await modifypackagerisis(params)
    }

    return {
    modifyreference,
    removereference,
    queryall,
    queryrules,
    modifyrules,
    getlistdetails,
    addlistdetails,
    addproject,
    selectproject,
    getproject,
    addvalue,
    getvalue,
    newpackage,
    deletepackage,
    modifypackage,
    deltbp,
    updatetbp,
    deletepackagerisis,
    modifypackagerisis
    }
})
