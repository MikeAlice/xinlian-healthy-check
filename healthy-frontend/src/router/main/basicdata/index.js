const routes = [
  {
    path: '/basicdata',
    name: 'basicdata',
    redirect: '/basicdata/DepartmentManagement.vue',
    children: [
      {
        // 科室管理
        path: '/basicdata/DepartmentManagement.vue',
        name: 'basicdatadepartmentmanagement',
        component: () => import('@/views/basicdata/DepartmentManagement.vue')
      },
      {
        path: '/basicdata/BasicProject.vue',
        name: 'basicdatabasicproject',
        component: () => import('@/views/basicdata/BasicProject.vue')
      },
      {
        path: '/basicdata/PortfolioItems.vue',
        name: 'basicdataportfolioitems',
        component: () => import('@/views/basicdata/PortfolioItems.vue')
      },
      {
        path: '/basicdata/CheckUpPackage.vue',
        name: 'basicdatacheckUppackage',
        component: () => import('@/views/basicdata/CheckUpPackage.vue')
      },
      {
        path: '/basicdata/SampleLibrary.vue',
        name: 'basicdatasamplelibrary',
        component: () => import('@/views/basicdata/SampleLibrary.vue')
      }
    ]
  }
]

export default routes
