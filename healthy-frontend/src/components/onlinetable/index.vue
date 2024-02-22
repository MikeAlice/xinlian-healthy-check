<template>
    <div class="role">
    	<!-- 只添加了el-popover这些代码 -->
    	<el-popover placement="bottom" title="表格配置" :width="200" trigger="click">
            <div v-for="(item, index) in columns" :key="index">
                <el-checkbox v-model="item.show" :label="item.label" :true-label="true" :false-label="false" />
            </div>
            <template #reference>
                <el-button :icon="Operation"></el-button>
            </template>
        </el-popover>
        
    	<!-- LTable是之前封装的，不懂的可以看上面的链接 -->
        <LTable :tableModule="tableModule"  :tableChildren="1">
            <template #event>
                <el-table-column align="center" fixed="right" label="操作" width="120">
                    <template slot-scope="scope" #default="scope">
                        <el-button @click="userDelete(scope)">删除</el-button>
                    </template>
                </el-table-column>
            </template>
        </LTable>
    </div>
</template>





<script setup lang="ts">
import { reactive, toRefs, ref, onMounted } from 'vue'
import { columnsData } from './table'
import { ElMessage, ElMessageBox } from 'element-plus'
import { Operation } from '@element-plus/icons-vue' // Icon图标

const state = reactive({
    columns: columnsData,
    selections: [],
    loading: false,
    dataList: [
        {
            username: '张三',
            phone: '16688889999',
            createDate: 1679489616000,
            avatar: 'https://img1.baidu.com/it/u=2427424503,947601508&fm=253&fmt=auto&app=138&f=JPEG?w=500&h=500',
            userStatus: 1,
        }
    ],
    pages: {
        total: 0,
        limit: 20,
        page: 1,
    }
})

const { loading, dataList, columns, pages } = toRefs(state)

onMounted(() => {
    getDataList()
})

function getDataList() {

}

function userDelete(row: any) {
    console.log(row)
}

// 表格分页相关
const tableModule = ref<Object>({
    currentChange: currentChange,
    selectChange: selectChange,
    fieldChange: fieldChange,
    sizeChange: sizeChange,
    editInputBlur: editInputBlur,
    columns: columns,
    dataList: dataList,
    loading: loading,
    pages: pages
})

function selectChange(selection: any) {
    state.selections = selection
}
function fieldChange(row: any, option: any) {
    if (option[row]) {
        return option[row]
    }
}
function sizeChange(item: any) {
    state.pages.limit = item
    getDataList()
}
function currentChange(item: any) {
    state.pages.page = item
    getDataList()
}

function editInputBlur() {
    console.log('可编辑单元格失去焦点')
}

</script>

<style scoped lang="scss"></style>
