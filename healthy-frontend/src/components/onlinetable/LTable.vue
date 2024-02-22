<template>
    <div class="l-table">
        <!-- 表格 -->
        <el-table :data="props.tableModule.dataList" border height="100%" style="width: 100%; overflow-y: scroll"
            v-loading="props.tableModule.loading" @selection-change="props.tableModule.selectChange"
            :row-class-name="tableRowClassName" :cell-class-name="tableCellClassName" @cell-dblclick="cellDblClick">
            <el-table-column type="selection" width="50" align="center" />
            <template v-if="tableChildren == '1'">
                <el-table-column v-for="(item, index) in props.tableModule.columns" :key="item.prop" :prop="item.prop"
                    :label="item.label" :align="item.align || 'left'" :width="item.width" :min-width="item.min_width"
                    :fixed="item.fixed">
                    <template slot-scope="scope" #default="scope">
                        <div v-if="item.type == 'switch'">
                            <el-switch v-model="scope.row[item.prop]" :active-value="item.activeValue"
                                :inactive-value="item.inactiveValue" @change="props.tableModule.switchChange(scope.row)">
                            </el-switch>
                        </div>
                        <div v-else-if="item.type == 'status'">
                            <el-tag :type="item.color ? item.color[scope.row[item.prop]] : ''">{{
                                props.tableModule.fieldChange(scope.row[item.prop], item.option) }}</el-tag>
                        </div>
                        <div v-else-if="item.type == 'image'">
                            <el-image style="width: 60px; height: 60px" :src="scope.row[item.prop]"
                                :preview-src-list="[scope.row[item.prop]]">
                            </el-image>
                        </div>
                        <div v-else-if="item.type == 'time'">{{ formatDate(scope.row[item.prop]) }}</div>
                        <div v-else-if="item.isEdit">
                            <el-input v-model="scope.row[item.prop]" :placeholder="'请输入' + item.label"
                                @blur="inputBlur(scope.row)" autofocus ref="inputRef"
                                v-if="scope.row['index'] == rowIndex && scope.column['index'] == columnIndex" />
                            <div v-else>{{ scope.row[item.prop] }}</div>
                        </div>
                        <div v-else>{{ scope.row[item.prop] }}</div>
                    </template>
                </el-table-column>
            </template>
            <template v-else-if="tableChildren == '2'">
                <el-table-column v-for="(one, index) in props.tableModule.columns" :key="index" :label="one.label">
                    <el-table-column v-for="item in props.tableModule.columns[index].children" :key="item.prop"
                        :prop="item.prop" :label="item.label" :align="item.align || 'left'" :width="item.width"
                        :min-width="item.min_width" :fixed="item.fixed">
                        <template slot-scope="scope" #default="scope">
                            <div v-if="item.type == 'switch'">
                                <el-switch v-model="scope.row[item.prop]" :active-value="item.activeValue"
                                    :inactive-value="item.inactiveValue"
                                    @change="props.tableModule.switchChange(scope.row)">
                                </el-switch>
                            </div>
                            <div v-else-if="item.type == 'status'">
                                <el-tag :type="item.color ? item.color[scope.row[item.prop]] : ''">{{
                                    props.tableModule.fieldChange(scope.row[item.prop], item.option) }}</el-tag>
                            </div>
                            <div v-else-if="item.type == 'image'">
                                <el-image style="width: 60px; height: 60px" :src="scope.row[item.prop]"
                                    :preview-src-list="[scope.row[item.prop]]">
                                </el-image>
                            </div>
                            <div v-else-if="item.type == 'time'">{{ formatDate(scope.row[item.prop]) }}</div>
                            <div v-else-if="item.isEdit">
                                <el-input v-model="scope.row[item.prop]" :placeholder="'请输入' + item.label"
                                    @blur="inputBlur(scope.row)" autofocus ref="inputRef"
                                    v-if="scope.row['index'] == rowIndex && scope.column['index'] == columnIndex" />
                                <div v-else>{{ scope.row[item.prop] }}</div>
                            </div>
                            <div v-else>{{ scope.row[item.prop] }}</div>
                        </template>
                    </el-table-column>
                </el-table-column>
            </template>
            <slot name="event"></slot>
        </el-table>
        <div class="l-pages">
            <!-- 分页 -->
            <el-pagination :current-page="props.tableModule.pages.page" :page-size.sync="props.tableModule.pages.limit"
                :page-sizes="pageSizes" :layout="layout" :total="props.tableModule.pages.total"
                @size-change="props.tableModule.sizeChange" @current-change="props.tableModule.currentChange" />
        </div>
    </div>
</template>

<script setup>
import { defineProps, onMounted, reactive, toRefs } from 'vue'
import { formatDate } from '@/utils/index'
const props = defineProps({
    tableModule: Object,
    layout: {
        type: String,
        default: "total, sizes, prev, pager, next, jumper",
    },
    pageSizes: {
        type: Array,
        default() {
            return [10, 20, 30, 50];
        },
    },
    tableChildren: {
        type: String,
        default: '1'
    }
})

const state = reactive({
    rowIndex: 0,
    columnIndex: 0
})

const { rowIndex, columnIndex } = toRefs(state)

onMounted(() => { })

// 编辑单元格
// 为每一行返回固定的className
function tableRowClassName({ row, rowIndex }) {
    row.index = rowIndex;
}

// 为所有单元格设置一个固定的 className
function tableCellClassName({ column, columnIndex }) {
    column.index = columnIndex;
}

// el-table单元格双击事件
function cellDblClick(row, column, cell, event) {
    state.rowIndex = row.index
    state.columnIndex = column.index
}

// input失去焦点
function inputBlur(row) {
    state.rowIndex = 0
    state.columnIndex = 0
    props.tableModule.editInputBlur()
}
</script>

<style scoped lang="scss">
.l-table {
    height: calc(100% - 32px);
    padding-bottom: 10px;

    .el-table {
        height: calc(100% - 42px) !important;
    }

    .l-pages {
        margin-top: 10px;
    }
}
</style>
