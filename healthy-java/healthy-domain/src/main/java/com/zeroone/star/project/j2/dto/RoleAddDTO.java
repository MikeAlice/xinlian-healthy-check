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
 * @author shun
 * @version 1.0.0
 */

@Data
@ApiModel("角色传输对象")
public class RoleAddDTO {

    private static final long serialVersionUID = 1L;

    @ApiModelProperty(value = "唯一标识" ,example = "1")
    private String id;

    @ApiModelProperty(value = "角色名称，命名规则以 “ROLE_” 开头" ,example = "ROLE_TEST")
    private String name;

    @ApiModelProperty(value = "是否为注册默认包含角色 0 否 1 是" ,example = "0")
    private Boolean defaultRole;

    @ApiModelProperty(value = "备注" ,example = "备注备注备注")
    private String description;

    @ApiModelProperty(value = "数据权限 0全部 1自定义 2本部门及以下 3本部门" ,example = "1")
    private Boolean dataType;
}