package com.zeroone.star.project.j2.dto;


import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
 * <p>
 * 描述：角色传输对象
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author 今天也是新的一天啊
 * @version 1.0.0
 */
@Data
@ApiModel
public class RoleDTO {
    private static final long serialVersionUID = 1L;
    @ApiModelProperty(value = "唯一标识",example = "1")
    private String id;
    
    @ApiModelProperty(value = "角色名称，命名规则以'ROLE_'开头",example = "超级管理员")
    private String name;
    
    @ApiModelProperty(value = "备注",example = "超级管理员，拥有超级管理员权限")
    private String description;
    
    @ApiModelProperty(value = "创建时间",example = "2018-04-22 23:03:49")
    private String createTime;
    
    @ApiModelProperty(value = "更新时间",example = "2021-11-27 17:07:30")
    private String updateTime;
    
    @ApiModelProperty(value = "是否为注册用户默认角色， 0 否 1 是",example = "0")
    private boolean defaultRole;

}
