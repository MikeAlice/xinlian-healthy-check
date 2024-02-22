package com.zeroone.star.sysmanager.mapper;


import com.zeroone.star.project.j1.vo.sysmanager.entiy.Role;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Select;

import java.util.List;

@Mapper
public interface RoleMapper {
     @Select("select t.name from t_role t left join t_user_role tr on t.id = tr.role_id where tr.user_id = #{id}")
     List<Role> selectRoleByUserId(Long id);

     @Select("select id from zo_healthy.t_role where name = #{role}")
     Long selectRoleIdByName(String role);
}
