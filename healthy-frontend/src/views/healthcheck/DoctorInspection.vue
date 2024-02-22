<template>
  <el-container>
    <el-aside>
      <PeopleList :use-header="false"></PeopleList>
    </el-aside>
    <el-main style="padding: 0">
      <!-- 顶部边距还需要调整 -->
      <el-card class="main_top" style="margin: 0px">
        <MedicalInfo></MedicalInfo>
        <el-button type="primary" @click="toggleDrawer(1)"> 阳性结果汇总 </el-button>
        <el-button type="primary" @click="toggleDrawer(2)"> 明细结果查看 </el-button>
      </el-card>

      <div class="drawer">
        <!-- 阳性结果汇总的抽屉 -->
        <el-drawer v-model="isDrawerVisible1" title="阳性结果汇总">
          <!-- 插入基础表格信息 -->
          <BaseDataList></BaseDataList>
          <template #footer>
            <el-button type="primary" @click="closeDrawer(1)">关闭</el-button>
          </template>
        </el-drawer>
        <!-- 明细结果查看的抽屉 -->
        <el-drawer v-model="isDrawerVisible2" title="明细结果查看">
          <template #footer>
            <el-button type="primary" @click="closeDrawer(2)">关闭</el-button>
          </template>
        </el-drawer>
      </div>
      <el-card>
        <!-- 体检详情组件 -->
        <TestResult></TestResult>
      </el-card>
    </el-main>
  </el-container>
</template>

<script setup>
import { ref } from 'vue'
import { ElDrawer, ElButton } from 'element-plus'
import PeopleList from '@/components/peoplelist/PeopleList.vue'
import MedicalInfo from '@/components/medicalinfo/MedicalInfo.vue'
import BaseDataList from '@/components/basedatalist/BaseDataList.vue'
import TestResult from '@/components/details/TestResult.vue'

// 抽屉组件显示
const isDrawerVisible1 = ref(false)
const isDrawerVisible2 = ref(false)

const toggleDrawer = (drawerNumber) => {
  if (drawerNumber === 1) {
    isDrawerVisible1.value = !isDrawerVisible1.value
  } else if (drawerNumber === 2) {
    isDrawerVisible2.value = !isDrawerVisible2.value
  }
}
//关闭抽屉显示
const closeDrawer = (drawerNumber) => {
  if (drawerNumber === 1) {
    isDrawerVisible1.value = false
  } else if (drawerNumber === 2) {
    isDrawerVisible2.value = false
  }
}
</script>

<style lang="scss" scoped>
.main_top {
  margin-top: 0%;
  margin-bottom: 5%;
}
.drawer {
  width: 500px;
  margin: 0;
}
</style>
