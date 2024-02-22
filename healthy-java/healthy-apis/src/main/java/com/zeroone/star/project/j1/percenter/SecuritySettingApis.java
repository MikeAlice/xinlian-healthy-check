package com.zeroone.star.project.j1.percenter;

import com.zeroone.star.project.j1.dto.percenter.EmailDTO;
import com.zeroone.star.project.j1.dto.percenter.GetSmsCodeDTO;
import com.zeroone.star.project.j1.dto.percenter.ModifyPasswordDTO;
import com.zeroone.star.project.j1.dto.percenter.ModifyPhoneDTO;
import com.zeroone.star.project.j1.query.percenter.EmailCodeQuery;
import com.zeroone.star.project.j1.query.sysmanager.PasswordAuthenticationQuery;
import com.zeroone.star.project.vo.JsonVO;


/**
 * 个人中心-安全设置相关接口
 */
public interface SecuritySettingApis {

    /**
     * 密码身份验证
     * @param passwordAuthenticationQuery 密码身份验证传入的数据
     * @return
     */
    JsonVO<String> passwordAuthentication(PasswordAuthenticationQuery passwordAuthenticationQuery);

    /**
     * 修改密码接口
     *
     * @param modifyPasswordVO 修改密码视图对象
     * @return 修改结果
     */
     JsonVO<String> changePassword(ModifyPasswordDTO modifyPasswordVO);

    /**
     * 修改手机接口
     *
     * @param modifyPhoneDTO 修改手机号视图对象
     * @return 修改结果
     */
    JsonVO<String> changePhone(ModifyPhoneDTO modifyPhoneDTO);

    /**
     * 系统管理-用户管理，用户邮箱修改相关接口（修改用户邮箱）
     *
     */
    JsonVO modifyMail(EmailDTO emailDTO);

    /**
     * 获取短信验证码
     * @param getSmsCodeDTO 获取短信验证码数据传输对象
     * @return 字符串提示消息
     */
    JsonVO<String> getSmsCode(GetSmsCodeDTO getSmsCodeDTO);

    /**
     * 获取邮箱验证码
     * @param emailCodeQuery 获取邮箱验证码数据传输对象
     * @return 字符串提示消息
     */
    JsonVO getEmailCode(EmailCodeQuery emailCodeQuery);
}
