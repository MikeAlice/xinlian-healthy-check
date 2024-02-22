<!-- 团检单位 -->
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
      @update-table-data="handlePageChange"
      @update-selected-rows="selectRows"
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
                <el-icon><DeleteFilled></DeleteFilled></el-icon>
                删除
              </el-dropdown-item>
            </el-dropdown-menu>
          </template>
        </el-dropdown>
      </template>

      <!-- form表单区域 -->
      <template #form>
        <el-form-item label="科室编码">
          <el-input v-model="formData.ksCoding"></el-input>
        </el-form-item>
        <el-form-item label="科室名称">
          <el-input v-model="formData.ksName"></el-input>
        </el-form-item>
        <el-form-item label="科室简拼">
          <el-input v-model="formData.ksLogogram"></el-input>
        </el-form-item>
        <el-form-item label="类型检查">
          <el-select v-model="formData.typeCheck" multiple style="width: 120px">
            <el-option v-for="item in options" :key="item.value" :label="item.label" :value="item.value"></el-option>
          </el-select>
        </el-form-item>
        <el-form-item>
          <el-button type="primary">
            <el-icon><Search></Search></el-icon>
            搜索
          </el-button>
        </el-form-item>
        <el-form-item>
          <el-button @click="resetForm">重置</el-button>
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
              <el-form-item label="*科室编码" label-width="90px">
                <el-input v-model="newForm.ksCode"></el-input>
              </el-form-item>
              <el-form-item label="*科室名称" label-width="90px">
                <el-input v-model="newForm.ksName"></el-input>
              </el-form-item>
              <el-form-item label="*科室简拼" label-width="90px">
                <el-input v-model="newForm.ksLogogram"></el-input>
              </el-form-item>
              <el-form-item label="*排序" label-width="90px">
                <el-input v-model="newForm.sort"></el-input>
              </el-form-item>
              <el-form-item label="联系人" label-width="90px">
                <el-input v-model="newForm.contactPeople"></el-input>
              </el-form-item>
              <el-form-item label="联系电话" label-width="90px">
                <el-input v-model="newForm.contactPhone"></el-input>
              </el-form-item>
              <el-form-item label="检查类型" label-width="90px">
                <el-select v-model="newForm.typeCheck" multiple>
                  <el-option v-for="item in newOptions" :key="item.value" :label="item.label" :value="item.value" />
                </el-select>
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
import { ArrowDown, Search, Plus, InfoFilled, Refresh, DeleteFilled, Bottom, View, Edit } from '@element-plus/icons-vue'
import BaseDataList from '@/components/basedatalist/BaseDataList.vue'

const useHint = ref(true)
const useForm = ref(true)
const usePagination = ref(true)
const BaseDataRef = ref()
const dialogVisible = ref(false)
const useFixed = ref(true)

// 新增功能表单内容是否禁用
// const formDisabled = ref(false)

// table列数据
const tableColumnAttribute = ref([
  { prop: 'ksCode', label: '科室编码', width: '240', align: 'center' },
  { prop: 'ksName', label: '科室名称', width: '240', align: 'center' },
  { prop: 'ksLogogram', label: '科室简拼', width: '240', align: 'center' },
  { prop: 'sort', label: '排序', width: '240', align: 'center' },
  { prop: 'contactPeople', label: '联系人', width: '240', align: 'center' },
  { prop: 'contactPhone', label: '联系人电话', width: '240', align: 'center' },
  { prop: 'typeCheck', label: '检查类型', width: '240', align: 'center' }
])

// table数据
const tableData = ref([
  {
    ksCode: '002',
    ksName: '检验科',
    ksLogogram: 'JYK',
    sort: '1',
    contactPeople: 'likk',
    contactPhone: '110',
    typeCheck: '健康体检,职业体检,从业体检'
  }
])

// 表单数据
const formData = reactive({
  ksCoding: '',
  ksName: '',
  ksLogogram: '',
  typeCheck: ''
})

// 表单选择器数据
const options = ref([
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

// 新增功能中表单数据
const newForm = reactive({
  ksCode: '',
  ksName: '',
  ksLogogram: '',
  sort: '',
  contactPeople: '',
  contactPhone: '',
  typeCheck: ''
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
  console.log(newForm.value)
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
