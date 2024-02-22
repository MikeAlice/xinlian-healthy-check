// 测试菜单数据
let testMenus = {
  id: 2,
  text: '从业体检系统',
  icon: 'IconUser',
  children: [
    {
      //用来展示整个诊断流程
      id: 1,
      text: '流程展示',
      href: '/employmentcheck/NavigationShow.vue',
      icon: 'IconSetting',
      pid: 1
    },
    {
      //用来展示整个诊断流程
      id: 2,
      text: '单位信息',
      href: '/employmentcheck/CompanyInfo.vue',
      icon: 'IconSetting',
      pid: 1
    },
    {
      id: 3,
      text: '体检登记',
      href: '/employmentcheck/MedicalRegistration.vue',
      icon: 'IconSetting',
      pid: 1
    },
    {
      id: 4,
      text: '体检诊台',
      href: '/employmentcheck/MedicalExamination.vue',
      icon: 'IconSetting',
      pid: 1
    },
    {
      id: 5,
      text: '医生总检',
      href: '/employmentcheck/DoctorInspection.vue',
      icon: 'IconSetting',
      pid: 1
    },
    {
      id: 6,
      text: '体检报告',
      href: '/employmentcheck/MedicalReport.vue',
      icon: 'IconSetting',
      pid: 1
    },
    {
      id: 7,
      text: '健康证',
      href: '/employmentcheck/HealthCertificate.vue',
      icon: 'IconSetting',
      pid: 1
    }
  ]
}

export default testMenus
