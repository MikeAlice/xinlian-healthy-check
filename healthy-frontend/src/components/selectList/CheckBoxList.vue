<template>
  <el-checkbox class="all" v-model="checkAll" :indeterminate="isIndeterminate" @change="handleCheckAllChange">
    <span style="color: black">全选</span>
  </el-checkbox>
  <el-checkbox-group v-model="checkBoxData" class="group" @change="handleItemChange">
    <CheckBox v-for="(item, index) in listsData" :key="index" :label="item.code" :list-data="item"></CheckBox>
    <template v-if="listsData.length === 0">
      <el-empty class="empty" description="没有数据"></el-empty>
    </template>
  </el-checkbox-group>
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

const checkBoxData = ref([])
const checkAll = ref(false)
const isIndeterminate = ref(false)

function handleCheckAllChange() {
  // 取消中间态
  isIndeterminate.value = false
  if (!checkAll.value) {
    // 取消全选时清空数组
    checkBoxData.value = []
    return
  }
  // 全选时将所有复选框标识符加入数组
  checkBoxData.value = props.listsData.map((item) => item.code)
}
// 单个复选框状态变化时更新全选和半选状态
function handleItemChange() {
  const checkedCount = checkBoxData.value.length
  checkAll.value = checkedCount === props.listsData.length
  // 勾选超过0个且小于列表长度，设置中间态
  isIndeterminate.value = checkedCount > 0 && checkedCount < props.listsData.length
}
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
