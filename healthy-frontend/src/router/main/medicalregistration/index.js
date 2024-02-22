const routes = [
  {
    path: '/medicalregistration',
    name: 'medicalregistration',
    redirect: '/medicalregistration/MedicalRegistration.vue',
    children: [
      {
        // 网报数据
        path: '/medicalregistration/MedicalRegistration.vue',
        name: 'medicalregistration',
        component: () => import('@/views/medicalregistration/MedicalRegistration.vue')
      }
    ]
  }
]

export default routes
