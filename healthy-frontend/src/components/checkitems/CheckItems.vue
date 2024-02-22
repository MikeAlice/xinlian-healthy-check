<template>
  <el-button type="primary" style="margin-left: 16px" @click="drawer2 = true" v-if="!hideButton">{{ props.bottonTitle }}</el-button>


 <!-- 选检项目-抽屉 -->
<div id = 'xjxm' class="darwer-box">
  <el-drawer v-model="drawer2" :title= "tableTitle"  :with-header="true" size="50%" direction="rtl" >
    <el-form :inline="true" :model="formInlineTc" class="demo-form-inline">
    <el-form-item label="关键字:" class="bold-label">
      <!-- 关键字输入框 -->
      <el-input
        v-model="formInlineTc.gjz"
        class="suibian"
        width="50px"
        placeholder="请输入关键字:"
        :suffix-icon="Search"
      />
    </el-form-item>
<!-- 套餐项目-所属科室-下拉菜单 -->
    <el-form-item  v-if="isShowSelectDown" label="所属科室" class="bold-label">
      <el-select
    v-model="formInlineTc.ssks"
    class="m-2"
    placeholder="请选择"
    size="large"
    style="width: 240px"
  >

    <el-option
      v-for="item in props.selectDown "
      :key="item"
      :label="item.label"
      :value="item.value"
    />
  </el-select>
</el-form-item>
  <!-- 套餐项目-from表单-按钮 -->
    <el-form-item>
      <el-button type="primary" :icon="Search" @click="handleSearchTc">搜索</el-button>
      <el-button plain @click="handleCzTc">重置</el-button>
      <div v-if="isShowNew">
      <NewButtonHx :ksmcsw="ksmcsw" :tjlxsw="tjlxsw" :sylxsw="sylxsw" :whyssw="whyssw" :zgztsw="zgztsw"/>
    </div>
    </el-form-item>
  </el-form>

  <!-- 套餐项目-表格数据table -->
  <el-table
    ref="multipleTableRefForTc"
    :data="tableDataForTc.slice((currentPage4 - 1) * pageSize4,currentPage4 * pageSize4)"
    style="width: 100%"
    :row-class-name="tableRowClassName"
    @select="selectTc"
    @selection-change="handleSelectionChangeForTc"
  >
    <!-- 单选框 -->
    <el-table-column type = "selection" label="单选框选择" width="180" />
    <el-table-column v-for="lieColumn in props.tableLieForTc" :key="lieColumn" :prop="lieColumn.prop" :label="lieColumn.label" :width="lieColumn.width" :align="lieColumn.align" />
    <el-table-column prop="cz" label="操作" v-if="EditDButtonShow">
      <template #default="scope" >
        <el-button size="small" @click="handleEdit(scope.$index, scope.row)"
          >编辑</el-button
        >
        <el-button
          size="small"
          type="danger"
          @click="handleDelete(scope.$index, scope.row)"
          >删除</el-button
        >
      </template>
    </el-table-column>
  </el-table>
  <el-pagination
      v-model:current-page="currentPage4"
      v-model:page-size="pageSize4"
      :page-sizes="[10, 20, 50, 100]"
      :small="small"
      :disabled="disabled"
      layout="total, sizes, prev, pager, next, jumper"
      :total= props.tableDataForTc.length
      @size-change="handleSizeChange"
      @current-change="handleCurrentChange"
    />

      <!-- 底栏 -->
      <template #footer v-if="isShowButtonForTc">
        <!-- <span class="dialog-footer"> -->
          <el-button
            @click="cancelTc"
            >关闭</el-button
          >
          <el-button
            type="primary"
            @click="submitTc"
          >
          确定
          </el-button>
        <!-- </span> -->
      </template>
  </el-drawer>
</div>
</template>

<script lang="ts" setup>
import { reactive,ref,defineProps,watch,defineEmits} from 'vue'
import { Search } from '@element-plus/icons-vue'
import { ElMessage, ElMessageBox } from 'element-plus'
import NewButtonHx from  '@/components/checkitems/NewButtonHx.vue'

// 分页属性
const currentPage4 = ref(1)
const pageSize4 = ref(10)
const small = ref(false)
const disabled = ref(false)

//新增按钮是否显示
const isShowNew = ref(false)

//编辑
const handleEdit = (index: number, row: Array<String>) => {
  alert(index)
  alert(row)
}

//删除
const handleDelete = (index: number, row: Array<String>) => {
  ElMessageBox.confirm(
    'proxy will permanently delete the data. Continue?',
    'Warning',
    {
      confirmButtonText: 'OK',
      cancelButtonText: 'Cancel',
      type: 'warning',
    }
  )
    .then(() => {
      //发请求给后端
      ElMessage({
        type: 'success',
        message: 'Delete completed',
      })
    })
    .catch(() => {
      ElMessage({
        type: 'info',
        message: 'Delete canceled',
      })
    })
  alert(index)
  alert(row)
}


//分页方法-套餐
const handleSizeChange = (val: number) => {
  console.log(`${val} items per page`)
}
const handleCurrentChange = (val: number) => {

}


  // 搜索框的字段存放区域-套餐项目
  const formInlineTc = reactive({
  gjz: '',
  ssks: ''
})



//标签设置区域
const drawer2 = ref(false)


// 定义抽屉预设
const props = defineProps({
  //是否显示新增按钮
  isShowNew:{
    type: Boolean,
    default: false
  },
  //是否显示编辑删除按钮
  EditDButtonShow:{
    typr: Boolean,
    default: false
  },
  //触发的按钮名字
  bottonTitle:{
    type: String,
    required: false,
    default: '按钮名字'
  },
  //抽屉标题
  tableTitle:{
    type: String,
    required: false,
    default: '抽屉标题'
  },
    //是否显示下拉框
    isShowSelectDown:{
    type: Boolean,
    default: true
  },
  //是否显示确定取消按钮
  isShowButtonForTc:{
    type: Boolean,
    default: true
  },
  //控制触发按钮是否隐藏
  hideButton:{
    type: Boolean,
    default: false
  },
   //控制抽屉是否打开
   openDrawer:{
    type: Boolean,
    default: false
   },
    //表格列属性
    tableLieForTc:{
      type:Array,
      required: true,
      default: () => [{
        prop:'bind',
        label:'列的显示名称'
      },
      {
        prop:'bind2',
        label:'列的显示名称'
      }]
    },
    //表格数据
    tableDataForTc:{
      type:Array,
      required: true,
      default: () => [{
        bind:'列的显示字段名',
        bind2:'列的显示字段名'
      }]
    },
    //下拉框
    selectDown:{
      typr:Array,
      required: false,
      default: () => [{
        value:'字段属性值-绑定用',
        label:'下拉显示的数据'
      }]
    }
})

const EditDButtonShow = ref(true)
const hideButton=ref(false)
//是否显示下拉框
const isShowSelectDown=ref(true)
const title = ref()
//初始化方法
created:{

  EditDButtonShow.value = props.EditDButtonShow
  hideButton.value=props.hideButton
  isShowSelectDown.value = props.isShowSelectDown
  drawer2.value=props.openDrawer
  title.value = props.tableTitle
  isShowNew.value=props.isShowNew
}



const emits = defineEmits(['submitTc','cancelTc','rowDataForTcMd'])

//套餐抽屉的打开与关闭
const openTc = () => drawer2.value = true
const closeTc = () => drawer2.value = false




const multipleTableRefForTc =  ref()
const multipleSelectionForTc = ref([])
const rowDataForTc = ref([]);

// 套餐抽屉的确认与取消按钮
const submitTc = () => {
  //获取当前选中行的数据
  emits('submitTc',rowDataForTc.value);
  cancelTc()
}
const cancelTc = () => {
  // 清除 所有勾选项
  multipleTableRefForTc.value.clearSelection()
  closeTc()
}


const rowDataForTcMd = () => {
  emits('rowDataForTcMd',rowDataForTc.value);
}

let loading = ref(false)

const showloading = () => loading.value = true
const hideloading = () => loading.value = false

// 暴露出去
defineExpose({
  openTc, closeTc, cancelTc,submitTc, showloading, hideloading,rowDataForTcMd
})

// 点击事件区域


//处理搜索-套餐项目
const handleSearchTc = () => {
  console.log(formInlineTc.gjz)
  console.log(formInlineTc.ssks)
}

//处理重置-套餐项目
const handleCzTc = () => {
  console.log('Cz')
   // 将表单中的输入框清空
   for (const key in formInlineTc) {
    formInlineTc[key] = ''
  }
}





//搜索变化
const handleSelectionChangeForTc = (val) => {
  multipleSelectionForTc.value = val
  rowDataForTc.value =val
}





// 套餐项目-表格绑定事件selectTc
const selectTc = (selection, row) => {
  // 清除 所有勾选项
  multipleTableRefForTc.value.clearSelection()
  // 当表格数据都没有被勾选的时候 就返回
  // 主要用于将当前勾选的表格状态清除
  if (selection.length == 0) return
  multipleTableRefForTc.value.toggleRowSelection(row, true)

}



//套餐项目-表格的class样式
const tableRowClassName = ({
  row,
  rowIndex,
}: {
  row: Array<String>
  rowIndex: number
}) => {
  if (rowIndex % 2 === 0) {
    return 'warning-row'
  } else if (rowIndex % 2  === 1) {
    return 'success-row'
  }
  return ''
}

//新增按钮下拉框的数据
const ksmcsw = [{
        value:'字段属性值-绑定用',
        label:'下拉显示的数据'
      }]

      const tjlxsw = [{
        value:'字段属性值-绑定用',
        label:'下拉显示的数据'
      }]
      const sylxsw = [{
        value:'字段属性值-绑定用',
        label:'下拉显示的数据'
      }]
      const whyssw = [{
        value:'字段属性值-绑定用',
        label:'下拉显示的数据'
      }]
      const zgztsw = [{
        value:'字段属性值-绑定用',
        label:'下拉显示的数据'
      }]
</script>

<style lang="scss"  >
.el-table .warning-row {
  --el-table-tr-bg-color: var(--el-color-warning-light-9);
}
.el-table .success-row {
  --el-table-tr-bg-color: var(--el-color-success-light-9);
}
.suibian{
  display: flex;
      justify-content: space-between;
      align-items: center;
}
</style>
