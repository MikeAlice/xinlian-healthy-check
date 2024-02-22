// 系统菜单数据
let systemconfiguration = [
  {
    id: 11,
    text: '系统管理',
    icon: 'IconUser',
    children: [
      {
        //用来展示整个诊断流程
        id: 1,
        text: '用户管理',
        href: '/systemconfiguration/UserManagement.vue',
        icon: 'IconSetting',
        pid: 1
      },
      {
        //用来展示整个诊断流程
        id: 2,
        text: '部门管理',
        href: '/systemconfiguration/DepartmentManagement.vue',
        icon: 'IconSetting',
        pid: 1
      },
      {
        //用来展示整个诊断流程
        id: 3,
        text: '消息管理',
        href: '/systemconfiguration/MessageManagement.vue',
        icon: 'IconSetting',
        pid: 1
      },
      {
        //用来展示整个诊断流程
        id: 4,
        text: '角色管理',
        href: '/systemconfiguration/RoleManagement.vue',
        icon: 'IconSetting',
        pid: 1
      },
      {
        //用来展示整个诊断流程
        id: 5,
        text: '菜单管理',
        href: '/systemconfiguration/MenuManagement.vue',
        icon: 'IconSetting',
        pid: 1
      },
      {
        //用来展示整个诊断流程
        id: 6,
        text: '数据字典',
        href: '/systemconfiguration/DataDictionary.vue',
        icon: 'IconSetting',
        pid: 1
      },
      {
        //用来展示整个诊断流程
        id: 7,
        text: '系统配置',
        href: '/systemconfiguration/SystemConfiguration.vue',
        icon: 'IconSetting',
        pid: 1
      },
      {
        //用来展示整个诊断流程
        id: 8,
        text: '类型库',
        href: '/systemconfiguration/TypeLibrary.vue',
        icon: 'IconSetting',
        pid: 1
      }
    ]
  }
]

export { systemconfiguration }
