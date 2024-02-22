<!-- 模板管理 -->
<template>
  <div class="contain">
    <BaseDataList
      ref="BaseDataRef"
      :use-form="useForm"
      :form-data="formData"
      :table-data="tableData"
      :table-column-attribute="tableColumnAttribute"
      :total="total"
      :use-pagination="usePagination"
      :pagination-data="paginationData"
      :use-fixed="useFixed"
      :use-switch="useSwitch"
      @update-table-data="handlePageChange"
      @update-selected-rows="selectRows"
      @update-switch-state="handleUpdateSwitchState"
    >
      <!-- fixed固定列 -->
      <template #fixed="{ row }">
        <el-button type="primary" style="margin-right: 5px" @click="handelLook(row)">
          <el-icon><View></View></el-icon>
          查看
        </el-button>
        <el-dropdown>
          <el-button>
            更多操作
            <el-icon class="el-icon--right">
              <arrow-down />
            </el-icon>
          </el-button>

          <template #dropdown>
            <el-dropdown-menu>
              <el-dropdown-item @click="handleEdit(row)">
                <el-icon><Edit></Edit></el-icon>
                修改
              </el-dropdown-item>
              <el-dropdown-item>
                <el-icon><UploadFilled></UploadFilled></el-icon>
                预览
              </el-dropdown-item>
              <el-dropdown-item>
                <el-icon><DeleteFilled></DeleteFilled></el-icon>
                删除
              </el-dropdown-item>
            </el-dropdown-menu>
          </template>
        </el-dropdown>
      </template>

      <!-- form表单区域 -->
      <template #form>
        <el-form-item label="报告类型">
          <el-select v-model="formData.bgType" style="width: 130px">
            <el-option v-for="item in bgTypeOptions" :key="item.value" :label="item.label" :value="item.value" />
          </el-select>
        </el-form-item>
        <el-form-item label="模版类型">
          <el-select v-model="formData.mbType" style="width: 130px">
            <el-option v-for="item in mbTypeOptions" :key="item.value" :label="item.label" :value="item.value"></el-option>
          </el-select>
        </el-form-item>
        <el-form-item label="项目名称">
          <el-select v-model="formData.projectName" style="width: 130px">
            <el-option v-for="item in projectNameOptions" :key="item.value" :label="item.label" :value="item.value"></el-option>
          </el-select>
        </el-form-item>
        <div v-if="isVisible" class="visible">
          <el-form-item label="模版状态">
            <el-select v-model="formData.mbState" style="width: 130px">
              <el-option v-for="item in mbStateOptions" :key="item.value" :label="item.label" :value="item.value"></el-option>
            </el-select>
          </el-form-item>
          <el-form-item label="创建时间">
            <div class="demo-date-picker">
              <div class="block">
                <el-date-picker v-model="value1" type="daterange" />
              </div>
            </div>
          </el-form-item>
        </div>
        <el-form-item>
          <el-button type="primary">
            <el-icon><Search></Search></el-icon>
            搜索
          </el-button>
        </el-form-item>
        <el-form-item>
          <el-button @click="resetForm">重置</el-button>
        </el-form-item>
        <el-form-item>
          <el-button v-if="noVisible" link style="color: rgb(45, 140, 240)" @click="expand">
            展开
            <el-icon><ArrowDownBold></ArrowDownBold></el-icon>
          </el-button>
        </el-form-item>
        <el-form-item>
          <el-button v-if="isVisible" link style="color: rgb(45, 140, 240)" @click="hide">
            收起
            <el-icon><ArrowUpBold></ArrowUpBold></el-icon>
          </el-button>
        </el-form-item>
      </template>

      <!-- operation功能区域 -->
      <template #operation>
        <div class="operation">
          <el-button type="primary" style="margin-right: 10px" @click="dialogVisible = true">
            <el-icon><Plus></Plus></el-icon>
            新增
          </el-button>
          <!-- 新增对话框区域 -->
          <el-dialog v-model="dialogVisible" title="新增" width="40%">
            <el-form :model="newForm">
              <el-form-item label="*报告类型" label-width="90px">
                <el-input v-model="newForm.bgType"></el-input>
              </el-form-item>
              <el-form-item label="*模版类型" label-width="90px">
                <el-input v-model="newForm.mbType"></el-input>
              </el-form-item>
              <el-form-item label="*状态" label-width="90px">
                <el-radio-group v-model="newForm.status">
                  <el-radio label="启用">启用</el-radio>
                  <el-radio label="停用">停用</el-radio>
                </el-radio-group>
              </el-form-item>
              <el-form-item label="*模板内容" label-width="90px">
                <el-upload class="upload-demo" drag multiple>
                  <el-icon class="el-icon--upload" style="color: rgb(51, 153, 255)"><upload-filled /></el-icon>
                  <div class="el-upload__text">
                    点击这里或将文件拖拽到这里上传
                    <br />
                    仅支持docx、ftl格式文件
                  </div>
                </el-upload>
              </el-form-item>
              <el-form-item label="*排序" label-width="90px">
                <el-input v-model="newForm.sort"></el-input>
              </el-form-item>
            </el-form>
            <template #footer>
              <span class="dialog-footer">
                <el-button @click="dialogVisible = false">取消</el-button>
                <el-button type="primary" @click="dialogVisible = false">提交</el-button>
              </span>
            </template>
          </el-dialog>
          <el-dropdown>
            <el-button style="margin-right: 8px">
              更多操作
              <el-icon class="el-icon--right"> <arrow-down /> </el-icon
            ></el-button>
            <template #dropdown>
              <el-dropdown-menu>
                <el-dropdown-item>
                  <el-icon><Refresh></Refresh></el-icon>
                  刷新
                </el-dropdown-item>
                <el-dropdown-item>
                  <el-icon><DeleteFilled></DeleteFilled></el-icon>
                  批量删除
                </el-dropdown-item>
                <el-dropdown-item>
                  <el-icon><Bottom></Bottom></el-icon>
                  导出本页数据
                </el-dropdown-item>
              </el-dropdown-menu>
            </template>
          </el-dropdown>
          <el-button @click="closeForm">关闭搜索</el-button>
          <el-button @click="closeHint">关闭提示</el-button>
        </div>
      </template>

      <!-- 多选清除栏 -->
      <template #hint>
        <div v-if="useHint" class="hint">
          <span>
            <el-icon style="color: blue"><InfoFilled></InfoFilled></el-icon>
            已选择{{ selectedTotal }}项
          </span>
          <el-button type="primary" link style="margin-bottom: 3px" @click="clearRows">清空</el-button>
        </div>
      </template>
    </BaseDataList>
  </div>
</template>

<script setup>
import { ref, reactive, onMounted } from 'vue'
import { ArrowDown, Search, Plus, InfoFilled, Refresh, DeleteFilled, Bottom, View, Edit, ArrowDownBold, ArrowUpBold, UploadFilled } from '@element-plus/icons-vue'
import BaseDataList from '@/components/basedatalist/BaseDataList.vue'

const useHint = ref(true)
const useForm = ref(true)
const usePagination = ref(true)
const BaseDataRef = ref()
const dialogVisible = ref(false)
const useFixed = ref(true)
// form表单中时间
const value1 = ref('')

// 展开form表单中后两项
const isVisible = ref(false)

const expand = () => {
  isVisible.value = true
  noVisible.value = false
}

// 收起form表单中后两项
const noVisible = ref(true)

const hide = () => {
  isVisible.value = false
  noVisible.value = true
}

// 新增功能表单内容是否禁用
// const formDisabled = ref(false)

// table列数据
const tableColumnAttribute = ref([
  { prop: 'bgType', label: '报告类型', width: '240', align: 'center' },
  { prop: 'mbType', label: '模版类型', width: '240', align: 'center' },
  { prop: 'projectName', label: '组合项目名称', width: '240', align: 'center' },
  { prop: 'status', label: '状态', width: '240', align: 'center', useSwitch: true },
  { prop: 'mbContent', label: '模版内容', width: '240', align: 'center' },
  { prop: 'createTime', label: '创建时间', width: '240', align: 'center' }
])

// table数据
const tableData = ref([
  {
    bgType: '从业体检',
    mbType: '从业体检引导单',
    prijectName: '-',
    status: true,
    mbContent: '-',
    createTime: '-'
  }
])

// 表单数据
const formData = reactive({
  bgType: '',
  mbType: '',
  projectName: '',
  mbState: '',
  createTime: ''
})

// 表单选择器数据byType
const bgTypeOptions = ref([
  {
    value: '职业体检'
  },
  {
    value: '健康体检'
  },
  {
    value: '从业体检'
  },
  {
    value: '放射体检'
  },
  {
    value: '通用'
  }
])

// 表单选择器数据mbType
const mbTypeOptions = ref([
  {
    value: '引导单'
  },
  {
    value: '分项报告'
  }
])

// 表单选择器数据projectName
const projectNameOptions = ref([
  {
    value: '1'
  }
])

// 表单选择器数据mbState
const mbStateOptions = ref([
  {
    value: '启用'
  },
  {
    value: '停用'
  }
])

// 新增功能中表单数据
const newForm = reactive({
  bgType: '',
  mbType: '',
  status: '',
  sort: ''
})

// 新增功能中选择器数据
const newOptions = ref([
  {
    label: '职业体检',
    value: '职业体检'
  },
  {
    label: '健康体检',
    value: '健康体检'
  },
  {
    label: '从业体检',
    value: '从业体检'
  },
  {
    label: '放射体检',
    value: '放射体检'
  }
])

// 查看操作
const handelLook = (row) => {
  newForm.value = row
  // formDisabled.value = true
  dialogVisible.value = true
}

const closeForm = () => {
  useForm.value = !useForm.value
}

const closeHint = () => {
  useHint.value = !useHint.value
}

// 更多操作中修改功能
const handleEdit = (row) => {
  dialogVisible.value = true
}

// 显示选中几项
const selectedTotal = ref(0)
// 选中的row

const selectRows = (selectRows) => {
  selectedTotal.value = selectRows.length
  // console.log(selectRows)
  console.log(BaseDataRef.value.rows)
}

// 清空选中行的方法
const clearRows = () => {
  // 调用子组件的 clearSelectedRows 方法
  BaseDataRef.value.clearSelectedRows()
}

// 重置表单方法
const resetForm = () => {
  ;(formData.ksCoding = ''), (formData.ksLogogram = ''), (formData.ksName = ''), (formData.typeCheck = '')
}

// 开关监听
const handleUpdateSwitchState = (state, row) => {
  row.status = state
}

const total = tableData.value.length

// 分页参数
const paginationData = ref({
  currentPage: 1,
  pageSize: 5
})

const currentTableData = ref()

// 根据分页参数计算当前显示的数据
function getPagedData(pageSize, currentPage) {
  const start = (currentPage - 1) * pageSize
  const end = start + pageSize
  const tables = []
  for (let i = start; i < end; i++) {
    if (tableData.value[i]) tables.push(tableData.value[i])
  }

  return (currentTableData.value = tables)
}

// 更新分页数据
function handlePageChange(pageSize, currentPage) {
  paginationData.value.pageSize = pageSize
  paginationData.value.currentPage = currentPage
  tableData.value = getPagedData(pageSize, currentPage)
}

onMounted(() => {
  handlePageChange(paginationData.value.pageSize, paginationData.value.currentPage)
})
</script>

<style lang="scss" scoped>
.operation {
  margin-bottom: 10px;
}
.hint {
  height: 33px;
  line-height: 33px;
  background-color: rgb(242, 250, 254);
  border: 1px solid rgb(193, 226, 252);
  border-radius: 5px;
  margin-bottom: 10px;
}
.avatar-uploader .avatar {
  width: 178px;
  height: 178px;
  display: block;
}
.avatar-uploader .el-upload {
  border: 1px dashed var(--el-border-color);
  border-radius: 6px;
  cursor: pointer;
  position: relative;
  overflow: hidden;
  transition: var(--el-transition-duration-fast);
}

.avatar-uploader .el-upload:hover {
  border-color: var(--el-color-primary);
}

.el-icon.avatar-uploader-icon {
  font-size: 28px;
  color: #8c939d;
  width: 178px;
  height: 178px;
  text-align: center;
}
</style>
