<!-- 登录页面 -->
<template>
  <div class="container">
    <div class="top-bar">
      <div class="logo">logo</div>
      <ul>
        <a href="#">关于</a>
        <a href="#">联系我们</a>
      </ul>
    </div>

    <div class="color">
      <div class="c1"></div>
      <div class="c2"></div>
      <div class="c3"></div>
    </div>

    <el-row class="main">
      <el-col :span="12">
        <div class="text-content">
          <h1>零壹<br /><span>健康体检</span><br /><span>管理系统</span></h1>
          <p>zero one healthy check manegement system</p>
          <a href="#">01星球</a>
        </div>
      </el-col>
      <el-col :span="8" :offset="1">
        <div class="box-card">
          <div class="square" style="--i: 0"></div>
          <div class="square" style="--i: 1"></div>
          <div class="square" style="--i: 2"></div>
          <div class="square" style="--i: 3"></div>
          <div class="square" style="--i: 4"></div>

          <div class="wrapper">
            <el-form :model="formData" status-icon label-width="60px" class="form">
              <h2>登录</h2>
              <el-form-item label="账号" prop="username">
                <el-input v-model="formData.username"></el-input>
              </el-form-item>
              <el-form-item label="密码" prop="password">
                <el-input v-model="formData.password" type="password"></el-input>
              </el-form-item>
              <el-form-item style="margin-top: 22px">
                <el-button type="primary" @click="submitForm()">登录</el-button>
              </el-form-item>
            </el-form>

            <div style="margin-left: 40px">
              <!-- TODO[TEST_CODE]: 测试代码后期发布需要删除 -->
              <router-link to="/sample">进入示例演示页面</router-link>
            </div>
          </div>
        </div>
      </el-col>
    </el-row>
  </div>

  <!-- 验证码组件 -->
  <Verify ref="verify" mode="pop" :captcha-type="captchaType" :img-size="{ width: '400px', height: '200px' }" @success="handleSuccess"></Verify>
</template>

<script setup>
import Verify from '@/components/verifition/Verify.vue'
import Request from '@/apis/request'
import { ref, reactive, toRefs } from 'vue'
import { login } from '@/apis/login'
import { ElMessage } from 'element-plus'
import { useRouter } from 'vue-router'

// 获取router对象
const $router = useRouter()

// 定义登录数据对象
const formData = reactive({
  username: '',
  password: ''
})

/**
 * 执行登录
 * @param code 验证码字符串
 */
function doLogin(code) {
  // 发送登录请求
  login(
    {
      ...formData,
      clientId: import.meta.env.VITE_CLIENT_ID,
      code: code
    },
    () => {
      // 跳转到首页
      $router.push('/dashboard')
      // 登录成功提示
      ElMessage.success('登录成功，前往首页')
    },
    () => {
      ElMessage.error('账号或密码错误')
    }
  )
}

// 定义登录提交函数
function submitForm() {
  //TODO[TEST_CODE]:测试直接进入主界面
  //$router.push('/home')
  //doLogin('res.captchaVerification')

  // 弹出验证码框
  useVerify('blockPuzzle')
}

// 验证码组件引用
const verify = ref(null)

// 验证码类型
const captchaType = ref('')

/**
 * 弹出验证码框
 * @param type 验证码类型 blockPuzzle滑块验证 clickWord点击文字验证
 */
function useVerify(type) {
  captchaType.value = type
  verify.value.show()
}

/**
 * 验证码验证通过执行登录二次验证逻辑
 * @param res 验证通过信息
 */
function handleSuccess(res) {
  //TODO[TEST_CODE]:测试调用二次验证
  // Request.requestForm(
  //   Request.POST,
  //   '/login',
  //   { captchaVerification: res.captchaVerification },
  //   { baseURL: import.meta.env.VITE_CAPTCHA_URL }
  // )
  //   .then((res) => {
  //     console.log(res)
  //     if (res.data.repCode === '0000') {
  //       // 跳转到首页
  //       $router.push('/home')
  //       // 登录成功提示
  //       ElMessage.success('登录成功，前往首页')
  //       return
  //     }
  //     ElMessage.error('账号或密码错误')
  //   })
  //   .catch((res) => {
  //     console.log(res)
  //     ElMessage.error('账号或密码错误')
  //   })
  // console.log(res)
  doLogin(res.captchaVerification)
}
</script>

<style lang="scss" scoped>
.container {
  position: relative;
  min-height: 100vh;
  width: 100%;
  overflow: hidden;
  background: linear-gradient(to bottom, #f1f4f9, #dff1ff);
}

.top-bar {
  position: absolute;
  background: rgba(255, 255, 255, 0.1);
  backdrop-filter: blur(15px);
  box-shadow: 0 25px 45px rgba(188, 186, 186, 0.1);
  border: 1px solid rgba(255, 255, 255, 0.5);

  top: 0;
  left: 0;
  width: 100%;
  padding: 8px 100px;
  display: flex;
  justify-content: space-between;
  align-items: center;
  z-index: 3;

  a {
    color: #606266;
    font-weight: 400;
    margin-left: 40px;
    text-decoration: none;
  }
}

.logo {
  position: relative;
  max-width: 80px;
  font-size: 2em;
  color: #fff;
  user-select: none;
}

.color {
  position: absolute;
  filter: blur(150px);

  .c1 {
    top: -240px;
    right: 100px;
    width: 300px;
    height: 300px;
    background: #ccf3cb;
  }
  .c2 {
    top: -150px;
    left: 100px;
    width: 400px;
    height: 300px;
    background: #f6cbe0;
  }
  .c3 {
    top: -220px;
    left: 1300px;
    width: 300px;
    height: 300px;
    background: #76b4e3;
  }
}

.main {
  display: flex;
  justify-content: center;
  align-items: center;
  background: url('@/assets/login/bg-img.png') no-repeat;
  min-height: 100vh;
  background-position: 460px 300px;
  background-size: 550px;
}

.text-content {
  max-width: 600px;
  top: -200px;
  justify-content: space-between;
  align-items: center;
  border-left: 2px solid rgba(121, 112, 112, 0.1);
  padding: 14px;

  h1 {
    color: #606266;
    font-size: 3em;
    line-height: 1.5em;
    font-weight: 900;

    span {
      font-size: 1.3em;
    }
  }

  p {
    color: #606266;
    text-transform: uppercase;
    font-weight: 600;
  }

  a {
    display: inline-block;
    margin-top: 10px;
    padding: 8px 20px;
    background-color: #fff;
    color: #111;
    border-radius: 40px;
    font-weight: 500;
    letter-spacing: 1px;
    text-decoration: none;
  }
}

.box-card {
  width: 440px;
  margin: 50px auto;
  padding: 20px;
  border-radius: 4%;
}

.box-card .square {
  position: absolute;
  backdrop-filter: blur(5px);
  box-shadow: 0 25px 45px rgba(0, 0, 0, 0.1);
  border: 1px solid rgba(255, 255, 255, 0.5);
  border-right: 1px solid rgba(0, 0, 0, 0.2);
  border-bottom: 1px solid rgba(0, 0, 0, 0.2);
  background: rgba(255, 255, 255, 0.1);
  border-radius: 10px;
  animation: animate 10s linear infinite;
  animation-delay: calc(-1s * var(--i));
}
@keyframes animate {
  0%,
  100% {
    transform: translateY(-45px);
  }
  50% {
    transform: translateY(45px);
  }
}

.square:nth-child(1) {
  top: -50px;
  right: -50px;
  width: 100px;
  height: 100px;
  z-index: 2;
}
.square:nth-child(2) {
  top: 150px;
  right: 390px;
  width: 120px;
  height: 120px;
  z-index: 2;
}
.square:nth-child(3) {
  bottom: 50px;
  right: -50px;
  width: 80px;
  height: 80px;
  z-index: 2;
}
.square:nth-child(4) {
  bottom: -80px;
  left: 100px;
  width: 50px;
  height: 50px;
  z-index: 2;
}
.square:nth-child(5) {
  top: -80px;
  left: 140px;
  width: 60px;
  height: 60px;
}

.wrapper {
  position: relative;
  width: 400px;
  min-height: 400px;
  background: rgba(255, 255, 255, 0.1);
  border-radius: 10px;
  justify-content: center;
  align-items: center;
  backdrop-filter: blur(6px);
  box-shadow: 0 25px 45px rgba(0, 0, 0, 0.1);
  border: 1px solid rgba(255, 255, 255, 0.5);
  border-right: 1px solid rgba(0, 0, 0, 0.2);
  border-bottom: 1px solid rgba(0, 0, 0, 0.2);
}

.form {
  position: relative;
  width: 100%;
  height: 100%;
  padding: 40px;
}

h2 {
  position: relative;
  color: #606266;
  margin: 40px 0 40px 14px;
  font-size: 24px;
  font-weight: 600;
  letter-spacing: 1px;
}

h2::after {
  content: '';
  position: absolute;
  left: 0;
  bottom: -10px;
  width: 80px;
  height: 2px;
  background: #9a9a9a;
}
</style>
