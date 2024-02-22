package com.zeroone.star.role.service;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.j2.dto.RoleDTO;
import com.zeroone.star.project.j2.dto.RoleNameDTO;
import com.zeroone.star.project.j2.query.RoleCriteriaQuery;
import com.zeroone.star.role.config.entity.TRole;
import com.baomidou.mybatisplus.extension.service.IService;

/**
 * <p>
 * 角色 服务类
 * </p>
 *
 * @author camille
 * @since 2024-01-15
 */
public interface ITRoleService extends IService<TRole> {
    //获取角色名称列表
    public RoleNameDTO getRoleNames();
    
    //条件加分页查询角色列表
    public PageDTO<RoleDTO> getByCondition(RoleCriteriaQuery roleCriteriaQuery);
}
