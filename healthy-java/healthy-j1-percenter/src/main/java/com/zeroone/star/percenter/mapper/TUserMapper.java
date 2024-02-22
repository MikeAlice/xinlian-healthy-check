package com.zeroone.star.percenter.mapper;

import com.zeroone.star.percenter.entity.TUser;
import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.project.j1.dto.percenter.ModifyPersonalInfoDTO;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Update;

import java.time.LocalDateTime;

/**
 * <p>
 * 用户 Mapper 接口
 * </p>
 *
 * @author feng
 * @since 2024-01-25
 */
@Mapper
public interface TUserMapper extends BaseMapper<TUser> {


    /**
     * 修改个人信息
     * @param tUser
     */
    void updatePersonalInfo(TUser tUser);

    /**
     * 修改手机号
     * @param newPhone
     * @param now
     * @param username
     * @param id
     */
    @Update("update zo_healthy.t_user set mobile = #{newPhone}, update_time = #{now}, update_by = #{username} where id = #{id}")
    void updatePhone(String newPhone, LocalDateTime now, String username, Long id);

    /**
     * 修改邮箱
     * @param email
     * @param now
     * @param username
     * @param id
     */
    @Update("update zo_healthy.t_user set email = #{email}, update_time = #{now}, update_by = #{username} where id = #{id}")
    void updateEmail(String email, LocalDateTime now, String username, Long id);
}
