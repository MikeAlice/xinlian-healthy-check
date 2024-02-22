// 系统菜单数据
let masterinspection = [
  {
    id: 8,
    text: '主检评价',
    icon: 'IconUser',
    children: [
      {
        //用来展示整个诊断流程
        id: 1,
        text: '医生总检',
        href: '/masterinspection/DoctorInspection.vue',
        icon: 'IconSetting',
        pid: 1
      }
    ]
  }
]

export { masterinspection }
