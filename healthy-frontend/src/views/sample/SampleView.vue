<template>
  <div>
    <el-header>
      <div class="header-nav">示例效果演示页</div>
    </el-header>
    <el-container>
      <el-aside>
        <div class="menu-wrap">
          <el-scrollbar max-height="95vh">
            <el-menu default-active="/sample/file" active-text-color="#409EFF" text-color="#fff" background-color="#545c64" unique-opened router>
              <el-menu-item v-for="(menu, index) in menus" :key="index" :index="menu.path">
                <el-icon>
                  <icon-menu />
                </el-icon>
                <span>{{ menu.text }}</span>
              </el-menu-item>
            </el-menu>
          </el-scrollbar>
        </div>
      </el-aside>
      <el-main>
        <router-view />
      </el-main>
    </el-container>
  </div>
</template>

<script setup>
import { reactive } from 'vue'
// 演示菜单数据，添加新的演示在这里不从数据即可 path代表路由地址 text代表提示文本
const menus = reactive([
  {
    path: '/sample/file',
    text: '文件上传'
  },
  {
    path: '/sample/excel',
    text: 'Excel演示'
  },
  {
    path: '/sample/print',
    text: '打印演示'
  },
  {
    path: '/sample/editor',
    text: '富文本框演示'
  },
  {
    path: '/sample/pdfobject',
    text: 'PDF预览演示'
  },
  {
    path: '/sample/basedatalist',
    text: '基础表格数据-张张奶酪包'
  },
  {
    path: '/sample/basedatalisttest',
    text: '基础表格数据测试-Yetta'
  },
  {
    path: '/sample/checkitems',
    text: '抽屉组件-回信'
  },
  {
    path: '/sample/search',
    text: '搜索框-intersellar'
  },
  {
    path: '/sample/medicalinfo',
    text: '体检人员信息-Rom'
  },
  {
    path: '/sample/details/Details.vue',
    text: '体检结果详情|统计页面-成果'
  },
  {
    path: '/sample/details/NewButtonCG.vue',
    text: '新增按钮|更多操作-成果'
  },
  {
    path: '/sample/newbutton',
    text: '新增按钮-云里的龙'
  },
  {
    path: '/sample/navigation',
    text: '流程导航-洛翼忆'
  },
  {
    path: '/sample/peoplelist',
    text: '人员列表-枇杷子'
  }
])
</script>

<style lang="scss" scoped>
.el-header {
  background-color: #5d6672;
  height: 5vh;
  display: flex;
  justify-content: space-between;
  padding: 0;
  .header-nav {
    line-height: 5vh;
    width: 100%;
    color: #f8f8f8;
    text-align: center;
  }
}
.el-aside {
  background-color: #545c64;
  height: 95vh;
  width: 221px;
  .menu-wrap {
    width: 220px;
  }
}
.el-menu {
  border: 0;
}
.el-main {
  padding: 20px;
  background-color: #edecec;
}
</style>
