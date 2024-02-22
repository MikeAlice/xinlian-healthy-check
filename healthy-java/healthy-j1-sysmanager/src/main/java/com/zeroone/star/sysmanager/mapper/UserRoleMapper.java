package com.zeroone.star.sysmanager.mapper;

import com.zeroone.star.sysmanager.entity.TUserRole;
import org.apache.ibatis.annotations.Mapper;

import java.util.List;

@Mapper
public interface UserRoleMapper {

    /**
     * 用户角色表新增数据
     * @param list
     */
    void insert(List<TUserRole> list);
}
