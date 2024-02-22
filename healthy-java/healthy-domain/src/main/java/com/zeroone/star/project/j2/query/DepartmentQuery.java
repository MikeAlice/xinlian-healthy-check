package com.zeroone.star.project.j2.query;

import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.math.BigDecimal;
import java.time.LocalDateTime;

/**
 * <p>
 * 描述：消息查询对象
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author camille
 * @version 1.0.0
 */

@Data
@ApiModel("部门查询对象")
public class DepartmentQuery extends PageQuery {
    //查询Id
    @ApiModelProperty(value = "查询Id",example = "1")
    private String id;
    //创建人
    @ApiModelProperty(value = "创建人",example = "张三")
    private String CreateBy;
    //创建时间
    @ApiModelProperty(value = "创建时间",example = "2024-01-15")
    private LocalDateTime CreateTime;
    //是否删除
    @ApiModelProperty(value = "是否删除",example = "0")
    private Integer DelFlag;
    //更新人
    @ApiModelProperty(value = "更新人",example = "张三")
    private String UpdateBy;
    //更新时间
    @ApiModelProperty(value = "更新时间",example = "2024-01-15")
    private LocalDateTime UpdateTime;
    //上级部门ID
    @ApiModelProperty(value = "上级部门ID",example = "1")
    private Long ParentID;
    //排序值
    @ApiModelProperty(value = "排序值",example = "1")
    private BigDecimal SortOrder;
    //状态
    @ApiModelProperty(value = "状态",example = "1")
    private Boolean Status;
    //部门名称
    @ApiModelProperty(value = "部门名称",example = "1")
    private String Title;
    //是否为父节点
    @ApiModelProperty(value = "是否为父节点",example = "0")
    private Boolean IsParent;
}
