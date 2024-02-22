const routes = [
  {
    path: '/personalcentre',
    name: 'personalcentre',
    redirect: '/personalcentre/PersonalCentre.vue',
    children: [
      {
        // 网报数据
        path: '/personalcentre/PersonalCentre.vue',
        name: 'PersonalCentre',
        component: () => import('@/views/personalcentre/PersonalCentre.vue')
      }
    ]
  }
]

export default routes
