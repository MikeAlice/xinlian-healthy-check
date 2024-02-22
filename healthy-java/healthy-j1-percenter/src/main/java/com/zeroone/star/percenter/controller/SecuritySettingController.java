package com.zeroone.star.percenter.controller;


import cn.hutool.core.bean.BeanUtil;
import com.zeroone.star.percenter.service.ITUserService;
import com.zeroone.star.project.components.mail.MailComponent;
import com.zeroone.star.project.components.mail.MailMessage;
import com.zeroone.star.project.components.sms.aliyun.SmsComponent;
import com.zeroone.star.project.components.sms.aliyun.SmsResult;
import com.zeroone.star.project.components.user.UserHolder;
import com.zeroone.star.project.dto.mail.MailDTO;
import com.zeroone.star.project.j1.dto.percenter.EmailDTO;
import com.zeroone.star.project.j1.dto.percenter.GetSmsCodeDTO;
import com.zeroone.star.project.j1.dto.percenter.ModifyPasswordDTO;
import com.zeroone.star.project.j1.dto.percenter.ModifyPhoneDTO;
import com.zeroone.star.project.j1.percenter.SecuritySettingApis;
import com.zeroone.star.project.j1.query.percenter.EmailCodeQuery;
import com.zeroone.star.project.j1.query.sysmanager.PasswordAuthenticationQuery;
import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.data.redis.core.RedisTemplate;
import org.springframework.validation.annotation.Validated;
import org.springframework.web.bind.annotation.*;

import javax.annotation.Resource;
import java.util.HashMap;
import java.util.concurrent.TimeUnit;


@RestController
@RequestMapping("/security-setting")
@Api(tags = "安全设置")
@Validated
public class SecuritySettingController implements SecuritySettingApis {
    @Autowired
    private ITUserService userService;
    @Resource
    private SmsComponent sms; //短信服务组件
    @Resource
    private MailComponent mailComponent; //邮箱服务组件
    @Resource
    private RedisTemplate redisTemplate;

    /**
     * 密码身份验证
     * @param passwordAuthenticationQuery 密码身份验证传入的数据
     * @return
     */
    @Override
    @GetMapping("/password-authentication")
    @ApiOperation("密码身份验证")
    public JsonVO<String> passwordAuthentication(@Validated PasswordAuthenticationQuery passwordAuthenticationQuery){
        userService.passwordAuthentication(passwordAuthenticationQuery.getPassword());
        return JsonVO.success("密码验证成功");
    }

    /**
     * 用户修改自己的密码
     *
     * @param modifyPasswordDTO 修改密码视图对象
     * @return
     */
    @ApiOperation(value = "修改密码", notes = "用户修改自己的密码")
    @PostMapping("/change-password")
    @Override
    public JsonVO<String> changePassword(@RequestBody @Validated ModifyPasswordDTO modifyPasswordDTO) {
        return userService.modifyPassword(modifyPasswordDTO);
    }

    /**
     * 用户修改自己的手机号码
     *
     * @param modifyPhoneDTO 修改手机号视图对象
     * @return
     */
    @ApiOperation(value = "修改手机号", notes = "用户修改自己的手机号码")
    @PostMapping("/change-phone")
    @Override
    public JsonVO<String> changePhone(@RequestBody @Validated ModifyPhoneDTO modifyPhoneDTO) {
        userService.modifyPhone(modifyPhoneDTO);
        return JsonVO.success("修改手机号成功");
    }

    /**
     * 修改邮箱
     * @param emailDTO 修改后的邮箱
     * @return
     */
    @ApiOperation("修改邮箱")
    @PostMapping("/change-mail")
//    @ApiImplicitParam(name = "email",value = "修改后的邮箱，例如：admin@01xq.com",required = true)
    @Override
    public JsonVO modifyMail(@RequestBody EmailDTO emailDTO) {
        userService.modifyEmail(emailDTO);
        return JsonVO.success("修改邮箱成功");
    }

    /**
     * 获取短信验证码
     * @param getSmsCodeDTO 获取短信验证码数据传输对象
     * @return
     */
    @ApiOperation(value = "获取短信验证码")
    @GetMapping("/query-sms-code")
    @Override
    public JsonVO<String> getSmsCode(@Validated GetSmsCodeDTO getSmsCodeDTO) {
        HashMap<String, String> params = new HashMap<>();
        double random = Math.random() * 900000 + 100000;
        int code = (int)random;
        params.put("code", String.valueOf(code));
        SmsResult smsResult = sms.sendSms(getSmsCodeDTO.getNewPhone(), "阿里云短信测试", "SMS_154950909", params);
        if ("OK".equals(smsResult.getCode())) {
            String SmsCode = userService.getUserByToken().getId() + ":" + getSmsCodeDTO.getNewPhone();
            int time = 60 * 5;
            redisTemplate.opsForValue().set(SmsCode, code,  Long.valueOf(time), TimeUnit.SECONDS);
            return JsonVO.success(smsResult.toString());
        }
        return JsonVO.fail(smsResult.toString());
    }

    /**
     * 获取邮箱验证码
     * @param emailCodeQuery 获取邮箱验证码数据传输对象
     * @return 字符串提示消息
     */
    @ApiOperation(value = "获取邮箱验证码")
    @GetMapping("/query-email-code")
    @Override
    public JsonVO<MailMessage> getEmailCode(@Validated EmailCodeQuery emailCodeQuery) {
        MailMessage msg = new MailMessage();
        MailDTO mailDTO = new MailDTO();
        mailDTO.setTo(emailCodeQuery.getEmail());
        mailDTO.setCc("局长<1685052085@qq.com>");
        mailDTO.setSubject("修改邮箱验证码");
        double random = Math.random() * 900000 + 100000;
        int code = (int)random;
        mailDTO.setText("验证码是：" + code +"，如非本人操作，请忽略本邮件！");
        BeanUtil.copyProperties(mailDTO, msg);
        //发送邮件和附件
        MailMessage result = mailComponent.sendMail(msg);
        if ("ok".equals(result.getStatus())) {
            String emailCode = userService.getUserByToken().getId() + ":" + emailCodeQuery.getEmail();
            int time = 60 * 5;
            redisTemplate.opsForValue().set(emailCode, code,  Long.valueOf(time), TimeUnit.SECONDS);
            return JsonVO.success(result);
        }
        return JsonVO.fail(result);
    }
}
