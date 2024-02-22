<template>
  <div class="main">
    <el-container class="mater">
      <el-main>
        <div class="ic01">
          <router-link to="/careercheck/InspectionCompany.vue" @click="findurl()">
            <img src="../../assets/navigation/icon01.png" />
          </router-link>
          <el-text size="large">团检单位</el-text>
        </div>
        <div class="arrow01">
          <img src="../../assets/navigation/arrow03.png" />
        </div>


        <div class="ic02">
          <router-link to="/careercheck/GroupOrder.vue" @click="findurl()">
            <img src="../../assets/navigation/icon02.png" />
          </router-link>
          <el-text size="large">团检订单</el-text>
        </div>
        <div class="arrow02">
          <img src="../../assets/navigation/arrow03.png" />
        </div>

        <div class="ic03">
          <router-link to="/careercheck/MedicalExaminer.vue">
            <img src="../../assets/navigation/icon03.png" />
          </router-link>
          <el-text size="large">团检人员</el-text>
        </div>
        <div class="arrow03">
          <img src="../../assets/navigation/arrow03.png" />
        </div>



        <div class="ic04">
          <router-link to="/careercheck/ContractApproval.vue">
            <img src="../../assets/navigation/icon04.png" />
          </router-link>
          <el-text size="large">合同审批</el-text>
        </div>
        <div class="arrow04">
          <img src="../../assets/navigation/arrow03.png" />
        </div>


        <div class="ic05">
          <router-link to="/careercheck/CompanyReport.vue">
            <img src="../../assets/navigation/icon05.png" />
          </router-link>
          <el-text size="large">单位报告</el-text>
        </div>
        <div class="arrow05">
          <img src="../../assets/navigation/arrow03.png" />
        </div>

        <div class="ic06">
          <router-link to="/careercheck/MedicalExamination.vue">
            <img src="../../assets/navigation/icon06.png" />
          </router-link>
          <el-text size="large">体检诊台</el-text>
        </div>
        <div class="arrow06">
          <img src="../../assets/navigation/arrow03.png" />
        </div>

        <div class="ic07">
          <router-link to="/careercheck/DoctorInspection.vue">
            <img src="../../assets/navigation/icon07.png" />
          </router-link>
          <el-text size="large">医生总检</el-text>
        </div>
        <div class="arrow07">
          <img src="../../assets/navigation/arrow03.png" />
        </div>

        <div class="ic08">
          <router-link to="/careercheck/ReportAudit.vue">
            <img src="../../assets/navigation/icon08.png" />
          </router-link>
          <el-text size="large">报告审核</el-text>
        </div>
        <div class="arrow08">
          <img src="../../assets/navigation/arrow03.png" />
        </div>

        <div class="ic09">
          <router-link to="/careercheck/MedicalReport.vue">
            <img src="../../assets/navigation/icon09.png" />
          </router-link>
          <el-text size="large">体检报告</el-text>
        </div>
        <div class="arrow09">
          <img src="../../assets/navigation/arrow03.png" />
        </div>

        <div class="ic10">
          <router-link to="/careercheck/QueryStatistics.vue">
            <img src="../../assets/navigation/icon10.png" />
          </router-link>
          <el-text size="large">查询统计</el-text>
        </div>
        <div class="arrow10">
          <img src="../../assets/navigation/arrow03.png" />
        </div>


        <div class="ic11">
          <router-link to="/careercheck/MedicalRegistration.vue">
            <img src="../../assets/navigation/icon11.png" />
          </router-link>
          <el-text size="large">体检登记</el-text>
        </div>
        <div class="arrow11">
          <img src="../../assets/navigation/arrow03.png" />
        </div>
        <div class="ic12">
          <router-link to="/careercheck/NetworkRecords.vue">
            <img src="../../assets/navigation/icon12.png" />
            </router-link>
            <el-text  size="large">数据网报</el-text>
          </div>      
          
          
          <div class="line01">
            <img src="../../assets/navigation/row01.png"/>
            <div class="line">
            <img src="../../assets/navigation/row03.png"/>
          </div> 
          </div> 
          <div class="row01">
            <img src="../../assets/navigation/row02.png"/>
          </div> 
          <div class="row02">
            <img src="../../assets/navigation/row02.png"/>
          </div> 
        </el-main>
        
      </el-container>
  </div>

        <!-- <div class="line">
          <img src="../../assets/navigation/row03.png" />
        </div>
        <div class="line01">
          <img src="../../assets/navigation/row01.png" />
        </div>
        <div class="row01">
          <img src="../../assets/navigation/row02.png" />
        </div>
        <div class="row02">
          <img src="../../assets/navigation/row02.png" />
        </div>
      </el-main>

    </el-container>
  </div> -->
</template>

<script setup>
  let line01 = 550;
  function findurl(){
    var url = window.location.href; //获取地址栏路径
    console.log(url);
    var temp1 = url.split('3000');//对url地址进行分割
    console.log(temp1);
    console.log(temp1[1]);
  }
</script>

<style lang="scss" scoped>
// 图标的编号先从左到右，然后从上到下，依次增加
.ic01 {
  position: center;
  width: 64px;
  height: 64px;
  left: 80px;
  top: 100px;
  border-radius: 20px;
  background-color: rgb(255, 255, 255, 0.7);
}

.ic02 {
  width: 64px;
  height: 64px;
  left: 200px;
  top: 35px;
  border-radius: 20px;
  background-color: rgb(255, 255, 255, 0.7);
}

.ic03 {
  width: 64px;
  height: 64px;
  left: 320px;
  top: -30px;
  border-radius: 20px;
  background-color: rgb(255, 255, 255, 0.7);
}

.ic04 {
  width: 64px;
  height: 64px;
  left: 440px;
  top: -90px;
  border-radius: 20px;
  background-color: rgb(255, 255, 255, 0.7);
}

.ic05 {
  width: 64px;
  height: 64px;
  left: 1100px;
  top: -150px;
  border-radius: 20px;
  background-color: rgb(255, 255, 255, 0.7);
}

.ic06 {
  width: 64px;
  height: 64px;
  left: 580px;
  top: 30px;
  border-radius: 20px;
  background-color: rgb(255, 255, 255, 0.7);
}

.ic07 {
  width: 64px;
  height: 64px;
  left: 700px;
  top: -30px;
  border-radius: 20px;
  background-color: rgb(255, 255, 255, 0.7);
}

.ic08 {
  width: 64px;
  height: 64px;
  left: 820px;
  top: -100px;
  border-radius: 20px;
  background-color: rgb(255, 255, 255, 0.7);
}

.ic09 {
  width: 64px;
  height: 64px;
  left: 940px;
  top: -165px;
  border-radius: 20px;
  background-color: rgb(255, 255, 255, 0.7);
}

.ic10 {
  width: 64px;
  height: 64px;
  left: 1100px;
  top: -225px;
  border-radius: 20px;
  background-color: rgb(255, 255, 255, 0.7);
}

.ic11 {
  width: 64px;
  height: 64px;
  left: 440px;
  top: -30px;
  border-radius: 20px;
  background-color: rgb(255, 255, 255, 0.7);
}

.ic12 {
  width: 64px;
  height: 64px;
  left: 1100px;
  top: -100px;
  border-radius: 20px;
  background-color: rgb(255, 255, 255, 0.7);
}

html,
body,
.el-container {
  background-image: url(../../assets/navigation/background03.jpg);
  // opacity: 0.8;
  background-size: 100% 100%;
  background-repeat: no-repeat;
  background-position: center center;
  border: 0;
  padding: 0;
  margin: 0;
  height: 90vh;
  width: 100%;
}

/* 背景颜色 */
.main {
  border: 0;
  padding: 0;
  margin: 0;
  height: 90vh;
  width: 100%;
}

/* 横线 */
.line {
  float: right;
  width: 100%;
  height: 1px;
  margin-top: -0.5em;
  background: #d4c4c4;
  position: relative;
  text-align: center;
}

.arrow01 {
  top: 70px;
  left: 172px;
  height: 1px;
  width: 40px;
  margin: 0;
  border: 0;
  padding: 0;
}

.arrow02 {
  top: 5px;
  left: 295px;
  height: 1px;
  width: 40px;
  margin: 0;
  border: 0;
  padding: 0;
}

.arrow03 {
  top: -60px;
  left: 415px;
  height: 1px;
  width: 40px;
  margin: 0;
  border: 0;
  padding: 0;
}

.arrow04 {
  top: -110px;
  left: 1070px;
  height: 1px;
  width: 40px;
  margin: 0;
  border: 0;
  padding: 0;
}

//10
.arrow05 {
  top: 70px;
  left: 1070px;
  height: 1px;
  width: 40px;
  margin: 0;
  border: 0;
  padding: 0;
}

//12
.arrow06 {
  top: 270px;
  left: 1070px;
  height: 1px;
  width: 40px;
  margin: 0;
  border: 0;
  padding: 0;
}

//9
.arrow07 {
  top: -55px;
  left: 915px;
  height: 1px;
  width: 40px;
  margin: 0;
  border: 0;
  padding: 0;
}

.arrow08 {
  top: -120px;
  left: 790px;
  height: 1px;
  width: 40px;
  margin: 0;
  border: 0;
  padding: 0;
}

.arrow09 {
  top: -185px;
  left: 670px;
  height: 1px;
  width: 40px;
  margin: 0 ;
  border: 0 ;
  padding: 0;
}
.arrow10{
  top: -250px;
  left :560px ;
  height:1px;
  width: 40px;
  margin: 0 ;
  border: 0 ;
  padding: 0;
}
.arrow11{
  top: -320px;
  left :1030px ;
  height:1px;
  width: 40px;
  margin: 0 ;
  border: 0 ;
  padding: 0;
}
//右边直立的直线
.line{
  // position:absolute;
  top: -522px;
  left :494px ;
  height:1px;
  width: 40px;
  margin: 0 ;
  border: 0 ;
  padding: 0;
}
//左边直立的直线
.line01{

  top: -615px;
  left :550px ;
  height:1px;
  width: 40px;
  margin: 0 ;
  border: 0 ;
  padding: 0;
}
.row01{
  top: -630px;
  left :517px ;
  height:1px;
  width: 40px;
  margin: 0 ;
  border: 0 ;
  padding: 0;
}
.row02{
  top: -127px;
  left :517px ;
  height:1px;
  width: 40px;
  margin: 0 ;
  border: 0 ;
  padding: 0;
}

.arrow10 {
  top: -250px;
  left: 560px;
  height: 1px;
  width: 40px;
  margin: 0;
  border: 0;
  padding: 0;
}

.arrow11 {
  top: -320px;
  left: 1030px;
  height: 1px;
  width: 40px;
  margin: 0;
  border: 0;
  padding: 0;
}

//右边直立的直线
.line {
  top: -520px;
  left: 496px;
  height: 1px;
  width: 40px;
  margin: 0;
  border: 0;
  padding: 0;
}

//左边直立的直线
.line01 {
  top: -615px;
  left: 550px;
  height: 1px;
  width: 40px;
  margin: 0;
  border: 0;
  padding: 0;
}

.row01 {
  top: -630px;
  left: 517px;
  height: 1px;
  width: 40px;
  margin: 0;
  border: 0;
  padding: 0;
}

.row02 {
  top: -127px;
  left: 517px;
  height: 1px;
  width: 40px;
  margin: 0;
  border: 0;
  padding: 0;
}</style>