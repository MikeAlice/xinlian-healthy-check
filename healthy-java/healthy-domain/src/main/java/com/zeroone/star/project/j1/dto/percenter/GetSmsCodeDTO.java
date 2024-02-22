package com.zeroone.star.project.j1.dto.percenter;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import javax.validation.constraints.NotBlank;

@Data
@ApiModel(value = "获取短信验证码", description = "获取短信验证码数据传输对象")
public class GetSmsCodeDTO {
    @NotBlank(message = "手机号不能为空")
    @ApiModelProperty(value = "手机号", required = true, example = "19864394134")
    private String newPhone;
}
