package com.zeroone.star.project.j2.dto;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;


/**
 * <p>
 * 描述：角色权限传输对象
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author shun
 * @version 1.0.0
 */
@Data
@ApiModel("角色权限传输对象")
public class RolePermissionDTO {

    private static final long serialVersionUID = 1L;

    @ApiModelProperty(value = "唯一标识" ,example = "1")
    private String id;

    @ApiModelProperty(value = "资源编号" ,example = "1")
    private Long permissionId;

    @ApiModelProperty(value = "角色ID" ,example = "12")
    private Long roleId;

}
