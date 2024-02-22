const routes = [
  {
    path: '/healthcheck',
    redirect: '/healthcheck/NavigationShow.vue',
    children: [
      {
        // 流程展示
        path: '/healthcheck/NavigationShow.vue',
        name: 'navigation',
        component: () => import('@/views/healthcheck/NavigationShow.vue')
      },
      {
        // 团检单位
        path: '/healthcheck/InspectionCompany.vue',
        name: 'inspectioncompany',
        component: () => import('@/views/healthcheck/InspectionCompany.vue')
      },
      {
        // 团建订单
        path: '/healthcheck/GroupOrder.vue',
        name: 'grouporder',
        component: () => import('@/views/healthcheck/GroupOrder.vue')
      },
      {
        // 体检人员
        path: '/healthcheck/MedicalExaminer.vue',
        name: 'medicalexaminer',
        component: () => import('@/views/healthcheck/MedicalExaminer.vue')
      },
      {
        // 合同审批
        path: '/healthcheck/ContractApproval.vue',
        name: 'contractapproval',
        component: () => import('@/views/healthcheck/ContractApproval.vue')
      },
      {
        // 体检登记
        path: '/healthcheck/MedicalRegistration.vue',
        name: 'MedicalRegistration',
        component: () => import('@/views/healthcheck/MedicalRegistration.vue')
      },
      {
        // 体检诊台
        path: '/healthcheck/MedicalExamination.vue',
        name: 'medicalexamination',
        component: () => import('@/views/healthcheck/MedicalExamination.vue')
      },
      {
        // 医生总检
        path: '/healthcheck/DoctorInspection.vue',
        name: 'doctorinspection',
        component: () => import('@/views/healthcheck/DoctorInspection.vue')
      },
      {
        // 报告审核
        path: '/healthcheck/ReportAudit.vue',
        name: 'reportaudit',
        component: () => import('@/views/healthcheck/ReportAudit.vue')
      },
      {
        // 体检报告
        path: '/healthcheck/MedicalReport.vue',
        name: 'MedicalReport',
        component: () => import('@/views/healthcheck/MedicalReport.vue')
      },
      {
        // 单位报告
        path: '/healthcheck/CompanyReport.vue',
        name: 'companyreport',
        component: () => import('@/views/healthcheck/CompanyReport.vue')
      },
      {
        // 查询统计
        path: '/healthcheck/QueryStatistics.vue',
        name: 'querystatistics',
        component: () => import('@/views/healthcheck/QueryStatistics.vue')
      }
    ]
  }
]

export default routes
