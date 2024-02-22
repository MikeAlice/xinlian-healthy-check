package com.zeroone.star.project.j1.vo.percenter;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
 * 修改邮箱视图对象
 */
@Data
@ApiModel(description = "用户修改邮箱信息")
public class ModifyEmailVO {
    @ApiModelProperty(value = "用户ID", required = true)
    private Long userId;

    @ApiModelProperty(value = "用户密码", required = true)
    private String password;

    @ApiModelProperty(value = "新邮箱地址", required = true)
    private String newEmail;

    @ApiModelProperty(value = "邮箱中收到的验证码", required = true)
    private String verificationCode;
}
