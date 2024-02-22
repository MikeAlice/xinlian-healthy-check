<template>
  <div>
    <el-scrollbar height="300px">
      <div class="box">
        <RadioList v-if="useWhich === 'radio'" :lists-data="listsData"></RadioList>
        <CheckBoxList v-else-if="useWhich === 'checkbox'" :lists-data="listsData"></CheckBoxList>
      </div>
    </el-scrollbar>
  </div>
</template>

<script setup>
const props = defineProps({
  // 使用单选框(radio)还是多选框(checkbox)，默认单选框
  useWhich: {
    type: String,
    default: 'radio'
  },
  // 每个列表的数据
  // code：编号
  // date：日期
  // company：单位
  // icon：
  // icon[0] 使用图标：健 1、职 2 、从 3、放 4、不使用 0
  // icon[1] 使用图标：未报(1)、已4报(2)、不使用 0
  // icon[2] 使用图标：审(1)、通(2)、不使用 0
  // icon[3] 使用图标：未打(1)、已打(2)、不使用 0
  // icon[4] 使用图标：个(1)、团(2)、不使用 0
  listsData: {
    type: Array,
    required: true
  }
})
</script>

<style scoped>
.box {
  margin: 10px;
}
</style>