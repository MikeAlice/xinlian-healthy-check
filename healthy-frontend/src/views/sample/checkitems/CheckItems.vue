<template>
  <div>
    <CheckItems :isShowButtonForTc="isShowButtonForTc" 
    :bottonTitle="bottonTitle"  :drawerTitle="drawerTitle"
    :hideButton="hideButton"  :openDrawer="openDrawer"
    :tableLieForTc="tableLieForTc"  :tableDataForTc="tableDataForTc"
    :selectDown="selectDown" :isShowSelectDown="isShowSelectDown" 
    :EditDButtonShow="EditDButtonShow" 
     @submitTc="submitTc"  />
  </div>
</template>

<script setup>
import CheckItems from '@/components/checkitems/CheckItems.vue'
import { ref,reactive } from 'vue'

const tcRowData = ref([])

//获取套餐表格行数据
const submitTc = (value) => {

tcRowData.value = value;

alert(tcRowData.value)

}

//是否显示编辑删除按钮
const EditDButtonShow = ref(false)
//是否显示确定取消按钮-套餐
const isShowButtonForTc = ref(true)
//抽屉按钮名字
const bottonTitle = ref('按钮开关')
// 抽屉标题
const drawerTitle = ref('编辑分组')
//是否显示下拉框
const isShowSelectDown = ref(false)
 //是否隐藏触发抽屉按钮
const hideButton = ref(false)
  //默认是否打开抽屉
const openDrawer = ref(false)
//套餐项目表格列
const tableLieForTc = [
  {
    prop: 'mc',
    label: '名称'
  },
  {
    prop: 'xsj',
    label: '销售价(元)'
  }
]
 //套餐项目表格数据
 const tableDataForTc = [
  {
    mc: '项目1',
    xsj: '10'
  },
  {
    mc: '项目2',
    xsj: '20'
  },
  {
    mc: '项目3',
    xsj: '30'
  },
  {
    
    mc: '项目4',
    xsj: '40'
  },
  {
    mc: '项目5',
    xsj: '50'
  },
  {
    mc: '项目6',
    xsj: '60'
  },
  {
    mc: '项目7',
    xsj: '70'
  },
  {
    
    mc: '项目8',
    xsj: '80'
  },
  {
    mc: '项目9',
    xsj: '90'
  },
  {
    mc: '项目10',
    xsj: '100'
  },
  {
    mc: '项目11',
    xsj: '110'
  },
  {
    
    mc: '项目12',
    xsj: '120'
  }
]

const selectDown =[
  {
    value: 'Option',
    label: '蔡徐坤'},
    {
    value: 'Option1',
    label: '蔡徐坤1'
    },
    {
    value: 'Option2',
    label: '蔡徐坤2'
    },
    {value: 'Option3',
    label: '蔡徐坤3',
  },
  {
    value: 'Option4',
    label: '蔡徐坤4'},
    {
    value: 'Option5',
    label: '蔡徐坤5'
    },
    {
    value: 'Option6',
    label: '蔡徐坤6'
    },
    {value: 'Option7',
    label: '蔡徐坤7',
  },
   {
    value: 'Option8',
    label: '蔡徐坤8'},
    {
    value: 'Option9',
    label: '蔡徐坤9'
    },
    {
    value: 'Option10',
    label: '蔡徐坤10'
    },
    {value: 'Option11',
    label: '蔡徐坤11',
  }
]

</script>

<style lang="scss" ></style>
