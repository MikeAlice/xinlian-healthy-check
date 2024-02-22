<template>
  <TestResult :testResult="tableData" />

  <Statistics :outsideData="outside" :insideData="inside" />

  <PersonInfo :personInfo="tableData" />

  <SortTable :tableData="tableData" />
</template>

<script setup>
import TestResult from '@/components/details/TestResult.vue'
import SortTable from '@/components/details/SortTable.vue'
import Statistics from '@/components/statistics/Statistics.vue'
import PersonInfo from '@/components/personinfo/PersonInfo.vue'

const outside = [
  { value: 1048, name: '未评价' },
  { value: 335, name: '已评价' }
]

const inside = [
  { value: 1548, name: '未登记' },
  { value: 775, name: '在体检' },
  { value: 679, name: '已总检' }
]

const tableData = [
  {
    id: '1',
    name: 'Tom',
    result: '正常',
    unit: '-',
    reference: '114514',
    prompt: '-',
    abnormal: false
  },
  {
    id: '2',
    name: 'Tom',
    result: '不正常',
    unit: '-',
    reference: '114514',
    prompt: '-',
    abnormal: true
  },
  {
    id: '3',
    name: 'Tom',
    result: '正常',
    unit: '-',
    reference: '114514',
    prompt: '-',
    abnormal: false
  },
  {
    id: '4',
    name: 'Tom',
    result: '正常',
    unit: '-',
    reference: '114514',
    prompt: '-',
    abnormal: false
  },
  {
    id: '5',
    name: 'Tom',
    result: '正常',
    unit: '-',
    reference: '114514',
    prompt: '-',
    abnormal: false
  },
  {
    id: '6',
    name: 'Tom',
    result: '不正常',
    unit: '-',
    reference: '114514',
    prompt: '-',
    abnormal: true
  }
]
</script>

<style lang="scss" scoped></style>
