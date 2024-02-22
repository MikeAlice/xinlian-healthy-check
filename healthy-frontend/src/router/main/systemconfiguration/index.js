const routes = [
  {
    path: '/systemconfiguration',
    name: 'systemconfiguration',
    redirect: '/systemconfiguration/UserManagement.vue',
    children: [
      {
        path: '/systemconfiguration/UserManagement.vue',
        name: 'systemconfigurationusermanagement',
        component: () => import('@/views/systemconfiguration/UserManagement.vue')
      },
      {
        path: '/systemconfiguration/DepartmentManagement.vue',
        name: 'systemconfigurationdepartmentmanagement',
        component: () => import('@/views/systemconfiguration/DepartmentManagement.vue')
      },
      {
        path: '/systemconfiguration/MessageManagement.vue',
        name: 'systemconfigurationMessageManagement',
        component: () => import('@/views/systemconfiguration/MessageManagement.vue')
      },
      {
        path: '/systemconfiguration/RoleManagement.vue',
        name: 'systemconfigurationRoleManagement',
        component: () => import('@/views/systemconfiguration/RoleManagement.vue')
      },
      {
        path: '/systemconfiguration/MenuManagement.vue',
        name: 'systemconfigurationMenuManagement',
        component: () => import('@/views/systemconfiguration/MenuManagement.vue')
      },
      {
        path: '/systemconfiguration/DataDictionary.vue',
        name: 'systemconfigurationDataDictionary',
        component: () => import('@/views/systemconfiguration/DataDictionary.vue')
      },
      {
        path: '/systemconfiguration/SystemConfiguration.vue',
        name: 'systemconfigurationSystemConfiguration',
        component: () => import('@/views/systemconfiguration/SystemConfiguration.vue')
      },
      {
        path: '/systemconfiguration/TypeLibrary.vue',
        name: 'systemconfigurationTypeLibrary',
        component: () => import('@/views/systemconfiguration/TypeLibrary.vue')
      }
    ]
  }
]

export default routes
