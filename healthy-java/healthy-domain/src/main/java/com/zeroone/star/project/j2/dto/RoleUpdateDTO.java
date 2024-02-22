package com.zeroone.star.project.j2.dto;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
 * <p>
 * 描述：消息详情传输对象
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author yanghailong
 * @version 1.0.0
 */
@Data
@ApiModel
public class RoleUpdateDTO {

    //角色Id
    @ApiModelProperty(value = "查询Id",example = "1")
    private String id;

    //角色名称
    @ApiModelProperty(value = "角色名称",example = "张三")
    private String name;

    //备注
    @ApiModelProperty(value = "备注",example = "说明")
    private String description;

}
