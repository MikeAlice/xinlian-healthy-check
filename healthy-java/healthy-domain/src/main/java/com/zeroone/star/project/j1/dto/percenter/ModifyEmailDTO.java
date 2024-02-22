package com.zeroone.star.project.j1.dto.percenter;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

@Data
@ApiModel(value = "ModifyEmailDTO", description = "用户修改邮箱的数据传输对象")
public class ModifyEmailDTO {
    @ApiModelProperty(value = "用户ID", required = true)
    private Long userId;

    @ApiModelProperty(value = "用户密码", required = true)
    private String password;

    @ApiModelProperty(value = "新邮箱", required = true)
    private String newEmail;

    @ApiModelProperty(value = "邮箱中收到的验证码", required = true)
    private String verificationCode;
}
