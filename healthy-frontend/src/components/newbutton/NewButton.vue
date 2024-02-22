<template>
  <div>
    <el-button @click="showDrawer">新增</el-button>
    <el-form-item>
      <el-select v-model="formData.checkupType" placeholder="更多操作" style="width: 200px">
        <el-option label="刷新" value="type1" @click="refreshData"></el-option>
        <el-option label="批量删除" value="type2" @click="deleData"></el-option>
        <el-option label="导出本页数据" value="type3" @click="exportData"></el-option>
      </el-select>
    </el-form-item>

    <el-drawer :model-value="drawerVisible" title="新增" class="custom-drawer" style="width: 1000px">
      <el-form :model="formData" label-position="right">
        <div class="form-row">
          <el-form-item label="单位名称" style="width: 300px">
            <el-input v-model="formData.unitName"></el-input>
          </el-form-item>
          <el-form-item label="体检类型" style="width: 200px">
            <el-select v-model="formData.checkupType" placeholder="请选择">
              <el-option label="类型1" value="type1"></el-option>
              <el-option label="类型2" value="type2"></el-option>
              <!-- 其他选项... -->
            </el-select>
          </el-form-item>
        </div>
        <!-- 其他输入框和下拉框... -->
      </el-form>

      <div class="form-row">
        <el-form-item label="统一社会信用代码" style="width: 200px">
          <el-input v-model="formData.unitName"></el-input>
        </el-form-item>
        <el-form-item label="行业类型" style="width: 200px">
          <el-select v-model="formData.checkupType" placeholder="请选择">
            <el-option label="类型1" value="type1"></el-option>
            <el-option label="类型2" value="type2"></el-option>
            <!-- 其他选项... -->
          </el-select>
        </el-form-item>
      </div>
      <div class="form-row">
        <el-form-item label="所属地区" style="width: 200px">
          <el-select v-model="formData.checkupType" placeholder="请选择">
            <el-option label="类型1" value="type1"></el-option>
            <el-option label="类型2" value="type2"></el-option>
            <!-- 其他选项... -->
          </el-select>
        </el-form-item>
        <el-form-item label="经济类型" style="width: 200px">
          <el-select v-model="formData.checkupType" placeholder="请选择">
            <el-option label="类型1" value="type1"></el-option>
            <el-option label="类型2" value="type2"></el-option>
            <!-- 其他选项... -->
          </el-select>
        </el-form-item>
      </div>
      <div class="form-row">
        <el-form-item label="单位注册地址" style="width: 200px">
          <el-input v-model="formData.unitName"></el-input>
        </el-form-item>
        <el-form-item label="企业规模" style="width: 200px">
          <el-select v-model="formData.checkupType" placeholder="请选择">
            <el-option label="类型1" value="type1"></el-option>
            <el-option label="类型2" value="type2"></el-option>
            <!-- 其他选项... -->
          </el-select>
        </el-form-item>
      </div>
      <div class="form-row">
        <el-form-item label="体检联系人姓名" style="width: 200px">
          <el-input v-model="formData.unitName"></el-input>
        </el-form-item>
        <el-form-item label="体检联系人电话" style="width: 200px">
          <el-input v-model="formData.unitName"></el-input>
        </el-form-item>
      </div>
      <div class="drawer-footer">
        <el-button @click="closeDrawer">取消</el-button>
        <el-button type="primary" @click="saveData">保存</el-button>
      </div>
    </el-drawer>
  </div>
</template>

<script setup>
import { ref } from 'vue'

const drawerVisible = ref(false)

const formData = {
  unitName: '',
  checkupType: ''
  // 其他字段...
}

const showDrawer = () => {
  drawerVisible.value = true
}

const closeDrawer = () => {
  drawerVisible.value = false
}

const saveData = () => {
  // 处理保存逻辑，根据实际需求进行调整
  console.log('Saving data:', formData)
  closeDrawer()
}
// 刷新操作
const message = ref(false)
const refreshData = () => {
  if (!message.value) {
    message.value = true
    // 执行刷新操作后，隐藏消息
    setTimeout(() => (message.value = false), 1000)
  }
}
// 导出数据
const exportData = () => {
  // 模拟导出数据，实际应用中您可能需要从服务器获取数据并转换为blob对象
  const data = '模拟数据'
  const blob = new Blob([data], { type: 'text/plain;charset=utf-8' })
  const url = window.URL.createObjectURL(blob)
  window.location.href = url
}
// 删除数据
</script>

<style scoped>
.custom-drawer {
  width: 2000px; /* 调整为你需要的宽度 */
}

.form-row {
  display: flex;
  justify-content: space-between;
}
</style>
