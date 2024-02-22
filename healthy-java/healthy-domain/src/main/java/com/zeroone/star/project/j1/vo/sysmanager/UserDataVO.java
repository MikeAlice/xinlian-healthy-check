package com.zeroone.star.project.j1.vo.sysmanager;

import cn.hutool.core.date.DateTime;
import com.zeroone.star.project.j1.vo.sysmanager.entiy.Role;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.sql.Timestamp;
import java.time.LocalDateTime;
import java.util.List;

@Data
@ApiModel("用户详情")
public class UserDataVO {
    @ApiModelProperty(value = "唯一ID", example = "682265633886208")
    private Long id;
    @ApiModelProperty(value = "用户昵称", example = "test1")
    private String nickname;
    @ApiModelProperty(value = "头像")
    private String avatar;
    @ApiModelProperty(value = "登录账号", example = "管理员")
    private String username;
    @ApiModelProperty(value = "性别")
    private String sex;
    @ApiModelProperty(value = "生日")
    private LocalDateTime birth;
    @ApiModelProperty(value = "区域")
    private String address;
    @ApiModelProperty(value = "街道")
    private String street;
    @ApiModelProperty(value = "个人简介")
    private String description;
    @ApiModelProperty(value = "所属部门编号")
    private Long departmentId;
    @ApiModelProperty(value = "部门名称")
    private String departmentTitle;
    @ApiModelProperty(value = "用户类型")
    private Integer type;
    @ApiModelProperty(value = "医生签名图片")
    private String autograph;
    @ApiModelProperty(value = "邮箱")
    private String email;
    @ApiModelProperty(value = "手机号")
    private String mobile;

    @ApiModelProperty(value = "角色")
    private List<Role> roleList;

}
