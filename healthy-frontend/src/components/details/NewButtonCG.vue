<template>
  <div>
    <el-button type="primary" style="margin-right: 10px" @click="dialogFormVisible = true">
      <el-icon style="margin-right: 5px"><Plus /></el-icon>
      新增
    </el-button>
    <!-- <el-button-group>
      <el-button @click="dialogFormVisible = true">
      <el-icon style="margin-right: 5px"><Plus /></el-icon>
      新增
    </el-button>
    <el-button @click="dialogFormVisible = true">
      <el-icon style="margin-right: 5px"><Plus /></el-icon>
      新增
    </el-button>
    <el-button @click="dialogFormVisible = true">
      <el-icon style="margin-right: 5px"><Plus /></el-icon>
      新增
    </el-button>
    </el-button-group> -->

    <el-select placeholder="更多操作" style="width: 100px" v-if="!isOnlyShowButton">
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

    <!-- 表格 -->
    <el-table
      ref="multipleTableRef"
      :data="companies"
      :cell-style="{ textAlign: 'center' }"
      :header-cell-style="{ 'text-align': 'center' }"
      style="width: 100%; margin-top: 10px"
      @selection-change="handleSelectionChange"
      border
      v-if="!isOnlyShowButton"
    >
      <el-table-column type="selection" width="60" />
      <el-table-column property="name" label="单位名称" />
      <el-table-column property="name" label="信用代码" />
      <el-table-column property="address" label="体检类型" />
      <el-table-column property="address" label="所属地区" />
      <el-table-column property="address" label="行业类别" />
    </el-table>
    <!-- <div style="margin-top: 20px">
      <el-button @click="toggleSelection([tableData[1], tableData[2]])"
        >Toggle selection status of second and third rows</el-button
      >
      <el-button @click="toggleSelection()">Clear selection</el-button>
    </div> -->

    <!-- 对话框 -->
    <el-dialog v-model="dialogFormVisible" title="新增" width="825px">
      <el-upload class="upload-demo" drag action="https://run.mocky.io/v3/9d059bf9-4660-45f2-925d-ce80ad6c4d15" multiple>
        <el-icon style="margin: 10px 0; font-size: 30px"><Plus /></el-icon>
        <div class="el-upload__text">上传营业执照</div>
      </el-upload>

      <!-- 表单 -->
      <el-form :label-position="right" :inline="true" :model="formInline" class="demo-form-inline">
        <el-form-item label="单位名称">
          <el-input v-model="formInline.user" placeholder="请输入单位名称" clearable />
        </el-form-item>
        <el-form-item label="体检类型">
          <el-select v-model="formInline.region" placeholder="请选择" clearable disabled>
            <el-option label="Zone one" value="shanghai" />
            <el-option label="Zone two" value="beijing" />
          </el-select>
        </el-form-item>
        <el-form-item label="统一社会信用代码">
          <el-input v-model="formInline.user" placeholder="请输入社会统一信用代码" clearable />
        </el-form-item>
        <el-form-item label="行业类型">
          <el-select v-model="formInline.region" placeholder="请选择" clearable>
            <el-option label="Zone one" value="shanghai" />
            <el-option label="Zone two" value="beijing" />
          </el-select>
        </el-form-item>
        <el-form-item label="所属地区">
          <el-select v-model="formInline.region" placeholder="请选择" clearable>
            <el-option label="Zone one" value="shanghai" />
            <el-option label="Zone two" value="beijing" />
          </el-select>
        </el-form-item>
        <el-form-item label="经济类型">
          <el-select v-model="formInline.region" placeholder="请选择" clearable>
            <el-option label="Zone one" value="shanghai" />
            <el-option label="Zone two" value="beijing" />
          </el-select>
        </el-form-item>
        <el-form-item label="单位注册地址">
          <el-input v-model="formInline.user" placeholder="请输入单位注册地址" clearable />
        </el-form-item>
        <el-form-item label="企业规模">
          <el-select v-model="formInline.region" placeholder="请选择" clearable>
            <el-option label="Zone one" value="shanghai" />
            <el-option label="Zone two" value="beijing" />
          </el-select>
        </el-form-item>
        <el-form-item label="体检联系人姓名">
          <el-input v-model="formInline.user" placeholder="请输入联系人姓名" clearable />
        </el-form-item>
        <el-form-item label="体检联系人电话">
          <el-input v-model="formInline.user" placeholder="请输入联系人电话" clearable />
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
import { ElMessage } from 'element-plus'
import { Plus } from '@element-plus/icons-vue'
import { defineProps } from 'vue'

const props = defineProps({
  companies: {
    type: Array,
    default: () => []
  },
  isOnlyShowButton: {
    type: Boolean,
    default: false
  }
})

// 表格相关
const multipleTableRef = ref(null)
const multipleSelection = ref([])

const toggleSelection = (rows) => {
  if (rows) {
    rows.forEach((row) => {
      if (multipleTableRef.value) {
        multipleTableRef.value.toggleRowSelection(row, undefined)
      }
    })
  } else {
    if (multipleTableRef.value) {
      multipleTableRef.value.clearSelection()
    }
  }
}

// 批量删除
const batchDelete = () => {
  // 获取选中的数据
  const selectedData = multipleSelection.value
  if (selectedData.length === 0) {
    ElMessage.warning('请先选择要删除的数据')
    return
  }

  // 获取选中的行
  let rows = multipleTableRef.value.getSelectionRows()
  console.log(rows)
  // 在下面调用接口删除后端数据。。。

  // 清空选中状态
  toggleSelection()
  ElMessage.success('批量删除成功')
}

const handleSelectionChange = (val) => {
  multipleSelection.value = val
}

const dialogFormVisible = ref(false)

const form = ref({
  name: '',
  region: '',
  date1: '',
  date2: '',
  delivery: false,
  type: [],
  resource: '',
  desc: ''
})

// 表单数据
const formInline = reactive({
  user: '',
  region: '',
  date: ''
})

// 提交表单
const onSubmit = () => {
  console.log('submit!')
}

// 清空表单
const resetFrom = () => {
  formInline.user = ''
  formInline.region = ''
  formInline.date = ''
}

// 上传图片相关
const imageUrl = ref('')

const handleAvatarSuccess = (response, uploadFile) => {
  imageUrl.value = URL.createObjectURL(uploadFile.raw)
}

const beforeAvatarUpload = (rawFile) => {
  if (rawFile.type !== 'image/jpeg') {
    ElMessage.error('Avatar picture must be JPG format!')
    return false
  } else if (rawFile.size / 1024 / 1024 > 2) {
    ElMessage.error('Avatar picture size cannot exceed 2MB!')
    return false
  }
  return true
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
