package com.zeroone.star.sysmanager.mapper;

import org.apache.ibatis.annotations.Select;
import org.apache.ibatis.annotations.Mapper;

@Mapper
public interface DepartmentMapper {
    @Select("select title from zo_healthy.t_department where id = #{departmentId}")
    String selectTitleById(Long departmentId);
}
