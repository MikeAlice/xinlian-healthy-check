package com.zeroone.star.project.j1.vo.sysmanager;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.io.Serializable;

@Data
@ApiModel("用户名称")
public class UserNameListVO implements Serializable {
    @ApiModelProperty(value = "唯一ID", example = "682265633886208")
    private Long id;
    @ApiModelProperty(value = "用户昵称", example = "管理员")
    private String nickname;
}
