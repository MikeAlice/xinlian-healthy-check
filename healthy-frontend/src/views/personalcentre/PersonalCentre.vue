<!-- 个人中心 -->
<template>
  <el-card>
    <el-tabs tab-position="left" class="demo-tabs">
      <el-tab-pane label="基本信息">
        <h1>基本信息</h1>
        <el-form :model="baseFormation" :label-position="labelPosition" label-width="100px">
          <el-form-item label="登录账号:">
            <span>admin</span>
          </el-form-item>
          <el-form-item label="用户头像:">
            <el-upload class="avatar-uploader" :show-file-list="false" auto-upload="false" :on-change="onSelectFile">
              <img v-if="imgUrl" :src="imgUrl" class="avatar" />
              <el-icon v-else class="avatar-uploader-icon"><Plus /></el-icon>
            </el-upload>
          </el-form-item>
          <el-form-item label="性别">
            <el-select v-model="baseFormation.gender" style="width: 220px">
              <el-option v-for="item in genderOptions" :key="item" :label="item.label" :value="item.value"></el-option>
            </el-select>
          </el-form-item>
          <el-form-item label="生日:">
            <el-date-picker v-model="baseFormation.birthday" type="date" />
          </el-form-item>
          <el-form-item label="所在省市:">
            <el-select style="width: 220px"></el-select>
          </el-form-item>
          <el-form-item label="个人简介:">
            <el-input v-model="baseFormation.resume" type="textarea" style="width: 220px"></el-input>
          </el-form-item>
          <el-form-item label="所属部门:"></el-form-item>
          <el-form-item label="用户类型:">
            <span>管理员</span>
          </el-form-item>
          <el-form-item label="签字文件">
            <el-upload class="avatar-uploader" :show-file-list="false" auto-upload="false" :on-change="onSelectFile2">
              <img v-if="imgUrl2" :src="imgUrl2" class="avatar" />
              <el-icon v-else class="avatar-uploader-icon"><Plus /></el-icon>
            </el-upload>
          </el-form-item>
          <el-button type="primary" size="large" class="saveButton" @click="saveOperation">保存</el-button>
        </el-form>
      </el-tab-pane>
      <el-tab-pane label="安全设置">
        <h1>安全设置</h1>
        <div class="content">
          <div class="item">
            <div class="text">
              <div class="topic">账户密码</div>
              <div class="bottom">当前密码强度: <span style="color: rgb(250, 173, 20)">中</span></div>
            </div>

            <el-button link class="button" @click="handleDrawer">修改</el-button>
          </div>
          <el-divider></el-divider>
          <div class="item">
            <div class="text">
              <div class="topic">绑定手机</div>
              <div class="bottom">已绑定手机: <span>18782059031</span></div>
            </div>
            <el-button link class="button" @click="editPhone">修改</el-button>
          </div>
          <el-divider></el-divider>
          <div class="item">
            <div class="text">
              <div class="topic">绑定邮箱</div>
              <div class="bottom">已绑定邮箱 <span>admin@exrick.cn</span></div>
            </div>
            <el-button link class="button" @click="editMailbox">修改</el-button>
          </div>
          <el-divider></el-divider>
          <div class="item">
            <div class="text">
              <div class="topic">密保问题</div>
              <div class="bottom">未设置密保问题,密保问题可有效保护账户安全</div>
            </div>
            <el-button link class="button">暂不支持设置</el-button>
          </div>
          <el-divider></el-divider>
        </div>
      </el-tab-pane>
      <el-tab-pane label="第三方账号绑定">
        <h1>第三方账号绑定</h1>
      </el-tab-pane>
      <el-tab-pane label="消息通知">
        <h1>消息通知</h1>
        <div class="message">
          <div class="system">
            <div class="header">系统消息</div>
            <div class="bottom">系统消息将以站内信的形式通知</div>
          </div>
          <el-switch v-model="systemMessages" active-text="开" inactive-text="关" inline-prompt></el-switch>
        </div>
        <el-divider />
      </el-tab-pane>
    </el-tabs>
  </el-card>
  <!-- 修改密码抽屉 -->
  <el-drawer v-if="drawerVisible" v-model="drawer" title="修改密码">
    <el-form v-model="remakePw" style="margin-top: 15px" :label-position="drawerLabel">
      <el-form-item label="*原密码" label-width="100">
        <el-input v-model="remakePw.oldPassword" show-password type="password" placeholder="请输入现在使用的密码"></el-input>
      </el-form-item>
      <el-form-item label="*新密码" label-width="100">
        <el-input v-model="remakePw.newPassword" show-password type="password" placeholder="请输入新密码,长度为6-20个字符"></el-input>
      </el-form-item>
      <el-form-item label="*确认新密码" label-width="100">
        <el-input v-model="remakePw.confirm" show-password type="password" placeholder="请再次输入新密码"></el-input>
      </el-form-item>
    </el-form>
    <template #footer>
      <div style="flex: auto">
        <el-button type="primary" @click="submitMm" >提交</el-button>
        <el-button @click="closeDrawer">取消</el-button>
      </div>
    </template>
  </el-drawer>
  <!-- 密码验证弹窗 -->
  <el-dialog v-model="confirmPassword">
    <template #header="{ titleId }">
      <h1 :id="titleId" style="color: rgb(23, 35, 61)">身份认证</h1>
      <el-divider></el-divider>
    </template>
    <div class="center" style="text-align: center">
      <el-icon style="color: rgb(81, 90, 110); font-size: 30px"><Lock></Lock></el-icon>
      <h2 style="font-weight: 700; color: rgb(47, 48, 51); margin-bottom: 45px">密码认证</h2>
      <span style="color: rgb(81, 90, 110); font-size: 16px">请输入您的密码</span>
      <br />
      <el-input v-model="confirmInp" type="password" size="large" show-password style="width: 250px; margin-top: 20px" placeholder="请输入您的密码"></el-input>
    </div>
    <template #footer>
      <div class="footer" style="text-align: center">
        <el-button size="large" @click="cancelConfirm">取消</el-button>
        <el-button type="primary" size="large" style="margin-left: 25px" @click="commitConfirm">提交</el-button>
      </div>
    </template>
  </el-dialog>
  <!--  -->
</template>

<script  setup>
import { ref, reactive } from 'vue'
import { usePersonalCenterStores } from '@/stores/personalcenter/index.js'

/* Stores中的方法 */
const personalCenterStore = usePersonalCenterStores()

// 基本信息表单---label位置
const labelPosition = ref('left')

// 修改密码---label位置
const drawerLabel = ref('top')

// 基本信息表单
const baseFormation = reactive({
  account: '',
  photo: '',
  userName: '',
  gender: '',
  birthday: '',
  locationCity: '',
  locationStreet: '',
  resume: '',
  department: '',
  userType: '',
  document: ''
})

// 基本信息表单---性别选项
const genderOptions = ref([
  {
    value: '男',
    label: '男'
  },
  {
    value: '女',
    label: '女'
  }
])

// 切换抽屉
const drawerVisible = ref(false)

// 抽屉显隐
const drawer = ref(true)

// 密码验证弹窗显隐
const confirmPassword = ref(false)

// 密码验证---绑定值
const confirmInp = ref()

// 修改密码表单
const remakePw = reactive({
  oldPassword: '',
  newPassword: '',
  confirm: ''
})

// 提交修改密码表单
const submitMm = () => {
  const result = personalCenterStore.changePasswordStore(remakePw);
  if(result.code == 200){
    return 
  }
}

// 点击修改打开抽屉
const handleDrawer = () => {
  drawerVisible.value = true
}

// 点击取消关闭抽屉
const closeDrawer = () => {
  drawerVisible.value = false
}

// 消息通知---系统消息开关
const systemMessages = ref(true)

// 用户头像
const imgUrl = ref()

// 用户头像---上传预览
const onSelectFile = (uploadFile) => {
  imgUrl.value = URL.createObjectURL(uploadFile.raw)
}

// 签字文件
const imgUrl2 = ref()

// 签字文件---上传预览
const onSelectFile2 = (uploadFile) => {
  imgUrl.value = URL.createObjectURL(uploadFile.raw)
}

// 基本信息---保存
const saveOperation = () => {
  console.log('保存')
}

// 安全设置---修改绑定手机
const editPhone = () => {
  confirmPassword.value = true
}

// 安全设置---修改绑定邮箱
const editMailbox = () => {
  confirmPassword.value = true
}

// 密码验证---取消按钮
const cancelConfirm = () => {
  confirmPassword.value = false
}

// 密码验证---提交按钮
const commitConfirm = () => {
  confirmPassword.value = false
}
</script>

<style lang="scss" scoped>
// 通用设置
h1 {
  margin-bottom: 15px;
}

// 安全设置
.item {
  display: flex;
  justify-content: space-between;
  .button {
    color: rgb(45, 140, 240);
  }
  .topic {
    color: rgba(0, 0, 0, 0.65);
    margin-bottom: 4px;
    font-size: 14px;
  }
  .bottom {
    color: rgba(0, 0, 0, 0.45);
    font-size: 14px;
  }
}

// 消息通知
.message {
  display: flex;
  justify-content: space-between;
  .header {
    font-size: 14px;
    color: rgba(0, 0, 0, 0.65);
  }
  .bottom {
    color: rgba(0, 0, 0, 0.45);
    font-size: 14px;
  }
}

// 上传头像---签字文件样式
.avatar-uploader {
  :deep() {
    .avatar {
      width: 130px;
      height: 130px;
      display: block;
    }
    .el-upload {
      border: 1px dashed var(--el-border-color);
      border-radius: 6px;
      cursor: pointer;
      position: relative;
      overflow: hidden;
      transition: var(--el-transition-duration-fast);
    }
    .el-upload:hover {
      border-color: var(--el-color-primary);
    }
    .el-icon.avatar-uploader-icon {
      font-size: 28px;
      color: #8c939d;
      width: 130px;
      height: 130px;
      text-align: center;
    }
  }
}

// 保存按钮样式
.saveButton {
  width: 100px;
  margin-left: 120px;
}
</style>
