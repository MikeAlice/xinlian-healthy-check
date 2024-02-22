// 配置管理
let configurationmanagement = [
  {
    id: 10,
    text: '配置管理',
    icon: 'IconUser',
    children: [
      {
        //用来展示整个诊断流程
        id: 1,
        text: '模板管理',
        href: '/configurationmanagement/TemplateManagement.vue',
        icon: 'IconSetting',
        pid: 1
      },
      {
        //用来展示整个诊断流程
        id: 2,
        text: '术语管理',
        href: '/configurationmanagement/TerminologyManagement.vue',
        icon: 'IconSetting',
        pid: 1
      }
    ]
  }
]

export { configurationmanagement }
