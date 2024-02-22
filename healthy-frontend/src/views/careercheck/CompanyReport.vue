<!-- 单位报告 -->
<template>
  <div>
    <el-container style="height: 600px;">
      <el-aside>
        <PeoplleList :isShowCheckbox="false" :isShowSwitch="false" title="报告查询">
          <template #table-area>
            <SelectList use-which="checkbox" :lists-data="listsData"></SelectList>
          </template>
        </PeoplleList>
      </el-aside>
      <el-main>
        <div class="form">

          <Head name="报告信息">
            <el-button v-if="showChangeBtn" type="primary" @click="change">修改</el-button>
            <el-button v-if="showSaveBtn" type="primary" @click="save">保存</el-button>
          </Head>
          <div>
            <el-form ref="formRef" label-position="right" label-width="85px" :disabled="isDisabled" :model="formData"
              :rules="rules" class="myForm">
              <el-row justify="space-between">
                <el-col span="12">
                  <el-form-item label="报告编号">
                    <el-input v-model="formData.code" placeholder="请输入" clearable class="input" />
                  </el-form-item>
                </el-col>
                <el-col span="12">
                  <el-form-item label="体检类型">
                    <el-select v-model="formData.type" placeholder="请选择">
                      <el-option label="健康体检" value="type1"></el-option>
                      <el-option label="职业体检" value="type2"></el-option>
                      <el-option label="" value="type3"></el-option>
                    </el-select>
                  </el-form-item>
                </el-col>
              </el-row>
              <el-row justify="space-between">
                <el-col span="12">
                  <el-form-item label="体检单位">
                    <el-input v-model="formData.checkUnit" placeholder="请输入" clearable />
                  </el-form-item>
                </el-col>
                <el-col span="12">
                  <el-form-item label="委托单位">
                    <el-input v-model="formData.commissionedUnit" placeholder="请输入" clearable />
                  </el-form-item>
                </el-col>
              </el-row>
              <el-row justify="space-between">
                <el-col span="12">
                  <el-form-item label="报告日期" prop="date">
                    <el-date-picker v-model="formData.date" placeholder="请选择日期" />
                  </el-form-item>
                </el-col>
                <el-col span="12">
                  <el-form-item label="体检人数">
                    <el-input-number v-model="formData.num" :min="0" clearable />
                  </el-form-item>
                </el-col>
              </el-row>
              <el-row justify="space-between">
                <el-col span="12">
                  <el-form-item label="体检项目">
                    <el-input v-model="formData.project" :autosize="{ minRows: 4 }" placeholder="请输入" clearable
                      type="textarea" />
                  </el-form-item>
                </el-col>
                <el-col span="12">
                  <el-form-item label="评论依据" prop="reason">
                    <el-input v-model="formData.reason" :autosize="{ minRows: 4 }" placeholder="请输入" clearable
                      type="textarea" />
                  </el-form-item>
                </el-col>
              </el-row>
              <el-row justify="space-between">
                <el-form-item style="width: 100%" class="result" label="体检结论与处理意见" prop="result">
                  <el-input v-model="formData.result" :autosize="{ minRows: 6 }" placeholder="请输入" clearable
                    type="textarea" />
                <CheckItems bottonTitle="选"></CheckItems>
                </el-form-item>
              </el-row>
            </el-form>
          </div>
        </div>

        <div class="tables">

          <Head name="汇总表">
            <Excel excelName="test" url="https://sheetjs.com/pres.numbers"></Excel>
          </Head>
          <el-tabs v-model="activeName" @tab-click="handleClick" type="border-card">
            <el-tab-pane label="体检人员汇总表" name="first">
              <BaseDataList :useSelection="false" :useFixed="false" :tableData="dataOneRow"
                :tableColumnAttribute="dataOneColumn">
              </BaseDataList>
            </el-tab-pane>
            <el-tab-pane label="复查人员汇总表" name="second">
              <BaseDataList :useSelection="false" :useFixed="false"></BaseDataList>
            </el-tab-pane>
            <el-tab-pane label="复查结果汇总表" name="third">
              <BaseDataList :useSelection="false" :useFixed="false"></BaseDataList>
            </el-tab-pane>
          </el-tabs>
        </div>
      </el-main>
    </el-container>
  </div>
</template>

<script setup>
import PeoplleList from '@/components/peoplelist/PeopleList.vue'
import { reactive, ref } from 'vue'
import BaseDataList from '@/components/basedatalist/BaseDataList.vue'
import Head from '@/components/head/Head.vue'
import Excel from '@/components/excel/Excel.vue'
import SelectList from '@/components/selectList/SelectList.vue'
import CheckItems from '@/components/checkitems/CheckItems.vue'

// 修改&保存按钮
const isDisabled = ref(true)
const showChangeBtn = ref(true)
const showSaveBtn = ref(false)
function change() {
  isDisabled.value = false
  showChangeBtn.value = false
  showSaveBtn.value = true
}
const formRef = ref()
function save() {
  // 表单验证
  formRef.value.validate((valid) => {
    if (!valid) {
      return
    }
    // 验证通过，执行保存逻辑
    isDisabled.value = true
    showChangeBtn.value = true
    showSaveBtn.value = false
    console.log(formData)
  })
}

// 绑定表单的数据
const formData = reactive(
  {
    code: '',
    type: '',
    checkUnit: '',
    commissionedUnit: '',
    date: '',
    num: 0,
    project: '',
    reason: '',
    result: ''
  }
)

// 表单的规则
const rules = reactive({
  date: [
    {
      required: true,
      message: '请选择日期',
      trigger: 'submit'
    }
  ],
  reason: [
    {
      required: true,
      message: '请填写评论依据',
      trigger: 'submit'
    }
  ],
  result: [
    {
      required: true,
      message: '请填写体检结论与处理意见',
      trigger: 'submit'
    }
  ]
})

// tabs 默认选中第一个
const activeName = 'first'

// 测试数据 1
// 每列数据
const dataOneColumn = [
  {
    prop: 'name',
    label: '单位名称'
  },
  {
    prop: 'credit',
    label: '信用代码'
  },
  {
    prop: 'examination',
    label: '体检类型'
  },
  {
    prop: 'address',
    label: '所属地区'
  },
  {
    prop: 'category',
    label: '行业类别'
  },
  {
    prop: 'etype',
    label: '经济类型'
  },
  {
    prop: 'scale',
    label: '企业规模'
  },
  {
    prop: 'contact',
    label: '联系人'
  },
  {
    prop: 'phone',
    label: '联系电话'
  }
]
// 每行的数据
const dataOneRow = [
  {
    name: '乐山市峨边盛和矿业',
    credit: '--',
    examination: '健康体检',
    address: '--',
    category: '铁矿采选*',
    etype: '国有企业',
    scale: '--',
    contact: '--',
    phone: '--'
  },
  {
    name: '习水宏旭纸箱有限公司',
    credit: '--',
    examination: '健康体检',
    address: '--',
    category: '--',
    etype: '--',
    scale: '--',
    contact: '蔡徐坤',
    phone: '--'
  },
  {
    name: '四川峨边三丰冶金材料',
    credit: '--',
    examination: '健康体检',
    address: '--',
    category: '--',
    etype: '国有企业',
    scale: '--',
    contact: '--',
    phone: '--'
  }
]

// 列表数据
const listsData = [
  {
    code: '121111118442',
    date: '2093-4-4',
    company: 'test company3',
    icon: [3, 0, 0, 0, 2]
  },
  {
    code: '102039338444',
    date: '2023-4-4',
    company: 'test company3',
    icon: [3, 0, 0, 0, 2]
  },
  {
    code: '102039338445',
    date: '2023-4-4',
    company: 'test company3',
    icon: [3, 0, 0, 0, 2]
  },
  {
    code: '102039338446',
    date: '2023-4-4',
    company: 'test company3',
    icon: [3, 0, 0, 0, 2]
  },
  {
    code: '102039338441',
    date: '2023-4-4',
    company: 'test company',
    icon: [4, 1, 2, 1, 2] // 放、未报、通、未打、团
  }
]
</script>

<style lang="scss" scoped>
.head {
  font-weight: bold;
}

.myForm .el-form-item {
  width: 400px;
}

// .input {
//   --el-input-width: 400px;
// }
</style>
