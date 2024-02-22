const routes = [
  {
    path: '/marketingmanagement',
    name: 'marketingmanagement',
    redirect: '/marketingmanagement/InspectionCompany.vue',
    children: [
      {
        path: '/marketingmanagement/InspectionCompany.vue',
        name: 'marketingmanagementinspectioncompany',
        component: () => import('@/views/marketingmanagement/InspectionCompany.vue')
      },
      {
        path: '/marketingmanagement/InspectionOrder.vue',
        name: 'marketingmanagementinspectionorder',
        component: () => import('@/views/marketingmanagement/InspectionOrder.vue')
      },
      {
        path: '/marketingmanagement/OrderApproval.vue',
        name: 'marketingmanagementorderapproval',
        component: () => import('@/views/marketingmanagement/OrderApproval.vue')
      },
      {
        path: '/marketingmanagement/MedicalExaminationLedger.vue',
        name: 'marketingmanagementmedicalexaminationledger',
        component: () => import('@/views/marketingmanagement/MedicalExaminationLedger.vue')
      },
      {
        path: '/marketingmanagement/MarketingCommission.vue',
        name: 'marketingmanagementmarketingcommission',
        component: () => import('@/views/marketingmanagement/MarketingCommission.vue')
      },
      {
        path: '/marketingmanagement/MedicalExaminer.vue',
        name: 'marketingmanagementmedicalexaminer',
        component: () => import('@/views/marketingmanagement/MedicalExaminer.vue')
      }
    ]
  }
]

export default routes
