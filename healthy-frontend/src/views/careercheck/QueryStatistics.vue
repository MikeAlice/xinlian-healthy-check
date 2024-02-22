<!-- 查询统计 -->
<template>
  <el-container style="height: 100%">
    <el-aside width="250px">
      <PeopleList style="height: 100%; width: 100%" />
    </el-aside>
    <el-main>
      <div class="tag-group" style="border-bottom: var(--el-border-color) solid 1px">
        <div>
          必检项折扣：
          <el-input placeholder="-" />
        </div>
        <div>
          体检编号：
          <el-input placeholder="-" />
        </div>
        <div>
          姓名：
          <el-input placeholder="-" />
        </div>
        <div style="margin-right: 50px">
          身份证号：
          <el-input placeholder="-" />
        </div>
        <div>
          <el-button type="primary">查询</el-button>
          <el-button type="primary">重置</el-button>

          <el-select placeholder="展开" style="width: 80px">
            <el-option @click="dialogFormVisible = true">
              <el-icon style="margin-right: 5px"><icon-refresh /></el-icon>
              刷新
            </el-option>
            <el-option @click="batchDelete">
              <el-icon style="margin-right: 5px"><icon-delete /></el-icon>
              批量删除
            </el-option>
            <el-option @click="dialogFormVisible = true">
              <el-icon style="margin-right: 5px"><icon-bottom /></el-icon>
              导出本页数据
            </el-option>
          </el-select>
        </div>
      </div>

      <Statistics :outsideData="outside" :insideData="inside" />

      <el-table :data="tableData" height="450" border :cell-style="{ textAlign: 'center' }" :header-cell-style="{ 'text-align': 'center' }" style="width: 100%">
        <el-table-column prop="id" label="#" width="60" />
        <el-table-column prop="name" label="项目名称" />
        <el-table-column prop="result" label="原价" />
        <el-table-column prop="unit" label="折扣" />
        <el-table-column prop="reference" label="折扣价" />
        <el-table-column prop="prompt" label="排序" />
      </el-table>

      <!-- 分页 -->
      <div style="display: flex; justify-content: end; margin-top: 15px">
        <el-pagination
          v-model:current-page="currentPage4"
          v-model:page-size="pageSize4"
          :page-sizes="[100, 200, 300, 400]"
          :small="small"
          :disabled="disabled"
          :background="background"
          layout="total, sizes, prev, pager, next, jumper"
          :total="400"
          @size-change="handleSizeChange"
          @current-change="handleCurrentChange"
        />
      </div>
    </el-main>
  </el-container>
</template>

<script setup>
import { ref } from 'vue'
import Statistics from '@/components/statistics/Statistics.vue'
import PeopleList from '@/components/peoplelist/PeopleList.vue'

// 图表相关
const outside = [
  { value: 1048, name: '未评价' },
  { value: 335, name: '已评价' }
]

const inside = [
  { value: 1548, name: '未登记' },
  { value: 775, name: '在体检' },
  { value: 679, name: '已总检' }
]

// 分页相关
const currentPage1 = ref(5)
const currentPage2 = ref(5)
const currentPage3 = ref(5)
const currentPage4 = ref(4)
const pageSize2 = ref(100)
const pageSize3 = ref(100)
const pageSize4 = ref(100)
const small = ref(false)
const background = ref(false)
const disabled = ref(false)

const handleSizeChange = (val) => {
  console.log(`${val} items per page`)
}
const handleCurrentChange = (val) => {
  console.log(`current page: ${val}`)
}
</script>

<style lang="scss" scoped>
.tag-group {
  background-color: var(--el-bg-color);
  padding: 15px;
  display: flex;

  > div {
    font-weight: bold;
    margin-right: 15px;

    .el-input {
      width: 120px;
    }
  }
}

.el-button {
  margin: 0;
  margin-right: 12px;
}
</style>
