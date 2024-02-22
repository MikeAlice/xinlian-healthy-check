package com.zeroone.star.project.vo.department;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.math.BigDecimal;
import java.time.LocalDateTime;

@ApiModel("部门列表对象")
@Data
public class DepartmentMenuVO{
    @ApiModelProperty(value = "序号", example = "1")
    private String id;
    @ApiModelProperty(value = "部门名称",example = "1")
    private String Title;
    @ApiModelProperty(value = "排序值",example = "1")
    private BigDecimal SortOrder;
    @ApiModelProperty(value = "创建时间",example = "2024-01-15")
    private LocalDateTime CreateTime;
    @ApiModelProperty(value = "是否为父节点",example = "0")
    private Boolean IsParent;
}
