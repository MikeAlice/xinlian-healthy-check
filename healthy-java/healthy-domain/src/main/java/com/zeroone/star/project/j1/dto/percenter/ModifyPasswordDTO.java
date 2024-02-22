package com.zeroone.star.project.j1.dto.percenter;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import javax.validation.constraints.NotBlank;

/**
 * 用户密码修改的数据传输对象
 */
@Data
@ApiModel(description = "用户修改密码信息")
public class ModifyPasswordDTO {

    @NotBlank(message = "原密码不能为空")
    @ApiModelProperty(value = "原密码", required = true, example = "123456")
    private String oldPassword;

    @NotBlank(message = "新密码不能为空")
    @ApiModelProperty(value = "新密码", required = true, example = "123456789")
    private String newPassword;

}