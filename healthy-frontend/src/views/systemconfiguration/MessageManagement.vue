<template>
  <div class="contain">
    <!-- 新增对话框区域 -->
    <el-dialog v-model="dialogVisible" title="新增" width="60%" :before-close="handleClose">
      <el-row style="height: 400px">
        <el-col :span="20">
          <el-form :model="basicForm">
            <el-form-item label="标题" :label-width="labelWidth">
              <el-input v-model="basicForm.title" placeholder="请输入"></el-input>
            </el-form-item>
            <el-form-item label="消息类型" :label-width="labelWidth">
              <el-select v-model="basicForm.type"></el-select>
            </el-form-item>
            <el-form-item label="内容" :label-width="labelWidth">
              <el-input type="textarea" :autosize="{ minRows: 4 }" v-model="basicForm.content"
                placeholder="请输入"></el-input>
            </el-form-item>
            <el-form-item label="新创建账号推送">
              <el-switch v-model="basicForm.push" inline-prompt active-text="是" inactive-text="否"
                @change="(state) => emits('updateSwitchState', state, row)"></el-switch>
            </el-form-item>
            <el-form-item label="发送范围" :label-width="labelWidth">
              <el-radio-group v-model="basicForm.range">
                <el-radio label="1" size="large" @click="hidePeople">全体用户</el-radio>
                <el-radio label="2" size="large" @click="showPeople">指定用户</el-radio>
              </el-radio-group>
            </el-form-item>
            <el-form-item :class="style" label="选择用户" :label-width="labelWidth">
              <div style="width: 100%; margin: 10px">
                <CheckItems bottonTitle="请选择"></CheckItems>
              </div>
              <div style="width: 100%; margin-inline: 30px">已选择 <span style="color: RGB(64, 158, 255)">{{ peopleNum
              }}</span> 人
              </div>
            </el-form-item>
          </el-form>
        </el-col>
      </el-row>
      <template #footer>
        <span class="dialog-footer">
          <el-button @click="dialogVisible = false">取消</el-button>
          <el-button type="primary" @click="dialogVisible = false">提交</el-button>
        </span>
      </template>
    </el-dialog>
    <BaseDataList ref="BaseDataRef" use-form :form-data="formData" :table-data="tableData"
      :table-column-attribute="tableColumnAttribute" :total="total" use-pagination
      :pagination-data="paginationData" :handle-edit="handleEdit" use-fixed
      @update-table-data="handlePageChange" @update-selected-rows="selectRows">
      <!-- fixed固定列 -->
      <!-- 表格后面的操作选项群 -->
      <template #fixed="{ row }">
        <el-button type="primary" :icon="View" style="margin-right: 5px" @click="handelLook(row)">查看</el-button>
        <el-button type="danger" style="margin-right: 5px" @click="handleCancel(row)">撤回</el-button>
      </template>

      <!-- form表单区域 -->
      <template #form>
        <el-form-item label="消息标题">
          <el-input v-model="formData.title" :style="{ width: '200px' }"></el-input>
        </el-form-item>
        <el-form-item label="消息内容">
          <el-input v-model="formData.content" :style="{ width: '200px' }"></el-input>
        </el-form-item>
        <div v-if="isShowInput" class="expend">
          <el-form-item label="消息类型">
            <el-input v-model="formData.type" :style="{ width: '230px' }"></el-input>
          </el-form-item>
          <el-form-item label="报告日期" prop="date">
            <el-date-picker v-model="formData.date" placeholder="请选择日期" />
          </el-form-item>
        </div>

        <el-form-item>
          <el-button type="primary">
            <el-icon>
              <Search></Search>
            </el-icon>
            搜索
          </el-button>
        </el-form-item>
        <el-form-item>
          <el-button @click="resetForm">重置</el-button>

          <el-button type="text" style="margin-left: 20px" @click="toggleCollapse">{{ isShowInput ? '收起' : '展开' }}
            <el-icon v-show="isShowInput === true">
              <ArrowUp />
            </el-icon>
            <el-icon v-show="isShowInput === false">
              <ArrowDown />
            </el-icon>
          </el-button>
        </el-form-item>
      </template>

      <!-- operation功能区域 -->
      <template #operation>
        <div class="operation">
          <el-button type="primary" :icon="Plus" @click="dialogVisible = true">发送新消息</el-button>
          <el-button type="danger" :icon="Delete" @click="open">批量撤回</el-button>
          <el-button type="primary" :icon="Refresh">刷新</el-button>

          <el-button @click="closeForm">关闭搜索</el-button>
          <el-button @click="closeHint">关闭提示</el-button>
        </div>
      </template>

      <!-- 多选清除栏 -->
      <template #hint>
        <div v-if="useHint" class="hint">
          <span>
            <el-icon style="color: blue">
              <InfoFilled></InfoFilled>
            </el-icon>
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
import { ElMessage } from 'element-plus'
import { ArrowUp, ArrowDown, Search, InfoFilled, View, Refresh, Plus, Delete } from '@element-plus/icons-vue'
import BaseDataList from '@/components/basedatalist/BaseDataList.vue'
import CheckItems from '@/components/checkItems/CheckItems.vue'
import { useMessageModuleStores } from '@/stores/messagemodule/index.js'

/* Stores中的方法 */
const messageModuleStore = useMessageModuleStores()

const useHint = ref(true)
const useForm = ref(true)
const BaseDataRef = ref()
const dialogVisible = ref(false)
const labelWidth = '125px'
// table列
const tableColumnAttribute = ref([
  { prop: 'title', label: '消息标题' },
  { prop: 'content', label: '消息内容' },
  { prop: 'type', label: '消息类型' },
  { prop: 'push', label: '新创建账号推送' },
  { prop: 'range', label: '发送范围' },
  { prop: 'date', label: '创建时间' }
])


//初始化方法
created:{
  //加载table数据
  const result = messageModuleStore.MessageQueryAllStore(formData)
  const data = res
  if(result.code === 200){
    //渲染数据
    const data = result.data
    tableData = data
  }
}

// table数据
const tableData = ref([
  {
    title: 'test title',
    content: 'test content',
    type: 'one',
    push: 'yes',
    range: 'test1',
    date: '2233-12-2'
  },
  {
    title: 'test title',
    content: 'test content',
    type: 'one',
    push: 'yes',
    date: '2233-12-2'
  }
])
function handelLook(row) {
  //发送获取消息详情请求
  // const result = messageModuleStore.MessageSendQueryStore(row[id])
  // if(result.code === 200){
  //   //弹框
  // }
  console.log(row)
}

function handleCancel(row) {
  console.log(row)
  open()
}

const formData = reactive({
  title: '',
  content: '',
  type: ''
})

// 点击展开按钮按钮的折叠逻辑
const isShowInput = ref(false)
const toggleCollapse = () => {
  isShowInput.value = !isShowInput.value
}

// 新增消息
// 基础信息表单
const basicForm = ref({
  title: '',
  content: '',
  push: false,
  range: '1',
  type: ''
})

const style = ref('hide')
function showPeople() {
  style.value = 'show'
}
function hidePeople() {
  style.value = 'hide'
}

const peopleNum = ref(0)

const closeForm = () => {
  useForm.value = !useForm.value
}
const closeHint = () => {
  useHint.value = !useHint.value
}
// 编辑功能
const handleEdit = (row) => {
  console.log(row)
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
  BaseDataRef.value.clearForm()
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

const idArray = ref([])
const open = () => {
  // eslint-disable-next-line no-undef
  ElMessageBox.confirm(
    '你确定撤回吗',
    '提示',
    {
      confirmButtonText: '确定',
      cancelButtonText: '取消',
      type: 'warning'
    }
  )
    .then(() => {
              //发送删除消息请求
              for(const key in selectRows){
                  idArray.push(selectRows[key])
              }
              const result = messageModuleStore.removeByIdsStore(idArray)
              if(result.code != 200){
                return
              }
      ElMessage({
        type: 'success',
        message: '撤回成功'
      })
    })
    .catch(() => {
      ElMessage({
        type: 'info',
        message: '撤回取消',
      })
    })
}
</script>

<style lang="scss" scoped>
.expend {
  display: isShowInput;
}

.operation {
  margin-bottom: 10px;
}

.hide {
  display: none;
}

.show {
  display: flex;
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
}</style>
