package com.zeroone.star.project.j4.dto;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.math.BigDecimal;

/**
 * @Description: 获取项目列表 (条件+分页）
 * @Author: Laputa
 * @CreateTime: 2024-01-20  12:10
 * @Version: 1.0
 */
@Data
@ApiModel("获取项目列表 (条件+分页")
public class PortfolioItemListDTO {
    @ApiModelProperty(value = "项目名称", example = "项目")
    private String name;

    @ApiModelProperty(value = "简称", example = "项目")
    private String shortName;

    @ApiModelProperty(value = "排序", example = "1")
    private Float orderNum;

    @ApiModelProperty(value = "销售价 (元)", example = "100")
    private BigDecimal salePrice;

    @ApiModelProperty(value = "成本价 (元)", example = "9")
    private BigDecimal costPrice;

    @ApiModelProperty(value = "科室名称", example = "一般检查")
    private String officeName;

    @ApiModelProperty(value = "检查地址", example = "01星球1号血库")
    private String address;
}
