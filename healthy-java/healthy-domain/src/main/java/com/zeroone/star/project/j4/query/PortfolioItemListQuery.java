package com.zeroone.star.project.j4.query;

import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import org.springframework.validation.annotation.Validated;

import java.math.BigDecimal;

/**
 * @Description: 获取项目列表 (条件+分页)
 * @Author: Laputa
 * @CreateTime: 2024-01-20  11:56
 * @Version: 1.0
 */
@Validated
@Data
@ApiModel("获取项目列表 (条件+分页)")
public class PortfolioItemListQuery extends PageQuery {
    @ApiModelProperty(value = "项目名称", example = "项目")
    private String name;

    @ApiModelProperty(value = "简称", example = "项目")
    private String shortName;
}
