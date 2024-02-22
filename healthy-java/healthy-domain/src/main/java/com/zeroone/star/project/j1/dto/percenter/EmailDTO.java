package com.zeroone.star.project.j1.dto.percenter;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import javax.validation.constraints.Email;
import javax.validation.constraints.NotBlank;

@Data
@ApiModel("修改邮箱传输的数据")
public class EmailDTO {
    @Email
    @ApiModelProperty(value = "邮箱", required = true, example = "admin@01xq.com")
    private String email;

    @NotBlank(message = "验证码不能为空")
    @ApiModelProperty(value = "验证码", required = true, example = "998007")
    private String verificationCode;
}
