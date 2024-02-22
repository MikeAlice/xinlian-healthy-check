<template>
  <!-- 人员信息 -->
  <div>
    <el-table :data="personInfo" border :cell-style="{ textAlign: 'center' }" :header-cell-style="{ 'text-align': 'center' }" style="width: 100%; margin-top: 10px">
      <el-table-column type="selection" width="60" />
      <el-table-column prop="name" label="姓名" />
      <el-table-column prop="result" label="性别" />
      <el-table-column prop="reference" label="证件号码" />
      <el-table-column prop="unit" label="年龄" />
      <el-table-column prop="prompt" label="操作">
        <template #default="scope">
          <el-button-group>
            <el-button size="small" @click="handleEdit(scope.$index, scope.row)">
              <el-icon><icon-view /></el-icon>
            </el-button>
            <el-button size="small" @click="handleEdit(scope.$index, scope.row)">
              <el-icon><icon-edit /></el-icon>
            </el-button>
            <el-button type="danger" size="small" @click="handleDelete(scope.$index, scope.row)">
              <el-icon><icon-delete /></el-icon>
            </el-button>
          </el-button-group>
        </template>
      </el-table-column>
    </el-table>
  </div>
</template>

<script setup>
import { defineProps } from 'vue'
import { ref } from 'vue'

// 分页相关
const currentPage = ref(1)
const pageSize = ref(10)

const props = defineProps({
  personInfo: {
    type: Array,
    default: () => []
  }
})

// 表格操作相关
const handleEdit = function(index, row) {
  console.log(index, row);
}
const handleDelete = function(index, row) {
  console.log(index, row);
}
</script>

<style lang="scss" scoped></style>
