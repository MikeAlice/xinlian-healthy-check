package com.zeroone.star.sysmanager.mapper;

import com.zeroone.star.sysmanager.entity.TUser;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Select;
import org.apache.ibatis.annotations.Update;

import java.time.LocalDateTime;

@Mapper
public interface UserMapper {
    @Update("update t_user set status = #{status}, update_time = #{updateTime}, update_by = #{updateBy} where id = #{id}")
    void updateUserStatus(Long id, Integer status, LocalDateTime updateTime, String updateBy);

    @Select("select * from t_user where id = #{id} and del_flag = 0")
    TUser selectById(Long id);
}
