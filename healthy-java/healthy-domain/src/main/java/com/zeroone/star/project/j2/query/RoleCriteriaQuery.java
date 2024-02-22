package com.zeroone.star.project.j2.query;

import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import javax.validation.constraints.NotBlank;

/**
 * <p>
 * 描述：角色分页和条件查询对象
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author camille
 * @version 1.0.0
 */

@Data
@ApiModel("角色条件查询对象")
public class RoleCriteriaQuery  extends PageQuery {
    @NotBlank(message = "关键字不能为空")
    @ApiModelProperty(value = "条件查询关键字,对应角色名称",example = "管理")
    private String name;

}