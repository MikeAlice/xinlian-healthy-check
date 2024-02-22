// 健康管理系统
let testMenus = {
  id: 1,
  text: '健康体检系统',
  icon: 'IconUser',
  children: [
    {
      //用来展示整个诊断流程
      id: 1,
      text: '流程展示',
      href: '/healthcheck/NavigationShow.vue',
      icon: 'IconSetting',
      pid: 1
    },
    {
      id: 2,
      text: '团检单位',
      href: '/healthcheck/InspectionCompany.vue',
      icon: 'IconSetting',
      pid: 1
    },
    {
      id: 3,
      text: '团检订单',
      href: '/healthcheck/GroupOrder.vue',
      icon: 'IconSetting',
      pid: 1
    },
    {
      id: 4,
      text: '体检人员',
      href: '/healthcheck/MedicalExaminer.vue',
      icon: 'IconSetting',
      pid: 1
    },
    {
      id: 5,
      text: '合同审批',
      href: '/healthcheck/ContractApproval.vue',
      icon: 'IconSetting',
      pid: 1
    },
    {
      id: 6,
      text: '体检登记',
      href: '/healthcheck/MedicalRegistration.vue',
      icon: 'IconSetting',
      pid: 1
    },
    {
      id: 7,
      text: '体检诊台',
      href: '/healthcheck/MedicalExamination.vue',
      icon: 'IconSetting',
      pid: 1
    },
    {
      id: 8,
      text: '医生总检',
      href: '/healthcheck/DoctorInspection.vue',
      icon: 'IconSetting',
      pid: 1
    },
    {
      id: 9,
      text: '报告审核',
      href: '/healthcheck/ReportAudit.vue',
      icon: 'IconSetting',
      pid: 1
    },
    {
      id: 10,
      text: '体检报告',
      href: '/healthcheck/MedicalReport.vue',
      icon: 'IconSetting',
      pid: 1
    },
    {
      id: 11,
      text: '单位报告',
      href: '/healthcheck/CompanyReport.vue',
      icon: 'IconSetting',
      pid: 1
    },
    {
      id: 12,
      text: '查询统计',
      href: '/healthcheck/QueryStatistics.vue',
      icon: 'IconSetting',
      pid: 1
    }
  ]
}

export default testMenus
