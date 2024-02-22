<template>
  <el-checkbox class="checkBox">
    <Label :code="listData.code" :date="listData.date" :company="listData.company" :use-system="listData.icon[0]"
      :use-report="listData.icon[1]" :use-inspect="listData.icon[2]" :use-print="listData.icon[3]"
      :use-together="listData.icon[4]"></Label>
  </el-checkbox>
</template>

<script setup>
const props = defineProps({
  listData: {
    type: Object,
    required: true
  }
})
</script>

<style scoped lang="scss">
.checkBox {
  justify-content: space-between;
  width: 100%;
  margin-bottom: 10px;
  margin-right: 0px;
  border-bottom: 1px solid gray;
  height: auto;
}
</style>
