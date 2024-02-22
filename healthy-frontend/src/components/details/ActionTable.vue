<template>
  <div>
    <el-table :data="tableData" height="250" border :cell-style="{ textAlign: 'center' }" :header-cell-style="{ 'text-align': 'center' }" style="width: 100%">
      <el-table-column prop="id" label="#" width="60" />
      <el-table-column prop="name" label="项目名称" />
      <el-table-column prop="result" label="原价" />
      <el-table-column prop="unit" label="折扣" />
      <el-table-column prop="reference" label="折扣价" />
      <el-table-column prop="prompt" label="操作">
        <template #default="scope">
          <el-button-group>
            <!-- <el-button size="small" @click="handleEdit(scope.$index, scope.row)">
                <el-icon><icon-view /></el-icon>
            </el-button>
            <el-button size="small" @click="handleEdit(scope.$index, scope.row)">
                <el-icon><icon-edit /></el-icon>
            </el-button> -->
            <el-button type="danger" size="small" @click="handleDelete(scope.$index, scope.row)">
                <el-icon><icon-delete /></el-icon>
                <span>删除</span>
            </el-button>
          </el-button-group>
        </template>
      </el-table-column>
    </el-table>

    <!-- 标签组 -->
    <div class="tag-group">
      <div>
        必检项折扣：
        <el-input placeholder="-" />
      </div>
      <div>
        选检项折扣：
        <el-input placeholder="-" />
      </div>
      <div>
        优惠价格：
        <el-input placeholder="-" />
      </div>
      <div>
        分组人数：
        <el-input placeholder="-" />
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

// 表格操作相关
// const handleEdit = function(index, row) {
//   console.log(index, row);
// }
const handleDelete = function(index, row) {
  console.log(index, row);
}
</script>

<style lang="scss" scoped>
.tag-group {
  background-color: var(--el-bg-color);
  padding: 15px;
  padding-bottom: 0;
  display: flex;
  justify-content: space-between;

  > div {
    font-weight: bold;

    .el-input {
      width: 120px;
    }
  }
}
</style>
