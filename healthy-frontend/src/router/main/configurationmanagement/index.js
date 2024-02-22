const routes = [
  {
    path: '/configurationmanagement',
    name: 'configurationmanagement',
    redirect: '/configurationmanagement/TemplateManagement.vue',
    children: [
      {
        // 模板管理
        path: '/configurationmanagement/TemplateManagement.vue',
        name: 'configurationmanagementemplatemanagement',
        component: () => import('@/views/configurationmanagement/TemplateManagement.vue')
      },
      {
        // 术语管理
        path: '/configurationmanagement/TerminologyManagement.vue',
        name: 'configurationmanagementterminologymanagement',
        component: () => import('@/views/configurationmanagement/TerminologyManagement.vue')
      }
    ]
  }
]

export default routes
