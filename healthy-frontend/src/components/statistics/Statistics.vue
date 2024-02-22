<template>
  <!-- 统计 -->
  <div style="background-color: white; padding: 15px; margin-top: 10px">
    <div id="echars" style="height: 200px"></div>
  </div>
</template>

<script setup>
import { defineProps } from 'vue'
import * as echarts from 'echarts'
import { onMounted } from 'vue'

const props = defineProps({
  // 外围数据
  outsideData: {
    type: Array,
    default: () => []
  },
  // 第二层数据
  insideData: {
    type: Array,
    default: () => []
  }
})

onMounted(() => {
  var myChart = echarts.init(document.getElementById('echars'))

  myChart.setOption({
    tooltip: {
      trigger: 'item',
      formatter: '{a} <br/>{b}: {c} ({d}%)'
    },
    legend: {
      data: ['未评价', '已评价', '未登记', '在体检', '已总检'],
      orient: 'vertical',
      left: 'left',
      top: 'top'
    },
    series: [
      {
        name: '体检完成率',
        type: 'pie',
        selectedMode: 'single',
        radius: [0, '55%'],
        label: {
          show: true,
          position: 'inner',
          fontSize: 14
        },
        labelLine: {
          show: false
        },
        data: props.insideData
      },
      {
        name: '评价完成率',
        type: 'pie',
        radius: ['70%', '90%'],
        labelLine: {
          length: 30
        },
        label: {
          show: true
        },
        data: props.outsideData
      }
    ]
  })
})
</script>

<style lang="scss" scoped></style>
