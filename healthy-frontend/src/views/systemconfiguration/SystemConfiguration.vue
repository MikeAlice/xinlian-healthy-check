<!-- 系统配置 -->
<template>
  <el-radio-group v-model="tabPosition" style="margin-bottom: 30px">
    <el-radio-button label="top">top</el-radio-button>
    <el-radio-button label="right">right</el-radio-button>
    <el-radio-button label="bottom">bottom</el-radio-button>
    <el-radio-button label="left">left</el-radio-button>
  </el-radio-group>

  <el-tabs :tab-position="tabPosition" style="height: 700x" class="demo-tabs">
    <!-- 文件对象存储配置 -->
    <el-tab-pane label="文件对象存储配置"><!-- 表单 -->
      <div>文件对象存储配置</div>
      <el-form :label-position="right" :inline="true" :model="formInline" class="demo-form-inline">
        <el-col :span="24">
        <el-form-item  label="服务提供商" class="bold-label">
      <el-select v-model="formInline.fwtgs" class="m-2" placeholder="请选择" size="large" style="width: 240px">
    <el-option v-for="item in props.ksmcsw " :key="item" :label="item.label" :value="item.value"/>
  </el-select>
</el-form-item>
</el-col>
<el-form-item  label="accessKey" class="bold-label">
  <el-input v-model="formInline.acckey"  placeholder="请输入accessKey"/>
</el-form-item>
<el-form-item  label="secretKey" class="bold-label">
  <el-input type="password" show-password v-model="formInline.seckey"  placeholder="请输入secretKey"/>
</el-form-item>
<el-form-item  label="bucket空间" class="bold-label">
  <el-input v-model="formInline.bucket"   placeholder="请输入bucket空间名"/>
</el-form-item>
<el-form-item  label="endpoint域名" class="bold-label">
  <el-input v-model="formInline.endpointym"   class="input-with-select" placeholder="请输入空间访问域名">
    <template #prepend>
        <el-select v-model="select" placeholder="Select" style="width: 115px">
          <el-option label="Restaurant" value="1" />
          <el-option label="Order No." value="2" />
          <el-option label="Tel" value="3" />
        </el-select>
      </template>
  </el-input>
</el-form-item>
</el-form>

          <el-button
            type="primary"
            @click="onSubmit();resetFrom()"
          >
            保存并启用
          </el-button>
    </el-tab-pane>

    <!-- 短信配置 -->
    <el-tab-pane label="短信配置">
      <div>短信配置</div>
     <el-form :label-position="right" :inline="true" :model="formInline" class="demo-form-inline">
        <el-col :span="24">
        <el-form-item  label="服务提供商" class="bold-label">
      <el-select v-model="dxpz.fwtgs" class="m-2" placeholder="请选择" size="large" style="width: 240px">
    <el-option v-for="item in props.ksmcsw " :key="item" :label="item.label" :value="item.value"/>
  </el-select>
</el-form-item>
</el-col>
<el-form-item  label="accessKey" class="bold-label">
  <el-input v-model="dxpz.acckey"  placeholder="请输入accessKey"/>
</el-form-item>
<el-form-item  label="secretKey" class="bold-label">
  <el-input type="password" show-password v-model="dxpz.seckey"  placeholder="请输入secretKey"/>
</el-form-item>
<el-form-item  label="短信签名" class="bold-label">
  <el-input v-model="dxpz.dxqm"   placeholder="请输入短信签名,例如XBoot"/>
</el-form-item>
 <el-form-item  label="使用场景" class="bold-label">
      <el-select v-model="dxpz.sycj" class="m-2" placeholder="请选择" size="large" style="width: 240px">
    <el-option v-for="item in props.ksmcsw " :key="item" :label="item.label" :value="item.value"/>
  </el-select>
</el-form-item>
<el-form-item  label="模板CODE" class="bold-label">
  <el-input v-model="dxpz.mbCode"  placeholder="请输入场景对应短信模板CODE，例如SMS_123456789"/>
</el-form-item>
</el-form>

<el-button
            type="primary"
            @click="onSubmit();resetFrom()"
          >
            保存更改
          </el-button>
    </el-tab-pane>

    <el-tab-pane label="邮件配置">
      <idv>邮件配置</idv>
      <el-form :label-position="right" :inline="true" :model="formInline" class="demo-form-inline">
        <el-col>
<el-form-item  label="邮箱服务器" class="bold-label">
  <el-input v-model="yjpz.yxfwq"  placeholder="请输入邮箱服务器HOST,例如QQ邮箱为smtp.qq.com"/>
</el-form-item>
<el-form-item  label="发送邮箱账号" class="bold-label">
  <el-input v-model="yjpz.fsyxzh"  placeholder="请输入发送者Email账号"/>
</el-form-item>
<el-form-item  label="邮箱授权码" class="bold-label">
  <el-input type="password" show-password v-model="yjpz.yxsqm"  placeholder="请输入邮箱授权码,进入邮箱-设置中可找到"/>
</el-form-item>
</el-col>
</el-form>

<el-button
            type="primary"
            @click="onSubmit();resetFrom()"
          >
            保存更改
          </el-button>
    </el-tab-pane>

    <!-- Vaptcha验证码配置 -->
    <el-tab-pane label="Vaptcha验证码">
      <div>Vaptcha验证码配置</div>
        <el-form :label-position="right" :inline="true" :model="formInline" class="demo-form-inline">
        <el-row>
          
<el-form-item  label="VID" class="bold-label">
  <el-input v-model="vyzmpz.vid"  placeholder="请输入验证单元VID"/>
</el-form-item>
<el-form-item  label="secretKey" class="bold-label">
  <el-input type="password" show-password v-model="vyzmpz.seckey"  placeholder="请输入验证单元Key"/>
</el-form-item>
</el-row>
</el-form>

<el-button
            type="primary"
            @click="onSubmit();resetFrom()"
          >
            保存更改
          </el-button>
    </el-tab-pane>

    <!-- 禁用词管理 -->
    <el-tab-pane label="禁用词管理">
  <div class="container">
    <BaseDataList
      ref="BaseDataRef"
      :use-form="useForm"
      :childrenData="childrenData"
      :form-data="formData"
      :table-data="tableData"
      :table-column-attribute="tableColumnAttribute"
      :total="total"
      :use-pagination="usePagination"
      :pagination-data="paginationData"
      :handle-edit="handleEdit"
      :use-fixed="useFixed"
      @update-table-data="handlePageChange"
      @update-selected-rows="selectRows"
      @update-selected-row="selectRow"
    >
      <!-- fixed固定列 -->
      <template #fixed="{ row }">
        <el-button type="primary" style="margin-right: 5px" @click="handleEdit(row)">
          <el-icon><View></View></el-icon>
          编辑
        </el-button>
          <el-button type="primary" style="margin-right: 5px" @click="handleDel(row)">
            删除
            <el-icon class="el-icon--right">
            </el-icon>
          </el-button>
      </template>

      <!-- form表单区域 -->
      <template #form>
        <el-form-item >
          <el-input v-model="formDataForSearch.search1" placeholder="请输入名称搜索"></el-input>
        </el-form-item>
        <el-form-item>
          <el-button type="primary">
            <el-icon><Search></Search></el-icon>
            搜索
          </el-button>
        </el-form-item>
        <el-form-item>
          <el-button @click="resetFormForJyc">重置</el-button>
        </el-form-item>
      </template>

      <!-- operation功能区域 -->
      <template #operation>
        <div class="operation">
          <el-button type="primary" style="margin-right: 10px" @click="dialogVisible = true">
            <el-icon><Plus></Plus></el-icon>
            添加
          </el-button>
          <!-- 新增对话框区域 -->
          <el-dialog v-model="dialogVisible" title="新增" width="60%" :before-close="handleClose">
            <el-row data="rowData">
              <el-col :span="20">
                <el-form :model="basicForm" inline>
                  <el-form-item >
                    <el-input type="hidden" v-model="basicForm.id"  style="width: 232px" disabled=isDisabled></el-input>
                  </el-form-item>
                  <el-form-item label="类型名称" :label-width="labelWidth">
                    <el-input v-model="basicForm.lxmc" placeholder="请输入类型名称" style="width: 232px" disabled=isDisabled></el-input>
                  </el-form-item>
                  <el-form-item label="类型编码" :label-width="labelWidth">
                    <el-input v-model="basicForm.lxbm" placeholder="请输入类型编码" style="width: 232px" disabled=isDisabled></el-input>
                  </el-form-item>
                  <el-form-item label="上级类型" :label-width="labelWidth">
                    <el-select v-model="basicForm.sjlx" style="width: 232px" disabled=isDisabled></el-select>
                  </el-form-item>
                  <el-form-item label="排序" :label-width="labelWidth">
                    <el-input v-model="basicForm.px" default="0" style="width: 232px" disabled=isDisabled></el-input>
                  </el-form-item>
                  <el-form-item label="备注" :label-width="labelWidth">
                    <el-input type="textarea" v-model="basicForm.bz" style="width: 232px" placeholder="请输入备注" disabled=isDisabled></el-input>
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
          <el-dropdown>
            <el-button style="margin-right: 8px">
              批量删除
              <el-icon class="el-icon--right"> <arrow-down /> </el-icon
            ></el-button>
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
    </el-tab-pane>
    
    <!-- 系统公告配置 -->
    <el-tab-pane label="系统公告配置">
      <div>系统公告配置</div>
      <el-form :label-position="right" :inline="true" :model="formInline" class="demo-form-inline">
<el-form-item  label="公告开关" class="bold-label">
  <el-switch v-model="xtggpz.ggkg">
    <template #active-action>
      <span class="custom-active-action">开</span>
    </template>
    <template #inactive-action>
      <span class="custom-inactive-action">关</span>
    </template>
  </el-switch>
</el-form-item>
<el-form-item  label="展示时长" class="bold-label">
  <el-input v-model="xtggpz.zssc"  default="10"/>秒
</el-form-item>
<el-form-item  label="展示页面" class="bold-label">
  <el-select v-model="xtggpz.zsym" style="width: 232px" >\
  </el-select>
</el-form-item>
<el-form-item  label="公告标题" class="bold-label">
  <el-input v-model="xtggpz.ggbt"  />
</el-form-item>
<el-form-item  label="公告内容" class="bold-label">
  <el-input type="textarea" v-model="xtggpz.ggnr"  />
</el-form-item>
</el-form>

<el-button
            type="primary"
            @click="onSubmit();resetFrom()"
          >
            保存更改
          </el-button>
      </el-tab-pane>

      <!-- 其它配置 -->
    <el-tab-pane label="其他配置">
    <div>其他配置</div>
    <el-form :label-position="right" :inline="true" :model="formInline" class="demo-form-inline">
        <el-col>
<el-form-item  label="应用部署域名" class="bold-label">
  <el-input v-model="qtpz.yybsym"  placeholder="请输入应用部署域名" default="http://scmt.jay.com"/>
</el-form-item>
<el-form-item  label="单点登录域名" class="bold-label">
  <el-input v-model="qtpz.dddlym"  placeholder="请输入单点登录域名" default="jay.com"/>
</el-form-item>
<el-form-item  label="ip黑名单" class="bold-label">
  <el-input type="textarea"  v-model="qtpz.iphmd"  placeholder="多个回车分隔"/>
</el-form-item>
</el-col>
</el-form>

<el-button
            type="primary"
            @click="onSubmit();resetFrom()"
          >
            保存更改
          </el-button>
    </el-tab-pane>
  </el-tabs>
</template>
<script lang="ts" setup>
import { ref,reactive,onMounted } from 'vue'
import { ElMessage } from 'element-plus'
import { ArrowDown, Search, Plus, InfoFilled, Refresh, DeleteFilled, Bottom, View, Edit } from '@element-plus/icons-vue'
import BaseDataList from '@/components/basedatalist/BaseDataList.vue'

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

// 文件对象存储配置数据字段
const formInline = reactive({
  fwtgs: '',
  acckey: '',
  seckey: '',
  bucket:'',
  endpointym:''
})

// 短信配置数据字段
const dxpz = reactive({
  fwtgs: '',
  acckey: '',
  seckey: '',
  dxqm:'',
  sycj:'',
  mbCode:''
})
// 邮件配置数据字段
const yjpz = reactive({
  yxfwq: '',
  fsyxzh: '',
  yxsqm: ''
})
// Vaptcha验证码配置数据字段
const vyzmpz = reactive({
  vid: '',
  seckey: ''
})
// 系统公告配置数据字段
const xtggpz = reactive({
  ggkg: '',
  zssc: '',
  zsym: '',
  ggbt: '',
  ggnr: ''
})
// 其它配置数据字段
const qtpz = reactive({
  yybsym: 'http://scmt.jay.com',
  dddlym: 'jay.com',
  iphmd: ''
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

const tabPosition = ref('left')



// 禁用词管理-table
const isDisabled = ref(false)
const childrenData = ref(true)
const selectValue = ref('')
const useHint = ref(true)
const useForm = ref(true)
const usePagination = ref(true)
const BaseDataRef = ref()
const dialogVisible = ref(false)
const useFixed = ref(true)
const labelWidth = '125px'
// table列
const tableColumnAttribute = ref([
  { prop: 'jyc', label: '禁用词', width: '360', align: 'center' },
  { prop: 'cjsj', label: '创建时间', width: '360', align: 'center' },
  { prop: 'gxsj', label: '更新时间', width: '360', align: 'center' }
])
// table数据
const tableData = ref([
  {
    id: 1,
    jyc: '好人',
    cjsj: '2024-1-31 17:40:16',
    gxsj: '2024-1-31 17:40:16',
  },
  {
    id: 2,
    jyc: 'underfined',
    cjsj: '2024-1-28 17:40:16',
    gxsj: '2024-1-28 17:40:16',
  },
  {
    id: 3,
    jyc: '坏孩子',
    cjsj: '2024-1-27 17:40:16',
    gxsj: '2024-1-27 17:40:16',
  }
])
function handelLook(row) {

   for(const key in row){
    basicForm[key] = row[key]
   }
   isDisabled.value = true
   dialogVisible.value = true
}

//修改单条数据
function editLxk(row) {

for(const key in row){
 basicForm[key] = row[key]
}
isDisabled.value = false
dialogVisible.value = true
}
const formDataForSearch = reactive({
 search1:''
})
const formData = reactive({
  SampleName: '',
  SampleCode: '',
  contactPerson: '',
  contactPhone: ''
})
// 基础信息表单
const basicForm = reactive({
  id:'',
  jyc: '',
  cjsj: '',
  gxsj: ''
})
// 联系人表单
const contactForm = reactive({
  people: '',
  phone: ''
})
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
// 删除功能
const handleDel = (row) => {
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
const resetFormForJyc = () => {
  for(const key in formDataForSearch){
    formDataForSearch[key] = ''
  }
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
<style>
.demo-tabs > .el-tabs__content {
  padding: 32px;
  color: #6b778c;
  font-size: 32px;
  font-weight: 600;
}

.el-tabs--right .el-tabs__content,
.el-tabs--left .el-tabs__content {
  height: 100%;
}
.container {
  width: 100%;
  height: 100%;
  padding: 16px;
}
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
