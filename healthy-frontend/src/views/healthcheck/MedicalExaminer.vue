<!-- 体检人员 -->
<template>
  <el-container style="background-color: #f0f0f0; padding: 10px; height: 100%">
    <el-aside style="width: 20%" :style="{ maxWidth: isCollapsed ? '0' : '20%' }">
      <PeopleListPPZ title="团检人员">
        <template #form>
          <el-form :model="form">
            <el-form-item prop="date">
              <el-row clearable>
                <el-date-picker v-model="form.startDate" type="date" placeholder="开始时间" style="width: 46%" />
                <span style="width: 8%; padding: 0 4px">~</span>
                <el-date-picker v-model="form.endDate" type="date" placeholder="结束时间" style="width: 46%" />
              </el-row>
            </el-form-item>
            <el-form-item prop="name">
              <el-input v-model="form.name" placeholder="请输入关键字" clearable />
            </el-form-item>
            <el-button :size="small" @click="onSubmit">重置</el-button>
          </el-form>
        </template>

        <template #table>
          <List></List>
        </template>
      </PeopleListPPZ>

      <!-- <Peoplelist
        :table-column-attribute="tableColumnAttribute"
        :table-data="publicStore.tableData"
        :page-sizes="[5]"
        :total="publicStore.total"
        :use-select-column="false"
        @update-table-data="
          (pageSize, pageIndex) => {
            getTableData({
              pageSize,
              pageIndex
            })
          }
        "
        ref="PeopleListRef"
      ></Peoplelist> -->
    </el-aside>

    <div class="collapse" style="height: 100%; line-height: 100vh; margin: 4px" @click="isCollapsed = !isCollapsed">
      <el-icon v-show="isCollapsed == false"><ArrowLeft /></el-icon>
      <el-icon v-show="isCollapsed == true"><ArrowRight /></el-icon>
    </div>

    <el-main class="body">
      <!-- 中间部分：团检人员 -->
      <div class="center-part">
        <el-card class="title-operation">
          <el-row style="display: flex; align-items: center; justify-content: center">
            <span>团检人员</span>
            <el-button type="primary" style="margin-right: 12px" @click="uploadDialogVisible = true">
              <el-icon><Upload /></el-icon>
              导入
            </el-button>
            <!-- 导入按钮的对话框 -->
            <el-dialog v-model="uploadDialogVisible" width="50%" style="justify-content: left">
              <template #header>
                <h4>人员批量导入</h4>
              </template>
              <template #default>
                <el-upload style="border: 1px solid #c3c3c3" multiple>
                  <div class="el-upload__text" style="width: 800px; height: 150px; display: flex; justify-content: center; align-items: center">
                    <el-icon style="display: flex; justify-content: center; align-items: center" class="el-icon--upload"><UploadFilled /></el-icon>
                    请选择需要上传的文件
                  </div>
                </el-upload>
                <p>提示；</p>
                <p>1.请按模板填写数据，模板格式禁止调整</p>
                <p>2.导入会覆盖之前数据（请慎重操作）</p>
                <p>3.上传文件类型只能为"xls", "xlsx", "xlsm"</p>
              </template>
              <template #footer>
                <span class="dialog-footer">
                  <el-upload>
                    <el-button style="background-color: #2db7f5; border-color: #2db7f5; color: #fff; margin-right: 12px"> 模板下载</el-button>
                  </el-upload>
                  <el-button type="primary" style="margin-bottom: 10px" @click="uploadDialogVisible = false"> 关闭 </el-button>
                </span>
              </template>
            </el-dialog>

            <el-button type="primary" style="margin-right: 12px" @click="dialogFormVisible = true">
              <el-icon><CirclePlus /></el-icon>
              新增
            </el-button>
            <!-- 新增按钮的对话框 -->
            <el-dialog v-model="dialogFormVisible">
              <template #header>
                <h3>新增</h3>
              </template>
              <div class="tabs" style="display: flex; justify-content: space-between">
                <el-tabs v-model="activeName" @tab-click="handleClick">
                  <el-tab-pane label="基本信息" name="first"> </el-tab-pane>
                </el-tabs>
                <el-button type="primary" @click="idInfoTips"
                  ><el-icon style="margin-right: 10px"><Plus /></el-icon>读取二代身份证</el-button
                >
              </div>
              <el-col>
                <el-form ref="ruleFormRef" :model="ruleForm" :rules="rules" :inline="true" label-width="120px" style="padding: 16px 26px" status-icon>
                  <el-form-item label="人员姓名" required>
                    <el-input v-model="ruleForm.name" placeholder="强输入人员姓名" />
                  </el-form-item>
                  <el-form-item label="证件号码">
                    <el-input v-model="ruleForm.idNumber" placeholder="强输入证件号码" />
                  </el-form-item>
                  <el-form-item label="性别" required>
                    <el-radio-group v-model="ruleForm.gender" style="width: 200px">
                      <el-radio label="男" />
                      <el-radio label="女" />
                    </el-radio-group>
                  </el-form-item>
                  <el-form-item label="出生日期" required>
                    <el-form-item>
                      <el-date-picker v-model="ruleForm.birthday" type="date" placeholder="请选择" p style="width: 200px" />
                    </el-form-item>
                  </el-form-item>
                  <el-form-item label="年龄" required>
                    <el-input v-model="ruleForm.age" placeholder="强输入年龄" />
                  </el-form-item>
                  <el-form-item label="手机号码" required>
                    <el-input v-model="ruleForm.phoneNumber" placeholder="强输入手机号码" />
                  </el-form-item>
                  <el-form-item label="婚姻状况">
                    <el-select v-model="ruleForm.maritalStatus" placeholder="请选择" style="width: 200px">
                      <el-option label="未婚" value="未婚" />
                      <el-option label="已婚" value="已婚" />
                      <el-option label="离异" value="离异" />
                      <el-option label="丧偶" value="丧偶" />
                      <el-option label="其他" value="其他" />
                    </el-select>
                  </el-form-item>
                </el-form>
              </el-col>

              <template #footer>
                <el-button @click="dialogFormVisible = false">取消</el-button>
                <el-button type="primary" @click="submitForm">提交</el-button>
              </template>
            </el-dialog>

            <el-upload
              v-model:file-list="fileList"
              action="https://run.mocky.io/v3/9d059bf9-4660-45f2-925d-ce80ad6c4d15"
              multiple
              :on-preview="handlePreview"
              :on-remove="handleRemove"
              :before-remove="beforeRemove"
              :on-exceed="handleExceed"
              style="display: flex"
            >
              <el-button type="primary" style="margin-right: 12px">
                <el-icon><Download /></el-icon>
                导出
              </el-button>
            </el-upload>

            <el-upload
              v-model:file-list="fileList"
              action="https://run.mocky.io/v3/9d059bf9-4660-45f2-925d-ce80ad6c4d15"
              multiple
              :on-preview="handlePreview"
              :on-remove="handleRemove"
              :before-remove="beforeRemove"
              :on-exceed="handleExceed"
              style="display: flex"
            >
              <el-button type="primary">
                <el-icon><Download /></el-icon>
                导出订单
              </el-button>
            </el-upload>
          </el-row>
        </el-card>
        <div style="height: 95%">
          <el-card style="height: 100%" shadow="hover">
            <el-tabs type="border-card">
              <el-tab-pane label="男">
                <el-table :data="personInfo" border style="width: 100%; margin-top: 10px">
                  <el-table-column type="selection" width="55" />
                  <el-table-column prop="name" label="姓名" />
                  <el-table-column prop="result" label="性别" />
                  <el-table-column prop="reference" label="证件号码" />
                  <el-table-column prop="unit" label="年龄" />
                  <el-table-column prop="prompt" label="操作" />
                </el-table>
              </el-tab-pane>
              <el-tab-pane label="女">
                <el-table :data="personInfo" border style="width: 100%; margin-top: 10px">
                  <el-table-column type="selection" width="55" />
                  <el-table-column prop="name" label="姓名" />
                  <el-table-column prop="result" label="性别" />
                  <el-table-column prop="reference" label="证件号码" />
                  <el-table-column prop="unit" label="年龄" />
                  <el-table-column prop="prompt" label="操作" />
                </el-table>
              </el-tab-pane>

              <!-- 分页器 -->
              <el-pagination
                v-model:current-page="currentPage4"
                v-model:page-size="pageSize4"
                style="margin-top: 14px"
                :page-sizes="[10, 20, 50]"
                small="small"
                layout="->, total, prev, pager, next,sizes,  jumper"
                :total="0"
                @size-change="handleSizeChange"
                @current-change="handleCurrentChange"
              />
            </el-tabs>
          </el-card>
        </div>
      </div>

      <!-- 右边部分：订单信息 -->
      <div class="right-part" style="position: absolute; top: 0; right: 0; width: 40%; height: 100%">
        <el-card class="title-bar" body-style="font-weight: 700">订单信息</el-card>
        <el-card style="height: 30%" shadow="hover">
          <el-form ref="OrderInfoRef" :inline="true" :model="formInline" label-width="70px" style="font-size: 12px" disabled="true">
            <el-form-item label="体检单位" style="width: 155px">
              <el-input />
            </el-form-item>
            <el-form-item label="体检类型" style="width: 155px">
              <el-input />
            </el-form-item>
            <el-form-item label="体检时间" style="width: 155px">
              <el-input />
            </el-form-item>
            <el-form-item label="套餐金额" style="width: 155px">
              <el-input />
            </el-form-item>
            <el-form-item label="订单编号" style="width: 155px">
              <el-input />
            </el-form-item>
            <el-form-item label="签订时间" style="width: 155px">
              <el-input />
            </el-form-item>
            <el-form-item label="检查人数" style="width: 155px">
              <el-input />
            </el-form-item>
            <el-form-item label="销售人员" style="width: 155px">
              <el-input />
            </el-form-item>
          </el-form>
        </el-card>
        <el-card class="title-bar" body-style="font-weight: 700" style="margin-top: 6px">团体项目</el-card>
        <div style="height: 59%">
          <el-card style="height: 100%" shadow="hover">
            <el-table :data="personInfo" border style="width: 100%">
              <el-table-column prop="project" label="体检项目" />
              <el-table-column prop="originalPrice" label="原价(元)" />
              <el-table-column prop="discount" label="折扣(100%)" />
              <el-table-column prop="discountPrice" label="折扣价(元)" />
            </el-table>

            <!-- 分页器 -->
            <el-pagination
              v-model:current-page="currentPage4"
              v-model:page-size="pageSize4"
              style="margin-top: 14px"
              :page-sizes="[10, 20, 50]"
              small="small"
              layout="->, total, prev, pager, next"
              :total="0"
              @size-change="handleSizeChange"
              @current-change="handleCurrentChange"
            />
          </el-card>
        </div>
      </div>
    </el-main>
  </el-container>
</template>

<script setup>
import PeopleListPPZ from '@/components/peoplelist/PeopleList-PPZ.vue'
import List from '@/components/peoplelist/List.vue'
import { Upload, CirclePlus, Download, ArrowLeft, ArrowRight, UploadFilled, Plus } from '@element-plus/icons-vue'
import { ref } from 'vue'
import { defineProps, defineEmits } from 'vue'
import { ElMessage } from 'element-plus'
import { usePublicStore } from '@/stores/public/index.js'
// 定义方法调用仓库接口
const publicStore = usePublicStore()

// 定义表格列属性
const tableColumnAttribute = ref([
  {
    prop: 'PeopleName',
    label: '姓名'
  },
  {
    prop: 'gender',
    label: '性别'
  },
  {
    prop: 'age',
    label: '年龄'
  },
  {
    prop: 'tagType',
    label: '标签'
  }
])
const PeopleListRef = ref(null)
const rowId = ref('')
const getTableData = async (params) => {
  console.log('res')
  PeopleListRef.value.openLoading = !PeopleListRef.value.openLoading
  await publicStore.queryUesrnameList(params)
  PeopleListRef.value.openLoading = !PeopleListRef.value.openLoading
}

const form = ref({
  date: '',
  startDate: '',
  endDate: ''
})

const isCollapsed = ref(false)

const uploadDialogVisible = ref(false) // 导入按钮的弹出框

const dialogFormVisible = ref(false) //导出按钮的弹出框

const idInfoTips = () => {
  ElMessage.error('请安装身份证读卡器服务！')
}
const ruleForm = ref({
  name: '',
  idNumber: '',
  gender: '男',
  birthday: '',
  age: '',
  phoneNumber: '',
  maritalStatus: ''
})
const ruleFormRef = ref(null)
const rules = ref({
  name: [{ required: true, message: '人员姓名不能为空!', trigger: 'blur' }],
  idNumber: [{ message: '人员姓名不能为空!', trigger: 'blur' }],
  gender: [{ required: true, message: '性别不能为空!', trigger: 'change' }],
  birthday: [{ type: 'date', required: true, message: '出生日期不能为空!', trigger: 'blur' }],
  age: [{ required: true, message: '请输入正确的年龄!', trigger: 'blur' }],
  phoneNumber: [{ required: true, message: '手机号码有误!', trigger: 'change' }],
  maritalStatus: [{ message: '手机号码有误!', trigger: 'change' }]
})

// 订单信息表单罗辑
const OrderInfoRef = ref(null)

const submitForm = () => {
  console.log('提交成功')
  ElMessage({
    message: '提交成功',
    type: 'success'
  })
  dialogFormVisible.value = false
}

const props = defineProps({
  usePagination: {
    type: Boolean,
    default: true
  }
})
const emits = defineEmits(['updateTableData'])

// 分页数据的处理逻辑
const paginationData = ref({
  currentPage: 1,
  pageSize: props.pageSizes ? props.pageSizes[0] : 10
})

const handleSizeChange = (pageSize) => {
  // 当前页的数据容量改变，重置页码为1(因页面大小限制，每页条数固定值为10)
  paginationData.value.currentPage = 1
  // 传入当期那页面的容量大小和当前页面
  emits('updateTableData', pageSize, paginationData.value.currentPage)
}
const handleCurrentChange = (currentPage) => {
  paginationData.value.currentPage = currentPage
  // 传入当前页码容量(默认值10)和当前页码
  emits('updateTableData', paginationData.value.pageSize, currentPage)
}

defineExpose({
  paginationData
})
</script>

<style lang="scss" scoped>
.el-container {
  overflow: hidden;
}
.body {
  display: flex;
  position: relative;

  .center-part {
    height: 100%;
    position: absolute;
    top: 0;
    left: 0;
    width: 59%;
    align-items: center;
    justify-content: center;
    align-items: center;
  }
  .title-operation {
    height: 5%;
    font-size: 14px;
    display: flex;
    align-items: center;
    background-color: #f0faff;
    border: 1px solid #abdcff;

    span {
      margin-right: 15px;
      font-weight: 550;
      display: flex;
      justify-content: center;
      text-align: center;
      align-items: center;
    }
  }
  p {
    color: red;
    font-weight: bold;
    font-size: 14px;
  }

  .title-bar {
    height: 5%;
    font-size: 14px;
    font-weight: 550;
    display: flex;
    justify-content: center;
    align-items: center;
    background-color: #f0faff;
    border: 1px solid #abdcff;
  }
}
</style>
