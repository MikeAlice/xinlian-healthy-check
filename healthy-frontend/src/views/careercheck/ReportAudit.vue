<!-- 报告审核 -->
<template>
  <el-container style="height: 100vh">
    <!-- 侧边栏 -->
    <el-aside :style="{ maxWidth: isCollapsed ? '0px' : '300px' }">
      <PeopleList
        :style="isCollapsed ? 'display: none;' : 'min-width: 300px;'"
        :title="title"
        :checkbox-item="checkboxItem"
        :is-date-visible="isDateVisible"
        :external-form-items="formConfig.formItems"
      >
      </PeopleList>
    </el-aside>
    <!-- 伸缩按钮 -->
    <div class="shrink-button">
      <!-- 伸缩按钮 -->
      <el-icon style="cursor: pointer; width: 20px" @click="isCollapsed = !isCollapsed">
        <ArrowRightBold v-if="isCollapsed" />
        <ArrowLeftBold v-else />
      </el-icon>
    </div>
  </el-container>
</template>

<script setup>
import { ref } from 'vue'
import PeopleList from '@/components/peoplelist/PeopleList.vue'
import { ArrowRightBold, ArrowLeftBold } from '@element-plus/icons-vue'

/* PeopleList的变量 */
const title = ref('人员查询')
const checkboxItem = ref(['未登记', '已登记'])
const isDateVisible = ref(false)
const formConfig = ref({
  formItems: [
    {
      type: 'input',
      name: '',
      placeholder: '请输入身份证号'
    },
    {
      type: 'input',
      name: '',
      placeholder: '请输入体检编号'
    },
    {
      type: 'input',
      name: '',
      placeholder: '请输入单位名称'
    }
  ]
})

/* 本界面变量及函数 */
const isCollapsed = ref(false) // 是否收缩侧边栏
</script>

<style lang="scss" scoped>
.shrink-button {
  display: flex;
  align-items: center;
  height: 100%;
}
</style>
