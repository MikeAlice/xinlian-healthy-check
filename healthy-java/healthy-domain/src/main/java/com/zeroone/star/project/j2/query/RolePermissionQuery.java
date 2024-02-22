package com.zeroone.star.project.j2.query;

import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import lombok.EqualsAndHashCode;

/**
 * <p>
 * 描述：角色权限查询对象
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author shun
 * @version 1.0.0
 */
@EqualsAndHashCode(callSuper = true)
@Data
@ApiModel("角色权限查询对象")
public class RolePermissionQuery extends PageQuery {

    @ApiModelProperty(value = "资源编号" ,example = "1")
    private Long permissionId;

    @ApiModelProperty(value = "角色ID" ,example = "12")
    private Long roleId;
}
