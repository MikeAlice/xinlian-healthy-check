const routes = [
  {
    path: '/careercheck',
    redirect: '/careercheck/NavigationShow.vue',
    children: [
      {
        // 流程展示
        path: '/careercheck/NavigationShow.vue',
        name: 'careernavigation',
        component: () => import('@/views/careercheck/NavigationShow.vue')
      },
      {
        // 团检单位
        path: '/careercheck/InspectionCompany.vue',
        name: 'careerinspectioncompany',
        component: () => import('@/views/careercheck/InspectionCompany.vue')
      },
      {
        // 团检订单
        path: '/careercheck/GroupOrder.vue',
        name: 'careergrouporder',
        component: () => import('@/views/healthcheck/GroupOrder.vue')
      },
      {
        // 体检人员
        path: '/careercheck/MedicalExaminer.vue',
        name: 'careermedicalexaminer',
        component: () => import('@/views/careercheck/MedicalExaminer.vue')
      },
      {
        // 合同审批
        path: '/careercheck/ContractApproval.vue',
        name: 'careercontractapproval01',
        component: () => import('@/views/careercheck/ContractApproval.vue')
      },
      {
        // 体检登记
        path: '/careercheck/MedicalRegistration.vue',
        name: 'careermedicalregistration01',
        component: () => import('@/views/careercheck/MedicalRegistration.vue')
      },
      {
        // 体检诊台
        path: '/careercheck/MedicalExamination.vue',
        name: 'careermedicalexamination',
        component: () => import('@/views/careercheck/MedicalExamination.vue')
      },
      {
        // 医生总检
        path: '/careercheck/DoctorInspection.vue',
        name: 'careerdoctorinspection',
        component: () => import('@/views/careercheck/DoctorInspection.vue')
      },
      {
        // 报告审核
        path: '/careercheck/ReportAudit.vue',
        name: 'careerreportaudit',
        component: () => import('@/views/careercheck/ReportAudit.vue')
      },
      {
        // 体检报告
        path: '/careercheck/MedicalReport.vue',
        name: 'careermedicalreport',
        component: () => import('@/views/careercheck/MedicalReport.vue')
      },
      {
        // 单位报告
        path: '/careercheck/CompanyReport.vue',
        name: 'careercompanyreport',
        component: () => import('@/views/careercheck/CompanyReport.vue')
      },
      {
        // 数据网报
        path: '/careercheck/NetworkRecords.vue',
        name: 'careerdatanetworkreport',
        component: () => import('@/views/careercheck/NetworkRecords.vue')
      },
      {
        // 查询统计
        path: '/careercheck/QueryStatistics.vue',
        name: 'careerquerystatistics',
        component: () => import('@/views/careercheck/QueryStatistics.vue')
      }
    ]
  }
]

export default routes
