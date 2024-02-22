package com.zeroone.star.project.j1.dto.percenter;


import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.time.LocalDateTime;
import java.util.List;

@Data
@ApiModel(value = "新建用户", description = "获取新用户数据传输对象")
public class CreateUserDTO {

    @ApiModelProperty(value = "登陆账号", required = true)
    private String username;

    @ApiModelProperty(value = "登陆密码", required = true)
    private String password;

    @ApiModelProperty(value = "用户名", required = true)
    private String nickname;

    @ApiModelProperty(value = "手机号", required = true)
    private String mobile;

    @ApiModelProperty(value = "所属部门ID", required = true)
    private Long departmentId;

    @ApiModelProperty(value = "邮箱")
    private String email;

    @ApiModelProperty(value = "性别", example = "男")
    private String sex;

    @ApiModelProperty(value = "用户类型", example = "0")
    private int type;

    @ApiModelProperty(value = "头像")
    private String avatar;

    @ApiModelProperty(value = "角色分配")
    private List<Long> roleIds;

    @ApiModelProperty(value = "所在地区")
    private String address;

    @ApiModelProperty(value = "街道地址")
    private String street;

    @ApiModelProperty(value = "签名文件")
    private String autograph;

    @ApiModelProperty(value = "生日")
    private LocalDateTime birth;

    @ApiModelProperty(value = "简介")
    private String description;

    public CreateUserDTO() {
    }
}
