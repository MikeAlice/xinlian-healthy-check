package com.zeroone.star.login.mapper;

import org.apache.ibatis.annotations.Mapper;

import java.util.List;

@Mapper
public interface RoleMapper {
    /**
     * 获取当前用户的角色
     *
     * @param id
     * @return
     */
    List selectUserRoles(Long id);
}
