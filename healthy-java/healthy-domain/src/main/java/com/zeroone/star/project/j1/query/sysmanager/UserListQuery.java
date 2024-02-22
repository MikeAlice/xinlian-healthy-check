package com.zeroone.star.project.j1.query.sysmanager;

import io.swagger.annotations.Api;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import javax.validation.constraints.NotBlank;
import java.sql.Timestamp;
import java.time.LocalDateTime;

@Data
@ApiModel("获取用户列表传入的数据对象")
public class UserListQuery {
    @ApiModelProperty(value = "当前页码", example = "1", required = true)
    private Long pageIndex;
    @ApiModelProperty(value = "每页显示最大数据条数", example = "10", required = true)
    private Long pageSize;
    @ApiModelProperty(value = "用户名", example = "管理员")
    private String nickname;
    @ApiModelProperty(value = "所属部门名称", example = "成都零壹星球健康体检中心")
    private String departmentTitle;
    @ApiModelProperty(value = "手机", example = "18782059031")
    private String mobile;
    @ApiModelProperty(value = "邮箱", example = "admin@01xq.com")
    private String email;
    @ApiModelProperty(value = "性别", example = "男")
    private String sex;
    @ApiModelProperty(value = "登录账号", example = "admin")
    private String username;
    @ApiModelProperty(value = "用户ID", example = "682265633886208")
    private String id;
    @ApiModelProperty(value = "创建时间", example = "2023-12-26 15:18:32")
    private LocalDateTime createTime;
}
