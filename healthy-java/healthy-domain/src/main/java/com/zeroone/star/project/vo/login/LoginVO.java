package com.zeroone.star.project.vo.login;

import io.swagger.annotations.Api;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.time.LocalDateTime;
import java.util.List;

/**
 * <p>
 * 描述：登录显示数据对象
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author 阿伟学长
 * @version 1.0.0
 */
@ApiModel("登录显示对象")
@Data
public class LoginVO {
    @ApiModelProperty(value = "用户唯一编号", example = "1")
    private Integer id;

    @ApiModelProperty(value = "用户名", example = "admin")
    private String username;

    @ApiModelProperty(value = "是否启用 1 启用 0 禁用 ", example = "1")
    private Byte status;

    @ApiModelProperty(value = "用户角色列表", example = "['ADMIN','MANAGER']")
    private List<String> roles;

    @ApiModelProperty(value = "头像")
    private String avatar;

    @ApiModelProperty(value = "用户名", example = "管理员")
    private String nickname;

    @ApiModelProperty(value = "性别", example = "男")
    private String sex;

    @ApiModelProperty(value = "生日")
    private LocalDateTime birth;

    @ApiModelProperty(value = "所在省市")
    private String address;

    @ApiModelProperty(value = "街道地址")
    private String street;

    @ApiModelProperty(value = "个人简介")
    private String description;

    @ApiModelProperty(value = "签名文件")
    private String autograph;

    @ApiModelProperty(value = "手机号")
    private String mobile;

    @ApiModelProperty(value = "邮箱")
    private String email;
}
