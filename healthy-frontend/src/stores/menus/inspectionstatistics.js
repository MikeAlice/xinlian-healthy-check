// 系统菜单数据
let inspectionstatistics = [
  {
    id: 9,
    text: '查询统计',
    icon: 'IconUser',
    children: [
      {
        //用来展示整个诊断流程
        id: 1,
        text: '查询统计',
        href: '/inspectionstatistics/InspectionStatistics.vue',
        icon: 'IconSetting',
        pid: 1
      }
    ]
  }
]

export { inspectionstatistics }
