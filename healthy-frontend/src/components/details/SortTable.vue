<template>
  <div>
    <el-table :data="tableData" height="250" border :cell-style="{ textAlign: 'center' }" :header-cell-style="{ 'text-align': 'center' }" style="width: 100%">
      <el-table-column prop="id" label="#" width="60" />
      <el-table-column prop="name" label="项目名称" />
      <el-table-column prop="result" label="原价" />
      <el-table-column prop="unit" label="折扣" />
      <el-table-column prop="reference" label="折扣价" />
      <el-table-column prop="prompt" label="排序" />
    </el-table>

    <!-- 标签组 -->
    <div class="tag-group">
      <div>
        必检项折扣：
        <span>{{ !tableData.name ? '-' : tableData.name }}</span>
      </div>
      <div>
        选检项折扣：
        <span>{{ !tableData.name ? '-' : tableData.name }}</span>
      </div>
      <div>
        优惠价格：
        <span>{{ !tableData.name ? '-' : tableData.name }}</span>
      </div>
      <div>
        分组人数：
        <span>{{ !tableData.name ? '-' : tableData.name }}</span>
      </div>
      <div>
        分组小计：
        <span>{{ !tableData.name ? '-' : tableData.name }}</span>
      </div>
    </div>

  </div>
</template>

<script setup>
import { defineProps } from 'vue'

const props = defineProps({
  tableData: {
    type: Array,
    default: () => []
  }
})
</script>

<style lang="scss" scoped>
.tag-group {
  background-color: var(--el-bg-color);
  padding: 15px;
  padding-bottom: 0;
  display: flex;
  justify-content: space-between;

  >div {
    font-weight: bold;
  }
}
</style>
