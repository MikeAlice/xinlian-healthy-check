const routes = [
  {
    path: '/resultsinput',
    name: 'resultsinput',
    redirect: '/resultsinput/MedicalExamination.vue',
    children: [
      {
        // 网报数据
        path: '/resultsinput/MedicalExamination.vue',
        name: 'resultsinput',
        component: () => import('@/views/resultsinput/MedicalExamination.vue')
      }
    ]
  }
]

export default routes
