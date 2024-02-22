package com.zeroone.star.percenter.service;

import com.zeroone.star.percenter.entity.TUser;
import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.project.j1.dto.percenter.EmailDTO;
import com.zeroone.star.project.j1.dto.percenter.ModifyPasswordDTO;
import com.zeroone.star.project.j1.dto.percenter.ModifyPersonalInfoDTO;
import com.zeroone.star.project.j1.dto.percenter.ModifyPhoneDTO;
import com.zeroone.star.project.vo.JsonVO;

/**
 * <p>
 * 用户 服务类
 * </p>
 *
 * @author feng
 * @since 2024-01-25
 */
public interface ITUserService extends IService<TUser> {

    /**
     * 修改用户密码。
     * 根据提供的信息更改用户的密码。
     *
     * @param modifyPasswordDTO 包含用户旧密码和新密码的数据传输对象
     * @return JsonVO<String> 返回操作的结果，包括成功或失败的信息
     */
    JsonVO<String> modifyPassword(ModifyPasswordDTO modifyPasswordDTO);

    /**
     * 修改个人基础信息
     * @param modifyPersonalInfoDTO 可修改的个人基础信息
     * @return
     */
    void updatePersonalInfo(ModifyPersonalInfoDTO modifyPersonalInfoDTO) throws Exception;

    /**
     * 密码身份验证
     * @param password 用户传入的密码
     */
    void passwordAuthentication(String password);

    /**
     * 修改用户手机号。
     * 根据提供的信息更改用户的手机号码。
     *
     * @param modifyPhoneDTO 包含用户新手机号和验证码的数据传输对象
     * @return JsonVO<String> 返回操作的结果，包括成功或失败的信息
     */
    void modifyPhone(ModifyPhoneDTO modifyPhoneDTO);

    /**
     * 修改邮箱
     * @param emailDTO
     */
    void modifyEmail(EmailDTO emailDTO);

    TUser getUserByToken();
}
