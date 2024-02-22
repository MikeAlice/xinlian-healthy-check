<template>
  <div class="form">
    <el-form :inline="true">
      <el-form-item v-for="(item, index) of formItem" :key="index" :label="item.label">
        <el-input v-model="item.input" placeholder="请输入" clearable @change="onSearch"/>
      </el-form-item>
      <el-form-item>
        <el-button type="primary" :icon="Search" @click="onSearch">搜索</el-button>
        <el-button plain @click="onReset">重置</el-button>
      </el-form-item>
    </el-form>
  </div>
  <slot :tableColumnAttribute="dataColumn" :tableData="row"></slot>
</template>

<script setup>
import { ref } from 'vue'
import { Search } from '@element-plus/icons-vue'

const props = defineProps({
  // 哪些需要搜索的标签
  toSearchLabel: {
    type: Array,
    require: true,
  },
  // 列属性
  dataColumn: {
    type: Array,
    require: true
  },
  // 每行数据
  dataRow: {
    type: Array,
    require: true
  }
})

let row = ref(props.dataRow)
let formItem = ref(props.toSearchLabel)

const onSearch = () => {
  console.log('search!')
  let data = ref(props.toSearchLabel)
  // 没输入默认 --
  for (let item in data.value) {
    if (item.input === '') {
      item.input = '--'
    }
  }
  // 表格数据置空
  row.value = []
  // 模糊搜索
  for (let item of props.dataRow) {
    let flag = 0
    for (let to of data.value) {
      item[to.prop]
      console.log(item[to.prop])
      if (item[to.prop].includes(to.input)) {
        flag++
      }
    }
    if (flag === 4) {
      row.value.push(item)
    }
  }
}

const onReset = () => {
  console.log('reset!')
  // 将表单中的输入框清空
  for (let item of formItem.value) {
    console.log(item.input)
    item.input = ''
  }
  // parent
  row.value = props.dataRow
}
</script>

<style lang="scss" scoped>
.form {
  border-bottom: 2px dashed rgb(224, 224, 238);

  .el-form {
    .el-form-item {
      .el-input {
        --el-input-width: 150px;
      }
    }
  }
}
</style>
