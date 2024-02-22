<template>
  <div class="container">
    <div class="content">
      <!-- 标题 -->
      <Head class="title" :name="name" :middle="middle" v-if="useTitle">
        <slot name="title"></slot>
      </Head>

      <!-- 表单 -->
      <div class="form">
        <slot name="form">表单</slot>
      </div>

      <!-- 表格 -->
      <div class="table">
        <slot name="table">表格</slot>
      </div>
    </div>

    <!-- 分页 -->
    <div class="page" v-if="usePage">
      <slot name="page">分页</slot>
    </div>
  </div>
</template>

<script setup>
import { ref } from 'vue'
import Head from '@/components/head/Head.vue'

const props = defineProps({
  // 标题内容
  name: {
    type: String,
    default: '标题'
  },
  // 标题内容是否居中
  middle: {
    type: Boolean,
    default: true
  },
  // 是否显示分页
  usePage: {
    type: Boolean,
    default: true
  },
  // 是否显示标题
  useTitle: {
    type: Boolean,
    default: true
  }
})
</script>

<style lang="scss" scoped>
.container {
  height: 100%;
  overflow: hidden;
  .title {
    margin: 0;
  }
  .content {
    padding: 10px 0;
    padding-bottom: 50px;
    padding-top: 0;
    height: 100%;
    border: solid 1px var(--el-border-color);
    border-radius: 6px;
    .form {
      padding-top: 10px;
      padding-bottom: 10px;
    }
    .table {
      padding: 0 10px;
      height: 75%;
      overflow: auto;
    }
  }
}

.page {
  width: 100%;
  position: absolute;
  display: flex;
  justify-content: center;
  bottom: 15px;
}

.form,
.page {
  padding: 0 16px;
}
</style>
