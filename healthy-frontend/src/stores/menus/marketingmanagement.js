// 营销管理
let marketingmanagement = [
  {
    id: 5,
    text: '营销管理',
    icon: 'IconUser',
    children: [
      {
        //用来展示整个诊断流程
        id: 1,
        text: '团检单位',
        href: '/marketingmanagement/InspectionCompany.vue',
        icon: 'IconSetting',
        pid: 1
      },
      {
        //用来展示整个诊断流程
        id: 2,
        text: '团检订单',
        href: '/marketingmanagement/InspectionOrder.vue',
        icon: 'IconSetting',
        pid: 1
      },
      {
        //用来展示整个诊断流程
        id: 3,
        text: '团单审批',
        href: '/marketingmanagement/OrderApproval.vue',
        icon: 'IconSetting',
        pid: 1
      },
      {
        //用来展示整个诊断流程
        id: 4,
        text: '体检台账',
        href: '/marketingmanagement/MedicalExaminationLedger.vue',
        icon: 'IconSetting',
        pid: 1
      },
      {
        //用来展示整个诊断流程
        id: 5,
        text: '营销提成',
        href: '/marketingmanagement/MarketingCommission.vue',
        icon: 'IconSetting',
        pid: 1
      },
      {
        //用来展示整个诊断流程
        id: 6,
        text: '团检人员',
        href: '/marketingmanagement/MedicalExaminer.vue',
        icon: 'IconSetting',
        pid: 1
      }
    ]
  }
]

export { marketingmanagement }
