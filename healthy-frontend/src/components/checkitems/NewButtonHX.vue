<template>
    <div>
    <el-button type="primary" style="margin-right: 10px" @click="dialogFormVisible = true">
      <el-icon style="margin-right: 5px"><Plus /></el-icon>
      新增
    </el-button>

     <!-- 对话框 -->
     <el-dialog v-model="dialogFormVisible" title="术语添加" width="1025px">

      <!-- 表单 -->
      <el-form :label-position="right" :inline="true" :model="formInline" class="demo-form-inline">
        <el-col :span="24">
        <el-form-item  label="科室名称" class="bold-label">
      <el-select v-model="formInline.ksmc" class="m-2" placeholder="请选择" size="large" style="width: 240px">
    <el-option v-for="item in props.ksmcsw " :key="item" :label="item.label" :value="item.value"/>
  </el-select>
</el-form-item>
</el-col>
<el-form-item  label="体检类型" class="bold-label">
      <el-select v-model="formInline.tjlx" class="m-2" placeholder="请选择" multiple size="large" style="width: 240px">
    <el-option v-for="item in props.tjlxsw " :key="item" :label="item.label" :value="item.value"/>
  </el-select>
</el-form-item>
<el-form-item  label="术语类型" class="bold-label">
      <el-select v-model="formInline.sylx" class="m-2" placeholder="请选择" size="large" style="width: 240px">
    <el-option v-for="item in props.sylxsw " :key="item" :label="item.label" :value="item.value"/>
  </el-select>
</el-form-item>
<el-form-item  label="危害因素" class="bold-label">
      <el-select v-model="formInline.whys" class="m-2" placeholder="请选择" size="large" style="width: 240px">
    <el-option v-for="item in props.whyssw " :key="item" :label="item.label" :value="item.value"/>
  </el-select>
</el-form-item>
<el-form-item  label="在岗状态" class="bold-label">
      <el-select v-model="formInline.zgzt" class="m-2" placeholder="请选择" multiple size="large" style="width: 240px">
    <el-option v-for="item in props.zgztsw " :key="item" :label="item.label" :value="item.value"/>
  </el-select>
</el-form-item>
<el-form-item label="状态">
      <el-radio-group v-model="formInline.zt">
        <el-radio label="启用" />
        <el-radio label="禁用" />
      </el-radio-group>
</el-form-item>
  <el-form-item label="术语内容">
      <el-input v-model="formInline.synr" type="textarea" placeholder="请输入术语内容"/>
  </el-form-item>
    <el-form-item label="排序" default="0">
      <el-input v-model="formInline.px" />
    </el-form-item>
</el-form>

      <!-- 底栏 -->
      <template #footer>
        <span class="dialog-footer">
          <el-button
            @click="dialogFormVisible = false;resetFrom()"
            >取消</el-button
          >
          <el-button
            type="primary"
            @click="onSubmit();resetFrom()"
          >
            提交
          </el-button>
        </span>
      </template>
    </el-dialog>
    </div>
  </template>
  
<script setup>
import { reactive, ref } from 'vue'
import { Plus } from '@element-plus/icons-vue'
import { defineProps } from 'vue'



created:{
    
  }
  

const dialogFormVisible = ref(false)
// 上传图片相关
const imageUrl = ref('')

const props = defineProps({
  ksmcsw: {
    type: Array,
    default: () => []
  },
  tjlxsw: {
    type: Array,
    default: () => []
  },
  sylxsw: {
    type: Array,
    default: () => []
  },
  whyssw: {
    type: Array,
    default: () => []
  },
  zgztsw: {
    type: Array,
    default: () => []
  }
})

// 表格相关
const multipleTableRef = ref(null)
const multipleSelection = ref([])

// 对话框数据字段
const formInline = reactive({
  ksmc: '',
  tjlx: '',
  sylx: '',
  whys:'',
  zgzt:'',
  zt:'',
  synr:'',
  px:0
})

// 提交表单
const onSubmit = () => {
  
}

// 清空表单
const resetFrom = () => {
 // 将表单中的输入框清空
 for (const key in formInline) {
  formInline[key] = ''
  }
}

</script>
  
<style lang="scss" scoped>
.el-button--text {
  margin-right: 15px;
}

.el-dialog {
  display: flex;
  justify-content: center;
}

.el-input,
.el-select {
  width: 180px;
}

.el-form {
  flex: 1;
  display: grid;
  grid-template-columns: repeat(2, 1fr);
  gap: 5px;
  justify-items: end;
}

.dialog-footer button:first-child {
  margin-right: 10px;
}
</style>
  