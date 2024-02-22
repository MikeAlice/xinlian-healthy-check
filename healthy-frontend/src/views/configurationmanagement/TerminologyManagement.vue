<!-- 术语管理 -->
<template>
  <el-card>
    <div class="contain">
      <el-container>
        <el-aside :width="leftWidth" style="margin-left: 10px">
          <div v-if="leftVisible" class="left">
            <div class="choice">
              <el-icon style="color: rgb(45, 140, 240)"><InfoFilled></InfoFilled></el-icon>
              <span> 当前选择:</span>
            </div>
            <div class="search">
              <el-input v-model="searchInput" placeholder="输入搜索科室" style="width: 100%"> </el-input>
            </div>
            <el-scrollbar height="630px">
              <div class="department">
                <ul class="departmentUl">
                  <li v-for="item in departmentArr" :key="item" class="departmentLi">
                    <span class="departmentItem">{{ item.name }}</span>
                  </li>
                </ul>
              </div>
            </el-scrollbar>
          </div>
        </el-aside>
        <el-main>
          <div class="main" style="display: flex">
            <div class="expend" style="margin-right: 10px">
              <i>
                <el-icon v-if="leftGo" @click="collectLeft"><ArrowLeftBold></ArrowLeftBold></el-icon>
              </i>
              <i>
                <el-icon v-if="leftBack" @click="returnLeft"><ArrowRightBold></ArrowRightBold></el-icon>
              </i>
            </div>
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
                        <el-icon><DeleteFilled></DeleteFilled></el-icon>
                        删除
                      </el-dropdown-item>
                    </el-dropdown-menu>
                  </template>
                </el-dropdown>
              </template>

              <!-- form表单区域 -->
              <template #form>
                <el-form-item label="体检类型">
                  <el-select v-model="formData.bgType" style="width: 130px">
                    <el-option v-for="item in tjTypeOptions" :key="item.value" :label="item.label" :value="item.value" />
                  </el-select>
                </el-form-item>
                <el-form-item label="术语类型">
                  <el-select v-model="formData.mbType" style="width: 130px">
                    <el-option v-for="item in syTypeOptions" :key="item.value" :label="item.label" :value="item.value"></el-option>
                  </el-select>
                </el-form-item>
                <el-form-item label="危害因素">
                  <el-select v-model="formData.projectName" style="width: 130px">
                    <el-option v-for="item in dangerFactorsOptions" :key="item.value" :label="item.label" :value="item.value"></el-option>
                  </el-select>
                </el-form-item>
                <el-form-item label="在岗状态">
                  <el-select v-model="formData.mbState" style="width: 130px">
                    <el-option v-for="item in zgStateOptions" :key="item.value" :label="item.label" :value="item.value"></el-option>
                  </el-select>
                </el-form-item>
                <div v-if="isVisible" class="visible">
                  <el-form-item label="术语内容">
                    <el-input style="width: 130px"></el-input>
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
                      <el-form-item label="*科室名称" label-width="90px">
                        <el-select :model="newForm.ksName"></el-select>
                      </el-form-item>
                      <el-form-item label="*体检类型" label-width="90px">
                        <el-select :model="newForm.tjType"></el-select>
                      </el-form-item>
                      <el-form-item label="*术语类型" label-width="90px">
                        <el-select :model="newForm.syType"></el-select>
                      </el-form-item>
                      <el-form-item label="*危害因素" label-width="90px">
                        <el-select :model="newForm.dangerFactors"></el-select>
                      </el-form-item>
                      <el-form-item label="*在岗状态" label-width="90px">
                        <el-select :model="newForm.zgStatus"></el-select>
                      </el-form-item>
                      <el-form-item label="*状态" label-width="90px">
                        <el-radio-group v-model="newForm.status" class="ml-4">
                          <el-radio label="启用" size="large">启用</el-radio>
                          <el-radio label="停用" size="large">停用</el-radio>
                        </el-radio-group>
                      </el-form-item>
                      <el-form-item label="*术语内容" label-width="90px">
                        <el-input v-model="newForm.syContent" :rows="2" type="textarea" placeholder="请输入术语内容" />
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
        </el-main>
      </el-container>
    </div>
  </el-card>
</template>

<script setup>
import { ref, reactive, onMounted } from 'vue'
import { ArrowDown, ArrowLeftBold, ArrowRightBold, Search, Plus, InfoFilled, Refresh, DeleteFilled, Bottom, View, Edit, ArrowDownBold, ArrowUpBold, Warning } from '@element-plus/icons-vue'
import BaseDataList from '@/components/basedatalist/BaseDataList.vue'

const useHint = ref(true)
const useForm = ref(true)
const usePagination = ref(true)
const BaseDataRef = ref()
const dialogVisible = ref(false)
const useFixed = ref(true)

// 输入搜索科室绑定的数据
const searchInput = ref('')

// 科室数据
const departmentArr = ref([
  { name: '007' },
  { name: '检验科' },
  { name: '电测听' },
  { name: '彩超室' },
  { name: 'DR室' },
  { name: 'CT室' },
  { name: '肺功能' },
  { name: '一般检查' },
  { name: '内科' },
  { name: '外科' },
  { name: '妇科' },
  { name: '口腔科' },
  { name: '眼科' },
  { name: '五官科' },
  { name: '皮肤科' },
  { name: '骨密度' },
  { name: '问诊科' },
  { name: '总检科' },
  { name: '辅助检查科室' },
  { name: '销售' }
])

// 控制箭头方向
const leftGo = ref(true)

const leftBack = ref(false)

// 控制左部显隐
const leftVisible = ref(true)

// 动态控制左部宽度
const leftWidth = ref('150px')

// 收起左部
const collectLeft = () => {
  leftWidth.value = '0'
  leftGo.value = false
  leftBack.value = true
}

// 展开左部
const returnLeft = () => {
  leftWidth.value = '150px'
  leftGo.value = true
  leftBack.value = false
}

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
  { prop: 'ksName', label: '科室名称', width: '120', align: 'center' },
  { prop: 'tjType', label: '体检类型', width: '120', align: 'center' },
  { prop: 'syType', label: '术语类型', width: '150', align: 'center' },
  { prop: 'dangerFactors', label: '危害因素', width: '120', align: 'center' },
  { prop: 'zgStatus', label: '在岗状态', width: '120', align: 'center' },
  { prop: 'status', label: '状态', width: '120', align: 'center', useSwitch: true },
  { prop: 'syContent', label: '', width: '180', align: 'center' },
  { prop: 'createTime', label: '创建时间', width: '150', align: 'center' }
])

// table数据
const tableData = ref([
  {
    ksName: '肺功能',
    tjType: '职业体检',
    syType: '诊断小结',
    dangerFactors: '溴甲烷',
    zgStatus: '---',
    status: true,
    syContent: '它能干扰细胞代谢，造成神经系统、肺、肾、肝及心血管系统的损害',
    createTime: '---'
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

// 表单选择器数据tjType
const tjTypeOptions = ref([
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
  }
])

// 表单选择器数据syType
const syTypeOptions = ref([
  {
    value: '职业检查结果'
  },
  {
    value: '医学建议'
  }
])

// 表单选择器数据dangerFactors
const dangerFactorsOptions = ref([
  {
    value: '职业危害因素'
  }
])

// 表单选择器数据zgState
const zgStateOptions = ref([
  {
    value: '上岗前'
  },
  {
    value: '在岗期间'
  },
  {
    value: '离岗时'
  },
  {
    value: '离岗后'
  },
  {
    value: '应急健康检查'
  }
])

// 新增功能中表单数据
const newForm = reactive({
  ksName: '',
  tjType: '',
  syType: '',
  dangerFactors: '',
  zgStatus: '',
  status: '',
  syContent: '',
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

// 左部
.left {
  width: 150px;
}
.choice {
  margin-top: 15px;
  height: 40px;
  line-height: 40px;
  border: 1px solid rgb(171, 220, 255);
  border-radius: 5px;
  background-color: rgb(240, 250, 255);
}

.search {
  margin-top: 10px;
}
.departmentUl {
  padding-left: 10px;
  list-style-type: none;
  color: rgb(97, 98, 110);
}

.departmentLi {
  margin-top: 10px;
}

.departmentItem {
  cursor: pointer;
}
.departmentItem:hover {
  background-color: rgb(234, 244, 254);
}

.expend {
  padding-top: 363px;
  cursor: pointer;
}
</style>
