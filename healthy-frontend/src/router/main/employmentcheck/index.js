const routes = [
  {
    path: '/employmentcheck',
    redirect: '/employmentcheck/NavigationShow.vue',
    children: [
      {
        // 流程展示
        path: '/employmentcheck/NavigationShow.vue',
        name: 'employmentnavigation',
        component: () => import('@/views/employmentcheck/NavigationShow.vue')
      },
      {
        // 单位信息
        path: '/employmentcheck/CompanyInfo.vue',
        name: 'employmentcompanyinfo',
        component: () => import('@/views/employmentcheck/CompanyInfo.vue')
      },
      {
        // 体检登记
        path: '/employmentcheck/MedicalRegistration.vue',
        name: 'employmentmedicalregistration',
        component: () => import('@/views/employmentcheck/MedicalRegistration.vue')
      },
      {
        // 体检诊台
        path: '/employmentcheck/MedicalExamination.vue',
        name: 'employmentmedicalexamination',
        component: () => import('@/views/employmentcheck/MedicalExamination.vue')
      },
      {
        // 医生总检
        path: '/employmentcheck/DoctorInspection.vue',
        name: 'employmentdoctorinspection',
        component: () => import('@/views/employmentcheck/DoctorInspection.vue')
      },
      {
        // 体检报告
        path: '/employmentcheck/MedicalReport.vue',
        name: 'employmentmedicalreport',
        component: () => import('@/views/employmentcheck/MedicalReport.vue')
      },
      {
        // 健康证
        path: '/employmentcheck/HealthCertificate.vue',
        name: 'employmenthealthcertificate',
        component: () => import('@/views/employmentcheck/HealthCertificate.vue')
      }
    ]
  }
]

export default routes
