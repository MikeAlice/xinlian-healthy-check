package com.zeroone.star.project.j1.dto.sysmanager;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;
import org.hibernate.validator.constraints.Length;

import javax.validation.constraints.NotBlank;

@Data
@AllArgsConstructor
@NoArgsConstructor
@ApiModel("修改密码数据对象")
public class ModifyPasswordDTO {

    @NotBlank(message = "旧密码不能为空")
    @ApiModelProperty(value = "旧密码", example = "123456",required = true)
    private String password;

    @Length(message = "密码长度不能超过{max}个",max = 20)
    @NotBlank(message = "密码不能为空")
    @ApiModelProperty(value = "新密码", example = "12345678",required = true)
    private String new_password;

    @NotBlank(message = "被修改密码的用户的id不能为空")
    @ApiModelProperty(value = "被修改密码的用户的id", example = "682265633886208",required = true)
    private String id;


    @NotBlank(message = "密码强度不能为空")
    @ApiModelProperty(value = "密码强度", example = "弱",required = true)
    private String pass_strength;


}
