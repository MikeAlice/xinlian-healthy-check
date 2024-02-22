const columnsData: any = [
    {
        prop: 'username', // 数据字段对应
        label: '姓名', 	// 列名称
        min_width: 120,	// 最小长度（这里建议每一个表格中最少有一个字段设置最小长度）设置这个就不用设置 widht 了，大家可以自己摸索
        fixed: true // 固定表头（注意：二级表头时不可用）
    },
    {
        prop: 'phone',
        label: '手机号',
        isEdit: true, // isEdit为 true 开启单元格编辑（可编辑的单元格由自己控制）
        align: 'center', // 控制列对其方式（默认左对齐）
        width: 150,
    },
    {
        prop: 'createDate',
        label: ' 创建时间',
        align: 'center',
        type: 'time', // 针对字段需要时间格式化
        width: 180,
    },
    {
        prop: 'avatar',
        label: '头像',
        align: 'center',
        type: 'image', // 设置字段以图片展示
        width: 80
    },
    {
        prop: 'userStatus',
        label: '用户状态',
        align: 'center',
        type: 'switch', // 编辑用户状态
        activeValue: 1, // switch为打开时的值
        inactiveValue: 2,// switch为关闭时的值
        width: 100
    },
    {
        prop: 'userStatus',
        label: '用户状态',
        align: 'center',
        width: 100,
        type: 'status', // 与 type 为 switch 不同（status主要是看的而不是对数据的操作）
        option: {
            '1': '启用',
            '2': '禁用',
        },
        color: {
            '1': 'success',
            '2': 'info',
        }
    },
]

export {
    columnsData
}
