<!-- 体检报告 -->
<template>
  <div>
    <el-container>
      <el-aside>
        <PeoplleList title="人员查询">
          <template #table-area>
            <SelectList use-which="checkbox" :lists-data="listsData"></SelectList>
          </template>
        </PeoplleList>
      </el-aside>
      <el-main>
        <Head name="报告预览"></Head>
        <div class="pdf">
          <PdfObject></PdfObject>
        </div>
      </el-main>
    </el-container>
  </div>
</template>

<script setup>
import PeoplleList from '@/components/peoplelist/PeopleList.vue'
import PdfObject from '@/components/pdfobject/PdfObject.vue'
import Head from '@/components/head/Head.vue'

// 列表数据
const listsData = [
  {
    code: '121111118442',
    date: '2093-4-4',
    company: 'test company3',
    icon: [1, 0, 0, 0, 2]
  },
  {
    code: '102039338444',
    date: '2023-4-4',
    company: 'test company3',
    icon: [1, 0, 0, 0, 2]
  },
  {
    code: '102039338445',
    date: '2023-4-4',
    company: 'test company3',
    icon: [1, 0, 0, 0, 2]
  },
  {
    code: '102039338446',
    date: '2023-4-4',
    company: 'test company3',
    icon: [1, 0, 0, 0, 2]
  },
  {
    code: '102039338441',
    date: '2023-4-4',
    company: 'test company',
    icon: [4, 1, 2, 1, 2] // 放、未报、通、未打、团
  }
]
</script>

<style lang="scss" scoped></style>
