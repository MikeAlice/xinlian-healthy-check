package com.zeroone.star.project.j1.dto.percenter;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import javax.validation.constraints.NotBlank;

/**
 * 用户手机号修改的数据传输对象
 */
@Data
@ApiModel(value = "ModifyPhoneDTO", description = "用户修改手机号的数据传输对象")
public class ModifyPhoneDTO {

    @NotBlank(message = "新手机号不能为空")
    @ApiModelProperty(value = "新手机号", required = true, example = "19864394134")
    private String newPhone;

    @NotBlank(message = "验证码不能为空")
    @ApiModelProperty(value = "验证码", required = true, example = "998007")
    private String verificationCode;
}