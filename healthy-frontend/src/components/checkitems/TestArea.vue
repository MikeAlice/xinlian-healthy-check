<template>
    <div >
        <el-form :inline="true"  class="demo-form-inline">
            <el-form-item label="体检提醒或影像所见" class="bold-label">
                    <el-input type="textarea"  
                    :rows="6"
                    :autosize="{ minRows: 6, maxRows: 10 }"
                    width="50%" 
                    class="suibian"
                    v-model="formInline.textarea1"
                    placeholder="输入以多个,分隔">
                    </el-input>
                    <CheckItems :isShowButtonForTc="isShowButtonForTc" 
    :bottonTitle="bottonTitle"  :drawerTitle="drawerTitle"
    :hideButton="hideButton"  :openDrawer="openDrawer"
    :tableLieForTc="tableLieForTc"  :tableDataForTc="tableDataForTc"
    :selectDown="selectDown" :isShowSelectDown="isShowSelectDown"
    :EditDButtonShow="EditDButtonShow" :isShowNew="isShowNew"    
     @submitTc="submitTc"  />
            </el-form-item>
            <el-form-item label="体检小结" class="bold-label">
                    <el-input type="textarea"  
                    :rows="6"
                    :autosize="{ minRows: 6, maxRows: 10 }"
                    width="50%" 
                    class="suibian"
                    v-model="formInline.textarea2"
                    placeholder="输入以多个,分隔">
                    <template #append>
                    <el-button :icon="选" />
                    </template>
                    </el-input>
                    <CheckItems :isShowButtonForTc="isShowButtonForTc" 
    :bottonTitle="bottonTitle"  :drawerTitle="drawerTitle"
    :hideButton="hideButton"  :openDrawer="openDrawer"
    :tableLieForTc="tableLieForTc"  :tableDataForTc="tableDataForTc"
    :selectDown="selectDown" :isShowSelectDown="isShowSelectDown"
    :EditDButtonShow="EditDButtonShow" :isShowNew="isShowNew"  
     @submitTc="submitTc"  />
            </el-form-item>
            <el-form-item label="检查医生" class="bold-label">
                <el-select
                     v-model="formInline.jcys"
                     class="m-2"
                     placeholder="请选择"
                     size="large"
                     style="width: 240px"
  >

            <el-option
                v-for="item in props.selectDown "
                :key="item"
                :label="item.label"
                :value="item.label"
    />
  </el-select>
</el-form-item>
<el-form-item label="检查日期" class="bold-label">
                    <el-input type="date"  
                    width="50%" 
                    class="suibian"
                    v-model="formInline.checkDate"
                    >
                    </el-input>
            </el-form-item>
            <el-form-item  class="bold-label">
            <el-button
            type="primary"
            @click="saveResult();resetFrom()"
          >
          保存结果
          </el-button>
        </el-form-item>
        </el-form>
    </div>
  </template>
  
  <script setup>

import { reactive,ref,defineProps,watch,defineEmits, createHydrationRenderer} from 'vue'
import CheckItems from '@/components/checkitems/CheckItems.vue'



//是否显示新增按钮
const isShowNew = ref(true)

// 表单数据
const formInline = reactive({
  textarea1: '',
  textarea2: '',
  checkDate: '',
  jcys:''
})

// 清空表单
const resetFrom = () => {
  formInline.textarea1 = ''
  formInline.textarea2 = ''
  formInline.checkDate = ''
  formInline.jcys = ''
}

created:{
    
}

//保存结果
const saveResult= () => {
    alert(formInline)
}

// 定义抽屉预设
const props = defineProps({
  //下拉框
  selectDown:{
      typr:Array,
      required: false,
      default: () => [{
        value:'字段属性值-绑定用',
        label:'下拉显示的数据'
      }]
    },
})

  // 体检诊台的字段存放区域-检查医生
  const tjzt = reactive({
  tjtx: '',
  jcys: ''
})

//抽屉1
const tcRowData = ref([])

//获取套餐表格行数据
const submitTc = (value) => {

tcRowData.value = value;

alert(tcRowData.value)

}

//是否显示编辑删除按钮
const EditDButtonShow = ref(true)
//是否显示确定取消按钮-套餐
const isShowButtonForTc = ref(true)
//抽屉按钮名字
const bottonTitle = ref('选')
// 抽屉标题
const drawerTitle = ref('常用术语')
//是否显示下拉框
const isShowSelectDown = ref(false)
 //是否隐藏触发抽屉按钮
const hideButton = ref(false)
  //默认是否打开抽屉
const openDrawer = ref(false)
//套餐项目表格列
const tableLieForTc = [
  {
    prop: 'xynr',
    label: '术语内容'
  },
]
 //套餐项目表格数据
 const tableDataForTc = [
  {
    xynr: '项目1'
  },
  {
    xynr: '项目2'
  },
  {
    xynr: '项目3'
  },
  {
    
    xynr: '项目4'
  },
  {
    xynr: '项目5'
  },
  {
    xynr: '项目6'
  },
  {
    xynr: '项目7'
  },
  {
    
    xynr: '项目8'
  },
  {
    xynr: '项目9'
  },
  {
    xynr: '项目10'
  },
  {
    xynr: '项目11'
  },
  {
    
    xynr: '项目12'
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
  
  <style lang="scss">
  .suibian{
  display: flex;
      justify-content: space-between;
      align-items: center;
}
</style>
  