<template style="margin-top: 0px">
  <el-button type="primary" @click="exportFile">导出</el-button>
</template>

<script setup>
import { ref, onMounted } from 'vue'
import { read, utils, writeFileXLSX } from 'xlsx'

const props = defineProps({
  url: String,
  excelName: String
})

const rows = ref([])
/**
 * 挂载的时候加载数据
 */
onMounted(async () => {
  /* Download from https://sheetjs.com/pres.numbers */
  const f = await fetch(props.url)
  const ab = await f.arrayBuffer()
  /* parse workbook */
  const wb = read(ab)
  /* update data */
  rows.value = utils.sheet_to_json(wb.Sheets[wb.SheetNames[0]])
})

/* get state data and export to XLSX */
function exportFile() {
  const ws = utils.json_to_sheet(rows.value)
  const wb = utils.book_new()
  utils.book_append_sheet(wb, ws, 'Data')
  writeFileXLSX(wb, props.excelName + '.xlsx')
}
</script>

<style scoped>

</style>
