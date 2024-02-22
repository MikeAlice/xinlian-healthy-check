package com.zeroone.star.project.j1.vo.sysmanager.entiy;

import cn.hutool.core.date.DateTime;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import io.swagger.models.auth.In;
import lombok.Data;

@Data
@ApiModel("角色分配")
public class Role {
    @ApiModelProperty(value = "角色id", example = "1")
    private String id;
    @ApiModelProperty(value = "角色名称", example = "技术负责人")
    private String name;
    //创建人
    private String createBy;
    //创建时间
    private DateTime createTime;
    //修改人
    private String updateBy;
    //修改时间
    private DateTime updateTime;
    //逻辑删除标识 0 未删除 1 已删除
    private Integer delFlag;
    //是否为注册默认包含角色 0 否 1 是
    private Integer defaultRole;
    //备注
    private String description;
    //数据权限 0全部 1自定义 2本部门及以下 3本部门
    private Integer dataType;


}
