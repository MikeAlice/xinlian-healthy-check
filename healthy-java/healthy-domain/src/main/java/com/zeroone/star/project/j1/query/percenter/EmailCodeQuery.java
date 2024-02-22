package com.zeroone.star.project.j1.query.percenter;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import javax.validation.constraints.NotBlank;

@Data
@ApiModel("获取邮箱验证码数据传输对象")
public class EmailCodeQuery {
    @NotBlank(message = "邮箱不能为空")
    @ApiModelProperty(value = "邮箱", required = true, example = "admin@01xq.com")
    private String email;
}
