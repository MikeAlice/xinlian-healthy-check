<template>
  <div>
    <div>示例为：'https://sheetjs.com/pres.numbers'</div>
    <Excel excelName="test" url="https://sheetjs.com/pres.numbers"></Excel>
  </div>
</template>

<script setup>
import Excel from '@/components/excel/Excel.vue'
</script>

<style scoped>
.el-table {
  width: 100%;
}

.el-button {
  margin-top: 5px;
}
</style>
