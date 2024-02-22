package com.zeroone.star.percenter.service.impl;

import cn.hutool.core.bean.BeanUtil;
import com.baomidou.mybatisplus.core.conditions.update.UpdateWrapper;
import com.zeroone.star.percenter.entity.TUser;
import com.zeroone.star.percenter.mapper.TUserMapper;
import com.zeroone.star.percenter.service.ITUserService;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.project.components.user.UserDTO;
import com.zeroone.star.project.components.user.UserHolder;
import com.zeroone.star.project.j1.dto.percenter.EmailDTO;
import com.zeroone.star.project.j1.dto.percenter.ModifyPasswordDTO;
import com.zeroone.star.project.j1.dto.percenter.ModifyPersonalInfoDTO;
import com.zeroone.star.project.j1.dto.percenter.ModifyPhoneDTO;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.ResultStatus;
import org.mapstruct.Mapper;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.data.redis.core.RedisTemplate;
import org.springframework.security.crypto.password.PasswordEncoder;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;
import java.time.LocalDateTime;

@Mapper(componentModel = "spring")
interface MsUserMapper{
    /**
     * 将ModifyPersonalInfoDTO转成TUser
     * @param modifyPersonalInfoDTO 转换的DTO
     * @return 转换结果
     */
    TUser modifyPersonalInfoDTOToTUser(ModifyPersonalInfoDTO modifyPersonalInfoDTO);
}
/**
 * <p>
 * 用户 服务实现类
 * </p>
 *
 * @author feng
 * @since 2024-01-25
 */
@Service
public class TUserServiceImpl extends ServiceImpl<TUserMapper, TUser> implements ITUserService {

    @Resource
    private UserHolder userHolder;      // 用户信息获取组件
    @Resource
    private PasswordEncoder passwordEncoder;        // 处理密码的加密和验证
    @Resource
    private TUserMapper userMapper;
    @Resource
    private MsUserMapper msUserMapper; // 将各类型的DTO转换成TUser实体
    @Resource
    private RedisTemplate redisTemplate;


    /**
     * 更新用户密码。
     * 该方法首先获取当前用户信息，验证旧密码，然后更新为新密码。
     *
     * @param modifyPasswordDTO 包含旧密码和新密码的数据传输对象
     * @return JsonVO<String> 表示操作结果，成功或失败信息
     */
    public JsonVO<String> modifyPassword(ModifyPasswordDTO modifyPasswordDTO) {
        try {
            // 从token中获取当前用户信息
            TUser user = getUserByToken();

            // 使用PasswordEncoder来验证密码
            if (!passwordEncoder.matches(modifyPasswordDTO.getOldPassword(), user.getPassword())) {
                return JsonVO.fail("旧密码不正确");
            }

            // 使用PasswordEncoder来加密新密码
            user.setPassword(passwordEncoder.encode(modifyPasswordDTO.getNewPassword()));
            // 修改密码
            UpdateWrapper<TUser> wrapper = new UpdateWrapper<>();
            wrapper.eq("id", user.getId()).set("password", user.getPassword());
            baseMapper.update(null, wrapper);

            return JsonVO.success("密码更新成功");
        } catch (Exception e) {
            return JsonVO.fail("密码更新失败: " + e.getMessage());
        }
    }

    /**
     * 修改个人基础信息
     * @param modifyPersonalInfoDTO 可修改的个人基础信息
     * @return
     */
    @Override
    public void updatePersonalInfo(ModifyPersonalInfoDTO modifyPersonalInfoDTO) {
        TUser user = getUserByToken();
        TUser tUser = msUserMapper.modifyPersonalInfoDTOToTUser(modifyPersonalInfoDTO);
        tUser.setId(user.getId());
        tUser.setUpdateTime(LocalDateTime.now());
        tUser.setUpdateBy(user.getUsername());
        userMapper.updatePersonalInfo(tUser);
    }

    /**
     * 密码身份验证
     * @param password 用户传入的密码
     */
    @Override
    public void passwordAuthentication(String password) {
        TUser user = getUserByToken();
        // 使用PasswordEncoder来验证密码
        if (!passwordEncoder.matches(password, user.getPassword())) {
            throw new RuntimeException("密码验证失败");
        }
    }

    //    @Autowired
//    private VerificationCodeService verificationCodeService;    // 验证码服务

    /**
     * 更新用户手机号。
     * 该方法首先验证提供的验证码，然后更新用户的手机号信息。
     * @param modifyPhoneDTO 包含新手机号和验证码的数据传输对象
     * @return JsonVO<String> 表示操作结果，成功或失败信息
     */
    public void modifyPhone(ModifyPhoneDTO modifyPhoneDTO) {
//        try {
//            UserDTO currentUser = userHolder.getCurrentUser();
//            Long userId = currentUser.getId();
//
//            if (!verificationCodeService.checkCode(modifyPhoneDTO.getNewPhone(), modifyPhoneDTO.getVerificationCode())) {
//                return JsonVO.fail("验证码不正确或已过期");
//            }
//
//            TUser user = this.getById(userId);
//            if (user == null) {
//                return JsonVO.fail("用户不存在");
//            }
//
//            user.setMobile(modifyPhoneDTO.getNewPhone());
//            this.updateById(user);
//
//            return JsonVO.success("手机号更新成功");
//        } catch (Exception e) {
//            return JsonVO.fail("手机号更新失败: " + e.getMessage());
//        }
        TUser userByToken = getUserByToken();
        String SmsCode = userByToken.getId() + ":" + modifyPhoneDTO.getNewPhone();
        String code = String.valueOf(redisTemplate.opsForValue().get(SmsCode));
        if (!modifyPhoneDTO.getVerificationCode().equals(code)) {
            throw new RuntimeException("验证码错误");
        }
        userMapper.updatePhone(modifyPhoneDTO.getNewPhone(), LocalDateTime.now(), userByToken.getUsername(), userByToken.getId());
    }

    /**
     * 修改邮箱
     * @param emailDTO
     */
    @Override
    public void modifyEmail(EmailDTO emailDTO) {
        TUser userByToken = getUserByToken();
        String emailCode = userByToken.getId() + ":" + emailDTO.getEmail();
        String code = String.valueOf(redisTemplate.opsForValue().get(emailCode));
        if (!emailDTO.getVerificationCode().equals(code)) {
            throw new RuntimeException("验证码错误");
        }
        userMapper.updateEmail(emailDTO.getEmail(), LocalDateTime.now(), userByToken.getUsername(), userByToken.getId());
    }

    /**
     * 从userHolder中获取用户信息
     * @return
     */
    public TUser getUserByToken() {
        UserDTO currentUser = null;
        try {
            currentUser = userHolder.getCurrentUser();
        } catch (Exception e) {
            throw new RuntimeException(ResultStatus.UNAUTHORIZED.getMessage());
        }
        Long userId = currentUser.getId();
        TUser user = this.getById(userId);
        if (user == null || user.getDelFlag()) {
            throw new RuntimeException("用户不存在");
        }
        if (user.getStatus() == 1) {
            throw new RuntimeException("用户处于禁用状态");
        }
        return user;
    }
}
