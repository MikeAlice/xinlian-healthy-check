package com.zeroone.star.project.vo.department;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.math.BigDecimal;
import java.time.LocalDateTime;

@ApiModel("部门详情对象")
@Data
public class DepartmentVO {
    //创建人
    @ApiModelProperty(value = "创建人",example = "张三")
    private String CreateBy;
    //创建时间
    @ApiModelProperty(value = "创建时间",example = "2024-01-15")
    private LocalDateTime CreateTime;
    //更新人
    @ApiModelProperty(value = "更新人",example = "张三")
    private String UpdateBy;
    //更新时间
    @ApiModelProperty(value = "更新时间",example = "2024-01-15")
    private LocalDateTime UpdateTime;
    //上级部门ID
    @ApiModelProperty(value = "上级部门ID",example = "1")
    private String ParentID;
    //排序值
    @ApiModelProperty(value = "排序值",example = "1")
    private BigDecimal SortOrder;
    //状态
    @ApiModelProperty(value = "状态",example = "1")
    private Integer Status;
    //部门名称
    @ApiModelProperty(value = "部门名称",example = "1")
    private String Title;
}
