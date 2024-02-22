<template>
  <!-- <div class="main">
    <div class="btn01">
      <el-button @click="enter01" style="position: fixed; width: 130px; height: 50px; font-size: larger; font-weight: 200">点击进入</el-button>
    </div>
    <div class="icon01">
      <img src="../../assets/dashboard/icon01.png" style="height: 195px; width: 350px" />
    </div>

    <div class="btn02">
      <el-button @click="enter02" style="position: fixed; width: 130px; height: 50px; font-size: larger; font-weight: 200">点击进入</el-button>
    </div>
    <div class="icon02">
      <img src="../../assets/dashboard/icon02.png" style="height: 195px; width: 350px" />
    </div>

    <div class="btn03">
      <el-button @click="enter03" style="position: fixed; width: 130px; height: 50px; font-size: larger; font-weight: 200">点击进入</el-button>
    </div>
    <div class="icon03">
      <img src="../../assets/dashboard/icon03.png" style="height: 400px; width: 434px" />
    </div>

    <div class="btn04">
      <el-button style="position: fixed; width: 130px; height: 50px; font-size: larger; font-weight: 200">点击进入</el-button>
    </div>
    <div class="icon04">
      <img src="../../assets/dashboard/icon04.png" style="height: 400px; width: 230px" />
    </div>

    <div class="btn05">
      <el-button style="position: fixed; width: 130px; height: 50px; font-size: larger; font-weight: 200">点击进入</el-button>
    </div>
    <div class="icon05">
      <img src="../../assets/dashboard/icon05.png" style="height: 195px; width: 350px" />
    </div>

    <div class="btn06">
      <el-button style="position: fixed; width: 130px; height: 50px; font-size: larger; font-weight: 200">点击进入</el-button>
    </div>
    <div class="icon06">
      <img src="../../assets/dashboard/icon06.png" style="height: 195px; width: 350px" />
    </div>

  </div> -->
  <div class="main" >
    <img src="../../assets/dashboard/allicon.png" style="width:1200px;left: 150px;top: 280px;" />
    <div class="btn01">
      <el-button @click="enter01" style=" width: 130px; height: 50px; font-size: larger; font-weight: 200;">点击进入</el-button>
    </div>
    <div class="btn02">
      <el-button @click="enter02" style="position: absolute; width: 130px; height: 50px; font-size: larger; font-weight: 200">点击进入</el-button>
    </div>
    <div class="btn03">
      <el-button @click="enter03" style=" width: 130px; height: 50px; font-size: larger; font-weight: 200">点击进入</el-button>
    </div>
    <div class="btn04">
      <el-button style="position: fixed; width: 130px; height: 50px; font-size: larger; font-weight: 200">点击进入</el-button>
    </div>
    <div class="btn05">
      <el-button style="position: fixed; width: 130px; height: 50px; font-size: larger; font-weight: 200">点击进入</el-button>
    </div>
    <div class="btn06">
      <el-button style="position: fixed; width: 130px; height: 50px; font-size: larger; font-weight: 200">点击进入</el-button>
    </div>
  </div>
</template>

<script setup>
import { RouterView, RouterLink, useRouter } from 'vue-router'

const router = useRouter()

function enter01() {
  router.push('/healthcheck')
}

function enter02() {
  router.push('/employmentcheck')
}

function enter03() {
  router.push('/careercheck')
}
</script>

<style lang="css" scoped>
.main {
  background-image: url(../../assets/navigation/background01.jpg);
  background-size: 100% 100%;
  background-repeat: no-repeat;
  background-position: center center;
  margin: 0;
  padding: 0;
  border: 0;
  height: 90vh;
  width: 100%;
  position: fixed;
}
.main01 {
  margin: 0;
  padding: 0;
  border: 0;
  height: 90vh;
  width: 100%;
}
.icon01 {
  position: fixed;
  left: 10px;
  top: 200px;
}
.btn01 {
  left: 548px;
  top: 430px;
  z-index: 9999;
  position: fixed;
}

.icon02 {
  position: absolute;
  left: 0px;
  top: 405px;
}
.btn02 {
  left: 550px;
  top: 605px;
  z-index: 9999;
  position: fixed;
}

.icon03 {
  position: absolute;
  left: 355px;
  top: 200px;
}
.btn03 {
  left: 460px;
  top: 450px;
  z-index: 9999;
  position: absolute;
}

.icon04 {
  position: absolute;
  left: 795px;
  top: 200px;
}
.btn04 {
  left: 875px;
  top: 335px;
  z-index: 9999;
  position: absolute;
}
.icon05 {
  position: absolute;
  left: 1030px;
  top: 200px;
}
.btn05 {
  left: 1215px;
  top: 355px;
  z-index: 9999;
  position: absolute;
}

.icon06 {
  position: absolute;
  left: 1030px;
  top: 405px;
}
.btn06 {
  left: 1213px;
  top: 535px;
  z-index: 9999;
  position: absolute;
}
</style>
