package com.zeroone.star.project.j1.dto.percenter;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.time.LocalDateTime;

/**
 *  验证码验证的数据传输对象
 */
@Data
@ApiModel(value = "VerificationCodeDTO", description = "验证码验证的数据传输对象")
public class VerificationCodeDTO {
    @ApiModelProperty(value = "验证码ID")
    private Long id;

    @ApiModelProperty(value = "验证码", required = true)
    private String code;

    @ApiModelProperty(value = "创建时间", notes = "验证码的生成时间")
    private LocalDateTime createTime;

    @ApiModelProperty(value = "状态", notes = "验证码的状态：true为有效，false为过期")
    private Boolean status;

    @ApiModelProperty(value = "验证码类型", example = "email或sms", required = true)
    private String type;

    @ApiModelProperty(value = "接收邮箱或手机号码", required = true)
    private String value;

    @ApiModelProperty(value = "业务场景", example = "重置密码或重置邮箱", required = true)
    private String scenes;

}