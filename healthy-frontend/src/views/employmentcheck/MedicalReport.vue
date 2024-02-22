<!-- 体检报告 -->
<template>
  <div class="container">
    <div class="left-main">
      <Head name="人员信息" style="font-size: 15px" />
      <el-form ref="formData" :model="searchData">
        <div class="search-input">
          <!-- 默认展开的输入框 -->
          <el-row :gutter="20">
            <el-col :span="8">
              <el-form-item prop="serialNumber" label="体检编号">
                <el-input v-model="searchData.serialNumber" placeholder="请输入体检编号" clearable />
              </el-form-item>
            </el-col>
            <el-col :span="8">
              <el-form-item prop="workplace" label="体检单位">
                <el-select v-model="searchData.workplace" placeholder="请选择" clearable>
                  <el-option label="测试单位" value="测试单位" />
                </el-select>
              </el-form-item>
            </el-col>
            <el-col :span="8">
              <el-form-item prop="reviewStatus" label="审核状态">
                <el-select v-model="searchData.reviewStatus" placeholder="请选择" clearable>
                  <el-option key="未审核" label="未审核" value="未审核" />
                  <el-option key="已审核" label="已审核" value="已审核" />
                </el-select>
              </el-form-item>
            </el-col>
          </el-row>
          <!-- 可展开的输入框 -->
          <div v-if="isShowInput" class="search-input">
            <el-row :gutter="20">
              <el-col :span="8">
                <el-form-item prop="idCard" label="身份证号">
                  <el-input v-model="searchData.idCard" placeholder="请输入身份证号" clearable />
                </el-form-item>
              </el-col>
              <el-col :span="8">
                <el-form-item prop="checkTime" label="体检日期">
                  <el-date-picker v-model="searchData.checkTime" type="date" placeholder="请选择" />
                </el-form-item>
              </el-col>
              <el-col :span="8">
                <el-form-item prop="userName" label="姓名">
                  <el-input v-model="searchData.userName" placeholder="请输入姓名" clearable />
                </el-form-item>
              </el-col>
              <el-col :span="8">
                <el-form-item prop="sex" label="性别">
                  <el-select v-model="searchData.sex" placeholder="请选择" clearable>
                    <el-option key="男" label="男" value="男" />
                    <el-option key="女" label="女" value="女" />
                  </el-select>
                </el-form-item>
              </el-col>
              <el-col :span="8">
                <el-form-item prop="age" label="年龄">
                  <el-input v-model="searchData.age" placeholder="请输入年龄" clearable />
                </el-form-item>
              </el-col>
            </el-row>
          </div>
        </div>
        <el-button type="primary" style="margin-left: 20px" @click="search">查询</el-button>
        <el-button type="primary" @click="reset">重置</el-button>
        <el-button type="text" style="margin-left: 14px" @click="toggleCollapse"
          >{{ isShowInput ? '收起' : '展开' }}
          <el-icon v-show="isShowInput == true"><ArrowUp /></el-icon>
          <el-icon v-show="isShowInput == false"><ArrowDown /></el-icon>
        </el-button>
      </el-form>
      <el-divider border-style="dashed" />
      <!-- 审核列表 -->
      <div>
        <el-button type="primary" style="margin-left: 20px; margin-bottom: 10px">
          <el-icon style="margin-right: 5px"><UploadFilled /></el-icon>批量审核
        </el-button>
        <BaseDataList
          ref="baseDataListRef"
          :use-form="false"
          :form-data="reviewData"
          :table-column-attribute="tableColumnAttribute"
          :table-data="tableData"
          :use-fixed="false"
          style="margin-left: 20px"
        />
      </div>
    </div>
    <div class="right-main">
      <Head name="检查详情" style="font-size: 15px" />
      <div class="center-content">暂无数据</div>
    </div>
  </div>
</template>

<script setup>
import Head from '@/components/head/Head.vue'
import BaseDataList from '@/components/basedatalist/BaseDataList.vue'
import { onMounted, ref } from 'vue'
import { ArrowUp, ArrowDown, UploadFilled } from '@element-plus/icons-vue'
/* BaseDataList的变量 */
const tableColumnAttribute = ref([
  { prop: 'id', label: '体检编号', width: 150, align: 'center' },
  { prop: 'idCard', label: '身份证号', width: 100, align: 'center' },
  { prop: 'userName', label: '姓名', width: 150, align: 'center' },
  { prop: 'sex', label: '性别', width: 250, align: 'center' },
  { prop: 'age', label: '年龄', width: 250, align: 'center' },
  { prop: 'checkTime', label: '体检日期', width: 250, align: 'center' },
  { prop: 'isQualified', label: '是否合格', width: 100, align: 'center' },
  { prop: 'untiName', label: '单位名称', width: 150, align: 'center' },
  { prop: 'reviewStatus', label: '审核状态', width: 250, align: 'center' }
])

// 获取用户输入数据或设置初值
const searchData = ref({
  serialNumber: '',
  workplace: '',
  reviewStatus: '',
  idCard: '',
  checkTime: '',
  userName: '',
  sex: '',
  age: ''
})
const formData = ref(null)
// 查询
const search = () => {
  console.log('查询', searchData.value.serialNumber)
}
// 重置
const reset = () => {
  formData.value.resetFields()
}
// 点击展开按钮按钮的折叠逻辑
const isShowInput = ref(false)
const toggleCollapse = () => {
  isShowInput.value = !isShowInput.value
}
</script>

<style lang="scss" scoped>
.container {
  display: flex;
}
.left-main {
  width: 65%;
}
.right-main {
  width: 35%;
}

.search-input .el-form-item {
  margin-bottom: 16px; /* 根据需要调整间距 */
}

.el-input,
.el-select {
  width: 180px;
}
</style>
<style>
.el-form-item__label {
  font-weight: 700;
  margin-left: 20px;
}
</style>
