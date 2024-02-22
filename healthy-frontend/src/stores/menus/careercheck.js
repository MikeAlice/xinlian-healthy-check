// 职业体检菜单数据
let testMenus = {
  id: 3,
  text: '职业体检系统',
  icon: 'IconUser',
  children: [
    {
      //用来展示整个诊断流程
      id: 1,
      text: '流程展示',
      href: '/careercheck/NavigationShow.vue',
      icon: 'IconSetting',
      pid: 1
    },
    {
      id: 2,
      text: '团检单位',
      href: '/careercheck/InspectionCompany.vue',
      icon: 'IconSetting',
      pid: 1
    },
    {
      id: 3,
      text: '团检订单',
      href: '/careercheck/GroupOrder.vue',
      icon: 'IconSetting',
      pid: 1
    },
    {
      id: 4,
      text: '体检人员',
      href: '/careercheck/MedicalExaminer.vue',
      icon: 'IconSetting',
      pid: 1
    },
    {
      id: 5,
      text: '合同审批',
      href: '/careercheck/ContractApproval.vue',
      icon: 'IconSetting',
      pid: 1
    },
    {
      id: 6,
      text: '体检登记',
      href: '/careercheck/MedicalRegistration.vue',
      icon: 'IconSetting',
      pid: 1
    },
    {
      id: 7,
      text: '体检诊台',
      href: '/careercheck/MedicalExamination.vue',
      icon: 'IconSetting',
      pid: 1
    },
    {
      id: 8,
      text: '医生总检',
      href: '/careercheck/DoctorInspection.vue',
      icon: 'IconSetting',
      pid: 1
    },
    {
      id: 9,
      text: '报告审核',
      href: '/careercheck/ReportAudit.vue',
      icon: 'IconSetting',
      pid: 1
    },
    {
      id: 10,
      text: '体检报告',
      href: '/careercheck/MedicalReport.vue',
      icon: 'IconSetting',
      pid: 1
    },
    {
      id: 11,
      text: '单位报告',
      href: '/careercheck/CompanyReport.vue',
      icon: 'IconSetting',
      pid: 1
    },
    {
      id: 12,
      text: '查询统计',
      href: '/careercheck/QueryStatistics.vue',
      icon: 'IconSetting',
      pid: 1
    },
    {
      id: 13,
      text: '数据网报',
      href: '/careercheck/NetworkRecords.vue',
      icon: 'IconSetting',
      pid: 1
    }
  ]
}

export default testMenus
