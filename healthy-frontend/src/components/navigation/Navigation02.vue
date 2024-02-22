<template>

    <div class="main">
        <el-container class="mater" >
          <el-main >
           
<div class="mid">

            <div class="ic01" >
              <router-link to="/employmentcheck/CompanyInfo.vue" >
              <img src="../../assets/navigation/icon01.png" />
              </router-link>
              <el-text  size="large" style="font-size: medium; position:center;width: 64px;font-weight: bold;" >单位信息</el-text>
            </div>
            <div class="arrow01">
              <img src="../../assets/navigation/arrow03.png"/>
            </div> 

          <div class="ic11">
          <router-link to="/employmentcheck/MedicalRegistration.vue">
            <img src="../../assets/navigation/icon11.png" />
          </router-link>
          <el-text size="large" style="font-size: medium; position:center;width: 64px;font-weight: bold;">体检登记</el-text>
          </div>
          <div class="arrow11">
          <img src="../../assets/navigation/arrow03.png" />
          </div>

           
  
            <div class="ic06">
              <router-link to="/employmentcheck/MedicalExamination.vue">
              <img src="../../assets/navigation/icon06.png" />
              </router-link>
              <el-text  size="large" style="font-size: medium; position:center;width: 64px;font-weight: bold;">体检诊台</el-text>
            </div>
            
  
            <div class="ic07">
              <router-link to="/employmentcheck/DoctorInspection.vue">
              <img src="../../assets/navigation/icon07.png" />
              </router-link>
              <el-text  size="large" style="font-size: medium; position:center;width: 64px;font-weight: bold;">医生总检</el-text>
            </div>
            <div class="arrow07">
              <img src="../../assets/navigation/arrow03.png"/>
            </div> 
  
            <div class="ic08">
              <router-link to="/employmentcheck/MedicalReport.vue">
              <img src="../../assets/navigation/icon09.png" />
              </router-link>
              <el-text  size="large" style="font-size: medium; position:center;width: 64px;font-weight: bold;">体检报告</el-text>
            </div>
            <div class="arrow08">
              <img src="../../assets/navigation/arrow03.png"/>
            </div> 
  
            <div class="ic09">
              <router-link to="/employmentcheck/HealthCertificate.vue">
              <img src="../../assets/navigation/icon13.png" />
              </router-link>
              <el-text  size="large" style="font-size: medium; position:center;width: 64px;font-weight: bold;">健  康  证</el-text>
            </div>
            <div class="arrow09">
              <img src="../../assets/navigation/arrow03.png"/>
            </div> 
   
  </div>
  
            
            
          </el-main>
          
        </el-container>
    </div>
  
  </template>
  
  <script setup>
    let line01 = 550;
  </script>
  
  <style lang="scss" scoped>
  // 图标的编号先从左到右，然后从上到下，依次增加
  .ic01{
    position:center;
    width: 64px;
    height: 64px;
    left: 333px;
    top: 167px;
    border-radius: 20px;
    background-color: rgb(255, 255, 255,0.7);
  }
  .ic02{
    width: 64px;
    height: 64px;
    left: 200px;
    top: 35px;
    border-radius: 20px;
    background-color: rgb(255, 255, 255,0.7);
  }
  .ic03{
    width: 64px;
    height: 64px;
    left: 320px;
    top: -30px;
    border-radius: 20px;
    background-color: rgb(255, 255, 255,0.7);
  }
  .ic04{
    width: 64px;
    height: 64px;
    left: 440px;
    top: -90px;
    border-radius: 20px;
    background-color: rgb(255, 255, 255,0.7);
  }
  .ic05{
    width: 64px;
    height: 64px;
    left: 1100px;
    top: -170px;
    border-radius: 20px;
    background-color: rgb(255, 255, 255,0.7);
  }
  .ic06{
    width: 64px;
    height: 64px;
    left: 580px;
    top: 38px;
    border-radius: 20px;
    background-color: rgb(255, 255, 255,0.7);
  }
  .ic07{
    width: 64px;
    height: 64px;
    left: 700px;
    top: -17px;
    border-radius: 20px;
    background-color: rgb(255, 255, 255,0.7);
  }
  .ic08{
    width: 64px;
    height: 64px;
    left: 820px;
    top: -91px;
    border-radius: 20px;
    background-color: rgb(255, 255, 255,0.7);
  }
  .ic09{
    width: 64px;
    height: 64px;
    left: 1050px;
    top: -150px;
    border-radius: 20px;
    background-color: rgb(255, 255, 255,0.7);
  }
  .ic10{
    width: 64px;
    height: 64px;
    left: 1100px;
    top: -225px;
    border-radius: 20px;
    background-color: rgb(255, 255, 255,0.7);
  }
  .ic11{
    position:center;
    width: 64px;
    height: 64px;
    left: 462px;
    top: 102px;
    border-radius: 20px;
    background-color: rgb(255, 255, 255,0.7);
  }
  .ic12{
    width: 64px;
    height: 64px;
    left: 1100px;
    top: -100px;
    border-radius: 20px;
    background-color: rgb(255, 255, 255,0.7);
  }
    html,
    body,
    .el-container{
      background-image:url(../../assets/navigation/background03.jpg);
      // opacity: 0.8;
      background-size: 100% 100%;
      background-repeat: no-repeat;
      background-position: center center ;
      border: 0;
      padding: 0;
      margin: 0;
      height: 90vh;
      width: 100%;
    }
    /* 背景颜色 */
    .main{
      border: 0;
      padding: 0;
      margin: 0;
      height: 90vh;
      width: 100%;
    }
    /* 横线 */
  .line{
    float:right;
    width: 100%;
    height: 1px;
    margin-top: -0.5em;
    background:#d4c4c4;
    position: relative;
    text-align: center;
  }
  .arrow01{
    top: 145px;
    left :430px ;
    height:1px;
    width: 40px;
    margin: 0 ;
    border: 0 ;
    padding: 0;
  }
  .arrow02{
    top: 5px;
    left :295px ;
    height:1px;
    width: 40px;
    margin: 0 ;
    border: 0 ;
    padding: 0;
  }
  
  .arrow03{
    top: -60px;
    left :415px ;
    height:1px;
    width: 40px;
    margin: 0 ;
    border: 0 ;
    padding: 0;
  }
  .arrow04{
    top: -139px;
    left :1070px ;
    height:1px;
    width: 40px;
    margin: 0 ;
    border: 0 ;
    padding: 0;
  }
  //10
  .arrow05{
    top: 50px;
    left :1070px ;
    height:1px;
    width: 40px;
    margin: 0 ;
    border: 0 ;
    padding: 0;
  }
  //12
  .arrow06{
    top: 210px;
    left :1070px ;
    height:1px;
    width: 40px;
    margin: 0 ;
    border: 0 ;
    padding: 0;
  }
  //9
  .arrow07{
    top: -55px;
    left :788px ;
    height:1px;
    width: 40px;
    margin: 0 ;
    border: 0 ;
    padding: 0;
  }
  .arrow08{
    top: -120px;
    left :970px ;
    height:1px;
    width: 80px;
    margin: 0 ;
    border: 0 ;
    padding: 0;
  }
  
  .arrow09{
    top: -185px;
    left :670px ;
    height:1px;
    width: 40px;
    margin: 0 ;
    border: 0 ;
    padding: 0;
  }
  .arrow10{
    top: -185px;
    left :555px ;
    height:1px;
    width: 40px;
    margin: 0 ;
    border: 0 ;
    padding: 0;
  }
//   图九的前面的箭头
  .arrow11{
    top: 75px;
    left :550px ;
    height:1px;
    width: 40px;
    margin: 0 ;
    border: 0 ;
    padding: 0;
  }
  //右边直立的直线
  .line{
    // position:absolute;
    top: -510px;
    left :494px ;
    height:1px;
    width: 40px;
    margin: 0 ;
    border: 0 ;
    padding: 0;
  }
  //左边直立的直线
  .line01{
  
    top: -590px;
    left :550px ;
    height:1px;
    width: 40px;
    margin: 0 ;
    border: 0 ;
    padding: 0;
  }
  .row01{
    top: -600px;
    left :517px ;
    height:1px;
    width: 40px;
    margin: 0 ;
    border: 0 ;
    padding: 0;
  }
  .row02{
    top: -105px;
    left :517px ;
    height:1px;
    width: 40px;
    margin: 0 ;
    border: 0 ;
    padding: 0;
  }
  
  .mid{
    top: 35%;
    left :-5% ;
  }
  </style>