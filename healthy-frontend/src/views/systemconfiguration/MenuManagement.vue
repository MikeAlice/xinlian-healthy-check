<!-- 菜单管理 -->
<template>
  <div class="top">
    <el-form inline>
      <el-form-item>
        <el-button type="primary">添加子节点</el-button>
      </el-form-item>
      <el-form-item>
        <el-button>添加顶部菜单</el-button>
      </el-form-item>
      <el-form-item>
        <el-button>批量删除</el-button>
      </el-form-item>
      <el-form-item>
        <el-button>添加顶部菜单</el-button>
      </el-form-item>
      <el-form-item>
        <el-dropdown>
          <el-button style="margin-right: 8px">
            更多操作
            <el-icon class="el-icon--right"> <arrow-down /> </el-icon></el-button>
          <template #dropdown>
            <el-dropdown-menu>
              <el-dropdown-item>刷新</el-dropdown-item>
              <el-dropdown-item>收合所有</el-dropdown-item>
              <el-dropdown-item>仅展开一级</el-dropdown-item>
              <el-dropdown-item>仅展开两级</el-dropdown-item>
              <el-dropdown-item>刷新</el-dropdown-item>
            </el-dropdown-menu>
          </template>
        </el-dropdown>
      </el-form-item>
      <el-form-item>
        <el-switch v-model="isSingle" inline-prompt active-text="级联" inactive-text="单选"></el-switch>
      </el-form-item>
    </el-form>
  </div>

  <div class="main">
    <el-container>
      <el-aside width="400px">
        <!-- 提示框 -->
        <div class="hint">
          <span>
            <el-icon style="color: blue">
              <InfoFilled></InfoFilled>
            </el-icon>
            当前选择编辑： {{ selectWhich }}
          </span>
        </div>
        <el-input v-model="menuName" style="width: 380px; margin: 10px" placeholder="请输入菜单名搜索" :suffix-icon="Search" />
      </el-aside>
      <el-main>
        <!-- 节点表单 -->
        <el-form style="width: 500px">
          <el-form-item label="类型">
            <el-input disabled placeholder="请输入"></el-input>
          </el-form-item>
          <el-form-item label="上级菜单">
            <el-input placeholder="请输入"></el-input>
          </el-form-item>
          <el-form-item label="名称">
            <el-input placeholder="请输入"></el-input>
          </el-form-item>
          <el-form-item label="路径">
            <el-input placeholder="请输入"></el-input>
          </el-form-item>
          <el-form-item label="路由英文名">
            <el-input placeholder="请输入"></el-input>
          </el-form-item>
          <el-form-item label="图标">
            <el-button>选择图标</el-button>
          </el-form-item>
          <el-form-item label="前端组件">
            <el-input placeholder="请输入"></el-input>
          </el-form-item>
          <el-form-item label="排序值">
            <el-input placeholder="请输入"></el-input>
          </el-form-item>
          <el-form-item label="是否启用">
            <el-switch inline-prompt active-text="启用" inactive-text="禁用"></el-switch>
          </el-form-item>
          <el-form-item>
            <el-button type="primary">保存</el-button>
            <el-button>重置</el-button>
          </el-form-item>
        </el-form>
      </el-main>
    </el-container>
  </div>
</template>

<script setup>
import { reactive, ref } from 'vue'
import { ArrowUp, ArrowDown, Search, Plus, InfoFilled, Refresh, DeleteFilled, Bottom, View, Edit } from '@element-plus/icons-vue'

const isSingle = ref(true)
const selectWhich = ref('')
const menuName = ref('')

</script>

<style lang="scss" scoped>
.top {
  margin: 10px;
}



.hint {
  position: relative;
  height: 48px;
  padding: 10px;
  border: 1px solid RGB(171, 220, 255);
  border-radius: 5px;
  margin: 10px 5px;
  background-color: RGB(240, 250, 255);
}
</style>
