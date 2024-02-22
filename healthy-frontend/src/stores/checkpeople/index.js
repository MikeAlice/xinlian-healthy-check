import { defineStore } from 'pinia'
import { queryUnit, addPeople } from '@/apis/checkpople/index.js'

export const useCheckPeopleStore = defineStore('checkpeople', () => {
  const useGetUnit = async (params) => {
    return await queryUnit(params)
  }

  const useAddPeople = async (params) => {
    return await addPeople(params)
  }

  return {
    useGetUnit,
    useAddPeople
  }
})
