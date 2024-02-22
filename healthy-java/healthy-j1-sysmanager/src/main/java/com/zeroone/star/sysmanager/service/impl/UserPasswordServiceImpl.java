package com.zeroone.star.sysmanager.service.impl;

import com.baomidou.mybatisplus.core.conditions.query.LambdaQueryWrapper;
import com.baomidou.mybatisplus.core.conditions.update.UpdateWrapper;
import com.zeroone.star.project.components.user.UserDTO;
import com.zeroone.star.project.components.user.UserHolder;
import com.zeroone.star.project.j1.dto.sysmanager.ModifyPasswordDTO;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.ResultStatus;
import com.zeroone.star.sysmanager.entity.TUser;
import com.zeroone.star.sysmanager.mapper.UserPasswordMapper;
import com.zeroone.star.sysmanager.service.UserPasswordService;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.security.crypto.bcrypt.BCryptPasswordEncoder;
import org.springframework.stereotype.Service;

import java.time.LocalDateTime;
import java.util.List;
import java.util.Objects;

/**
 * <p>
 * 用户 服务实现类
 * </p>
 *
 * @author light
 * @since 2024-01-18
 */
@Service("userPasswordService")
public class UserPasswordServiceImpl extends ServiceImpl<UserPasswordMapper, TUser> implements UserPasswordService {


    @Autowired
    UserHolder userHolder;

    /**
     * 修改密码
     * @param modifyPasswordDTO 修改密码DTO
     * @return
     */
    @Override
    public JsonVO updatePasswordToChange(ModifyPasswordDTO modifyPasswordDTO) {
        // 判断当前登录的用户是否为管理员账号(type字段是否为1)
        // 获取当前登录的用户id
        Long currentUserId;
        try {
            UserDTO currentUser = userHolder.getCurrentUser();
            currentUserId = currentUser.getId();
        } catch (Exception e) {
            return JsonVO.create(null,ResultStatus.UNAUTHORIZED);
        }
        TUser currentUserDO = getBaseMapper().selectById(currentUserId);
        // 获取被修改密码的用户
        TUser changeUser = getBaseMapper().selectById(modifyPasswordDTO.getId());
        // 判断被修改密码的用户是否存在
        if(Objects.isNull(changeUser)){
            return JsonVO.create(null,8000,"用户id非法");
        }
        // 当前登录的用户不是管理员则提示没有权限
        if(currentUserDO.getType() != 1){
            return JsonVO.create(null, ResultStatus.FORBIDDEN);
        }
        // 判断被修改密码的用户的新密码与旧密码是否相同
        if(modifyPasswordDTO.getPassword().equals(modifyPasswordDTO.getNew_password())){
            return JsonVO.create(null,9991,"新密码不能与现在的密码相同");
        }
        // 验证被修改用户的旧密码是否正确
        BCryptPasswordEncoder bCryptPasswordEncoder = new BCryptPasswordEncoder();
        boolean matches = bCryptPasswordEncoder.matches(modifyPasswordDTO.getPassword(),changeUser.getPassword());
        if(!matches){
            return JsonVO.create(null,9990,"旧密码输入有误");
        }
        // 使用加密后的新密码替换原来的密码,同时更改密码强度
        String encodePassword = bCryptPasswordEncoder.encode(modifyPasswordDTO.getNew_password());
        UpdateWrapper<TUser> tUserUpdateWrapper = new UpdateWrapper<>();
        tUserUpdateWrapper
                .set("password",encodePassword)
                .set("pass_strength",modifyPasswordDTO.getPass_strength())
                .set("update_by", currentUserDO.getUsername())
                .set("update_time", LocalDateTime.now())
                .eq("id",modifyPasswordDTO.getId());
        getBaseMapper().update(null,tUserUpdateWrapper);
        return JsonVO.success(null);
    }

    /**
     * 重置选中用户的密码为123456
     * @param ids 被重置密码的用户id
     * @return
     */
    @Override
    public JsonVO updatePasswordToReset(List<String> ids) {
        // 判断是否选择了被重置密码的用户
        if(ids == null || ids.size() == 0){
            return JsonVO.create(null,8001,"请选择需要被重置密码的用户");
        }
        // 获取当前登录的用户id
        Long currentUserId;
        try {
            UserDTO currentUser = userHolder.getCurrentUser();
            currentUserId = currentUser.getId();
        } catch (Exception e) {
            return JsonVO.create(null,ResultStatus.UNAUTHORIZED);
        }
        TUser currentUserDO = getBaseMapper().selectById(currentUserId);
        // 判断token解析后获得的id是否存在于数据库中
        if(Objects.isNull(currentUserDO)){
            return JsonVO.create(null,8000,"数据库中不存在此用户");
        }
        // 当前登录的用户不是管理员则提示权限不足
        if(currentUserDO.getType() != 1){
            return JsonVO.create(null, ResultStatus.FORBIDDEN);
        }

        // 被重置密码的用户中有管理员用户时就不能进行重置操作
        for(String id : ids){
            LambdaQueryWrapper<TUser> tUserLambdaQueryWrapper = new LambdaQueryWrapper<>();
            tUserLambdaQueryWrapper
                    .select(TUser::getId, TUser::getType)
                    .eq(TUser::getId,id);
            TUser tUserDO = getBaseMapper().selectOne(tUserLambdaQueryWrapper);
            // 判断数据库中是否存在数据
            if(Objects.isNull(tUserDO)){
                return JsonVO.create(null,8005,"存在非法的用户id");
            }
            if(tUserDO.getType() == 1){
                return JsonVO.create(null,8004,"不能重置管理员的密码");
            }
        }
        // 执行重置操作，重置选中用户的密码为123456
        for(String id : ids){
            BCryptPasswordEncoder bCryptPasswordEncoder = new BCryptPasswordEncoder();
            String password = bCryptPasswordEncoder.encode("123456");
            UpdateWrapper<TUser> tUserUpdateWrapper = new UpdateWrapper<>();
            tUserUpdateWrapper
                    .set("password",password)
                    .set("update_by", currentUserDO.getUsername())
                    .set("update_time", LocalDateTime.now())
                    .eq("id",id);
            getBaseMapper().update(null,tUserUpdateWrapper);
        }
        return JsonVO.success("重置完成");
    }
}
