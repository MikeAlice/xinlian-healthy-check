package com.zeroone.star.project.j2;

import com.zeroone.star.project.vo.JsonVO;

public interface RolePermissionApis {
    /**
     * 查看角色菜单权限
     * @param id
     * @return
     */
    JsonVO queryRoleMenuPermission(long id);
}
