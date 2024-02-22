<!-- Parent.vue -->
<template>
  <div>
    <!-- search 演示 -->
    <div class="search">
      <Search :toSearchLabel="toSearch" :dataColumn="dataOneColumn" :dataRow="dataOneRow">
        <template v-slot="{ tableColumnAttribute, tableData }">
          <BaseDataList :tableColumnAttribute="tableColumnAttribute" :tableData="tableData"></BaseDataList>
        </template>
      </Search>
    </div>

    <!-- head 演示 -->
    <div class="head">
      <!-- 插槽必须为 span -->

      <Head :middle="true">
        <span>
          <el-button type="primary">搜索</el-button>
          <el-button type="primary">搜索</el-button>
          <el-button type="primary">搜索</el-button>
        </span>
      </Head>

      <Head>
        <span>
          <el-button type="primary">搜索</el-button>
          <el-button type="primary">搜索</el-button>
          <el-button type="primary">搜索</el-button>
        </span>
      </Head>

      <Head :middle="true"></Head>

      <Head name="自定义标题"></Head>
    </div>

    <!-- list 演示 -->
    <div class="list">
      <h2>多选列表</h2>
      <SelectList use-which="checkbox" :lists-data="listsData"></SelectList>
      <h2>单选列表</h2>
      <SelectList use-which="radio" :lists-data="listsData"></SelectList>
      <h2>空单选列表</h2>
      <SelectList use-which="radio"></SelectList>
      <h2>空多选列表</h2>
      <SelectList use-which="checkbox"></SelectList>
    </div>

    <!-- peoplelist-inter 演示
    <div class="peoplelist">
      <PeopleListInter>
        <template #btns>
          <el-button type="primary">搜索</el-button>
          <el-button type="primary">搜索</el-button>
        </template>
        <template #form>
          <Search :toSearchLabel="toSearch" :dataColumn="dataOneColumn" :dataRow="dataOneRow"></Search>
        </template>
        <template #list>
          <SelectList use-which="radio" :lists-data="listsData"></SelectList>
        </template>
      </PeopleListInter>
    </div> -->

    <!-- peoplelist 演示 -->
    <peoplelist :isShowCheckbox="false" :isShowSwitch="false">
      <template #table-area>
        <SelectList use-which="radio" :lists-data="listsData"></SelectList>
      </template>
    </peoplelist>

    <peoplelist :isShowCheckbox="false" :isShowSwitch="false">
      <template #table-area>
        <SelectList use-which="checkbox" :lists-data="listsData"></SelectList>
      </template>
    </peoplelist>

    <peoplelist :isShowCheckbox="false" :isShowSwitch="false">
      <template #table-area>
        <SelectList use-which="checkbox"></SelectList>
      </template>
    </peoplelist>
  </div>
</template>

<script setup>
import Search from '@/components/search/Search.vue'
import BaseDataList from '@/components/basedatalist/BaseDataList.vue'
import Head from '@/components/head/Head.vue'
import SelectList from '@/components/selectList/SelectList.vue'
import peoplelist from '@/components/peoplelist/PeopleList.vue'
// import PeopleListInter from '../../../components/peoplelist/PeopleList-Inter.vue'

// 需要搜索的数据传入
// const toSearch = ['单位名称', '信用代码', '联系人', '联系电话']
const toSearch = [
  {
    prop: 'name',
    label: '单位名称',
    input: ''
  },
  {
    prop: 'credit',
    label: '信用代码',
    input: ''
  },
  {
    prop: 'contact',
    label: '联系人',
    input: ''
  },
  {
    prop: 'phone',
    label: '联系电话',
    input: ''
  }
]

// 表格数据 1
// 列属性 attribute
const dataOneColumn = [
  {
    prop: 'name',
    label: '单位名称'
  },
  {
    prop: 'credit',
    label: '信用代码'
  },
  {
    prop: 'examination',
    label: '体检类型'
  },
  {
    prop: 'address',
    label: '所属地区'
  },
  {
    prop: 'category',
    label: '行业类别'
  },
  {
    prop: 'etype',
    label: '经济类型'
  },
  {
    prop: 'scale',
    label: '企业规模'
  },
  {
    prop: 'contact',
    label: '联系人'
  },
  {
    prop: 'phone',
    label: '联系电话'
  }
]
// 每行的数据
const dataOneRow = [
  {
    name: '乐山市峨边盛和矿业',
    credit: '--',
    examination: '健康体检',
    address: '--',
    category: '铁矿采选*',
    etype: '国有企业',
    scale: '--',
    contact: '--',
    phone: '--'
  },
  {
    name: '习水宏旭纸箱有限公司',
    credit: '--',
    examination: '健康体检',
    address: '--',
    category: '--',
    etype: '--',
    scale: '--',
    contact: '蔡徐坤',
    phone: '--'
  },
  {
    name: '四川峨边三丰冶金材料',
    credit: '--',
    examination: '健康体检',
    address: '--',
    category: '--',
    etype: '国有企业',
    scale: '--',
    contact: '--',
    phone: '--'
  }
]

// 列表数据
// icon：
// icon[0] 使用图标：健 1、职 2 、从 3、放 4、不使用 0
// icon[1] 使用图标：未报(1)、已4报(2)、不使用 0
// icon[2] 使用图标：审(1)、通(2)、不使用 0
// icon[3] 使用图标：未打(1)、已打(2)、不使用 0
// icon[4] 使用图标：个(1)、团(2)、不使用 0
const listsData = [
  {
    code: '102039338441',
    date: '2023-4-4',
    company: 'test company',
    icon: [4, 1, 2, 1, 2] // 放、未报、通、未打、团
  },
  {
    code: '121111118442',
    date: '2093-4-4',
    company: 'test company3',
    icon: [1, 0, 0, 0, 1]
  },
  {
    code: '102039338444',
    date: '2023-4-4',
    company: 'test company3',
    icon: [4, 1, 2, 2, 2]
  },
  {
    code: '102039338445',
    date: '2023-4-4',
    company: 'test company3',
    icon: [4, 1, 2, 2, 2]
  }
]
</script>

<style lang="scss" scoped></style>
