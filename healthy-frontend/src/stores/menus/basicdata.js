// 系统菜单数据
let basicdata = [
  {
    id: 4,
    text: '基础数据',
    icon: 'IconUser',
    children: [
      {
        //用来展示整个诊断流程
        id: 1,
        text: '科室管理',
        href: '/basicdata/DepartmentManagement.vue',
        icon: 'IconSetting',
        pid: 1
      },
      {
        //用来展示整个诊断流程
        id: 2,
        text: '基础项目',
        href: '/basicdata/BasicProject.vue',
        icon: 'IconSetting',
        pid: 1
      },
      {
        //用来展示整个诊断流程
        id: 3,
        text: '组合项目',
        href: '/basicdata/PortfolioItems.vue',
        icon: 'IconSetting',
        pid: 1
      },
      {
        //用来展示整个诊断流程
        id: 4,
        text: '体检套餐',
        href: '/basicdata/CheckUpPackage.vue',
        icon: 'IconSetting',
        pid: 1
      },
      {
        //用来展示整个诊断流程
        id: 5,
        text: '样本库',
        href: '/basicdata/SampleLibrary.vue',
        icon: 'IconSetting',
        pid: 1
      }
    ]
  }
]

export { basicdata }
