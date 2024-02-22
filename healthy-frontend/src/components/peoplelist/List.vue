<template>
  <div class="list-box" v-for="item in items" :key="item.id" @click="onClick(item)">
    <!-- 信息 -->
    <div class="info">
      <span>第{{ item.id }}个</span>
      <span>2024-01-22</span>
    </div>

    <!-- 标签 -->
    <div class="tag">
      <el-tag type="success" effect="plain" size="small" round> 健 </el-tag>
      <el-tag effect="plain" size="small" round> 检 </el-tag>
    </div>
  </div>
</template>

<script setup>
import { ref } from 'vue'

// 单选框
const radio = ref('1')

const onClick = (item) => {
  console.log(item.id)
}

const items = [
  {
    id: '1',
    name: 'Tom',
    result: '正常',
    unit: '-',
    reference: '114514',
    prompt: '-',
    abnormal: false
  },
  {
    id: '2',
    name: 'Tom',
    result: '不正常',
    unit: '-',
    reference: '114514',
    prompt: '-',
    abnormal: true
  },
  {
    id: '1',
    name: 'Tom',
    result: '正常',
    unit: '-',
    reference: '114514',
    prompt: '-',
    abnormal: false
  },
  {
    id: '2',
    name: 'Tom',
    result: '不正常',
    unit: '-',
    reference: '114514',
    prompt: '-',
    abnormal: true
  },
  {
    id: '1',
    name: 'Tom',
    result: '正常',
    unit: '-',
    reference: '114514',
    prompt: '-',
    abnormal: false
  },
  {
    id: '2',
    name: 'Tom',
    result: '不正常',
    unit: '-',
    reference: '114514',
    prompt: '-',
    abnormal: true
  },
  {
    id: '1',
    name: 'Tom',
    result: '正常',
    unit: '-',
    reference: '114514',
    prompt: '-',
    abnormal: false
  },
  {
    id: '2',
    name: 'Tom',
    result: '不正常',
    unit: '-',
    reference: '114514',
    prompt: '-',
    abnormal: true
  },
  {
    id: '1',
    name: 'Tom',
    result: '正常',
    unit: '-',
    reference: '114514',
    prompt: '-',
    abnormal: false
  },
  {
    id: '2',
    name: 'Tom',
    result: '不正常',
    unit: '-',
    reference: '114514',
    prompt: '-',
    abnormal: true
  },
  {
    id: '1',
    name: 'Tom',
    result: '正常',
    unit: '-',
    reference: '114514',
    prompt: '-',
    abnormal: false
  },
]
</script>

<style lang="scss" scoped>
.list-box {
  width: 100%;
  display: flex;
  border-bottom: solid 1px var(--el-border-color);
  padding: 10px 0;
  padding-left: 10px;

  &:hover {
    background-color: #f5f7fa;
  }

  .info {
    display: flex;
    flex-direction: column;
    width: 70%;
  }

  .tag {
    display: flex;
    flex-direction: column;
    justify-content: space-around;
    padding: 0 10px;
    width: 30%;

    .el-tag {
      padding: 0;
    }
  }
}
</style>
