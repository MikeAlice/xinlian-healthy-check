<template>
  <el-radio-group v-model="radioData" class="group">
    <Radio v-for="(item, index) in listsData" :key="index" :label="index" :list-data="item"></Radio>
    <template v-if="listsData.length === 0">
      <el-empty class="empty" description="没有数据"></el-empty>
    </template>
  </el-radio-group>
</template>

<script setup>
import { ref } from 'vue'

const props = defineProps({
  listsData: {
    type: Array,
    required: true,
    default: () => []
  }
})

const radioData = ref('1')
</script>

<style scoped>
.group {
  display: block;
}

.empty {
  min-width: auto;
  min-height: auto;
}
</style>
