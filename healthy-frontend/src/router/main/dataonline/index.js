const routes = [
  {
    path: '/dataonline',
    name: 'dataonline',
    redirect: '/dataonline/DataOnline.vue',
    children: [
      {
        // 网报数据
        path: '/dataonline/DataOnline.vue',
        name: 'dataonlinedataonline',
        component: () => import('@/views/dataonline/DataOnline.vue')
      },
      {
        // 网报记录
        path: '/dataonline/OnlineRecord.vue',
        name: 'dataonline',
        component: () => import('@/views/dataonline/OnlineRecord.vue')
      }
    ]
  }
]

export default routes
