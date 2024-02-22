package com.zeroone.star.sysmanager.mapper;

import com.zeroone.star.project.j1.vo.sysmanager.UserNameListVO;
import com.zeroone.star.sysmanager.entity.TUser;
import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Select;

import java.time.LocalDateTime;
import java.util.List;

/**
 * <p>
 * 用户 Mapper 接口
 * </p>
 *
 * @author 阿布
 * @since 2024-01-23
 */
@Mapper
public interface TUserMapper extends BaseMapper<TUser> {


    /**
     * 批量删除用户
     * @param ids
     */
    void deleteUserByIds(List<Long> ids, LocalDateTime updateTime, String UpdateBy);

    /**
     * 修改用户信息
     * @param tUser
     */
    void updateUser(TUser tUser);

}
