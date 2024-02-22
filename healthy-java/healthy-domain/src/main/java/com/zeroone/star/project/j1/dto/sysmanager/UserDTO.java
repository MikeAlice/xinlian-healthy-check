package com.zeroone.star.project.j1.dto.sysmanager;

import io.swagger.annotations.Api;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import io.swagger.annotations.ApiOperation;
import lombok.Data;
import lombok.NoArgsConstructor;

import java.sql.Timestamp;
import java.time.LocalDateTime;

@Data
@NoArgsConstructor
@ApiModel("用户列表展示数据")
public class UserDTO {
    @ApiModelProperty(value = "唯一ID", example = "682265633886208")
    private Long id;
    @ApiModelProperty(value = "登录账号", example = "admin")
    private String username;
    @ApiModelProperty(value = "用户名", example = "管理员")
    private String nickname;
    @ApiModelProperty(value = "头像")
    private String avatar;
    @ApiModelProperty(value = "所属部门编号", example = "40322777781112832")
    private Long departmentId;
    @ApiModelProperty(value = "所属部门名称", example = "成都零壹星球健康体检中心")
    private String departmentTitle;
    @ApiModelProperty(value = "手机", example = "18782059031")
    private String mobile;
    @ApiModelProperty(value = "性别", example = "男")
    private String sex;
    @ApiModelProperty(value = "类型(0 普通用户 1 管理员)", example = "1")
    private Integer type;
    @ApiModelProperty(value = "状态(0 启用 1 禁用)", example = "0")
    private Integer status;
    @ApiModelProperty(value = "创建时间", example = "2023-12-26 15:18:32")
    private LocalDateTime createTime;
}
