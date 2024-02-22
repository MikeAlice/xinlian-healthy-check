// 数据网报
let dataonline = [
  {
    id: 12,
    text: '数据网报',
    icon: 'IconUser',
    children: [
      {
        //用来展示整个诊断流程
        id: 1,
        text: '数据网报',
        href: '/dataonline/DataOnline.vue',
        icon: 'IconSetting',
        pid: 1
      },
      {
        //用来展示整个诊断流程
        id: 2,
        text: '网报记录',
        href: '/dataonline/OnlineRecord.vue',
        icon: 'IconSetting',
        pid: 1
      }
    ]
  }
]

export { dataonline }
