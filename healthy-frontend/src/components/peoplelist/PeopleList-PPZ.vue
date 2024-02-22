<template>
  <div class="container">
    <!-- 标题 -->
    <Head class="title" :name="title" middle="true"></Head>

    <div class="content">
      <!-- 表单 -->
      <div class="form">
        <slot name="form">表单</slot>
      </div>

      <!-- 表格 -->
      <div class="table">
        <slot name="table">表格</slot>
      </div>

      <!-- 分页 -->
      <div class="page">
        <el-pagination
          v-model:current-page="paginationData.currentPage"
          v-model:page-size="paginationData.pageSize"
          :page-sizes="props.pageSizes"
          layout=" prev,pager, next"
          :total="props.total"
          pager-count="5"
          @size-change="handleSizeChange"
          @current-change="handleCurrentChange"
        />
      </div>
    </div>
  </div>
</template>

<script setup>
import { ref } from 'vue'
import Head from '@/components/head/Head.vue'

const props = defineProps({
  title: {
    type: String,
    default: '标题'
  },
  // 表格的数据数量
  total: {
    type: Number,
    require: true,
    default: 50
  }
})

// 分页数据的处理逻辑
const paginationData = ref({
  currentPage: 1,
  pageSize: props.pageSizes ? props.pageSizes[0] : 5
})

const handleSizeChange = (pageSize) => {
  // 当前页的数据容量改变，重置页码为1
  paginationData.value.currentPage = 1
  // 传入当期那页面的容量大小和当前页面
  emits('updateTableData', pageSize, paginationData.value.currentPage)
}
const handleCurrentChange = (currentPage) => {
  paginationData.value.currentPage = currentPage
  // 传入当前页码容量(默认值5)和当前页码
  emits('updateTableData', paginationData.value.pageSize, currentPage)
}

const emits = defineEmits(['updateTableData'])

defineExpose({
  paginationData
})
</script>

<style lang="scss" scoped>
.container {
  height: 100%;
  position: relative;

  .title {
    margin: 0;
  }
  .content {
    padding: 10px 0;
    padding-bottom: 50px;
    height: calc(100% - 50px);
    border: solid 1px var(--el-border-color);
    background-color: #fff;

    .form {
      padding-bottom: 10px;
    }
    .table {
      padding: 0 10px;
      height: calc(100% - 150px);
      overflow: auto;
    }
  }
  .page {
    width: 100%;
    position: absolute;
    display: flex;
    justify-content: center;
    bottom: 16px;
  }
}

.form {
  padding: 0 16px;
}
.page {
  display: flex;
  justify-content: center;
  align-items: center;
  text-align: center;
  margin-top: 30px;
  position: absolute;
  bottom: 0;
}
</style>
