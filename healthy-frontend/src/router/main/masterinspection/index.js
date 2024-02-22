const routes = [
  {
    path: '/masterinspection',
    name: 'masterinspection',
    redirect: '/masterinspection/DoctorInspection.vue',
    children: [
      {
        // 网报数据
        path: '/masterinspection/DoctorInspection.vue',
        name: 'masterinspection',
        component: () => import('@/views/masterinspection/DoctorInspection.vue')
      }
    ]
  }
]

export default routes
