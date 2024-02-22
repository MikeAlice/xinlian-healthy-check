const routes = [
  {
    path: '/inspectionstatistics',
    name: 'inspectionstatistics',
    redirect: '/inspectionstatistics/InspectionStatistics.vue',
    children: [
      {
        // 网报数据
        path: '/inspectionstatistics/InspectionStatistics.vue',
        name: 'inspectionstatistics',
        component: () => import('@/views/inspectionstatistics/InspectionStatistics.vue')
      }
    ]
  }
]

export default routes
