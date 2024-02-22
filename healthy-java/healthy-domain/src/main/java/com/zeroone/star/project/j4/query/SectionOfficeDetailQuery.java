package com.zeroone.star.project.j4.query;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
 * @author: jiemo
 * @date: 2024/2/4 11:03
 * @description:
 */
@ApiModel("获取科室详情条件")
@Data
public class SectionOfficeDetailQuery {
    @ApiModelProperty(value = "ID",example = "1454369800754171904",required = true)
    private String id;
    @ApiModelProperty(value = "编码",example = "001",required = true)
    private String sectionCode;
}
