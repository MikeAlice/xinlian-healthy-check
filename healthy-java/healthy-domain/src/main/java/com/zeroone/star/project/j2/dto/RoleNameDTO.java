package com.zeroone.star.project.j2.dto;

import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.util.List;

/**
 * <p>
 * 描述：角色名称列表传输对象
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author 今天也是新的一天啊
 * @version 1.0.0
 */
@Data
public class RoleNameDTO {
    private static final long serialVersionUID = 1L;
    @ApiModelProperty(value = "角色名称列表",example = "['超级管理员','问诊科']")
    List<String> roleNames;
    
}
