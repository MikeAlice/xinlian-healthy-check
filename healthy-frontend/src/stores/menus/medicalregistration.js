// 体检登记
let medicalregistration = [
  {
    id: 6,
    text: '体检登记',
    icon: 'IconUser',
    children: [
      {
        //用来展示整个诊断流程
        id: 1,
        text: '体检登记',
        href: '/medicalregistration/MedicalRegistration.vue',
        icon: 'IconSetting',
        pid: 1
      }
    ]
  }
]

export { medicalregistration }
