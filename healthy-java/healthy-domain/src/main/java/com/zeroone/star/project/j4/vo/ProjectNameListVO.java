package com.zeroone.star.project.j4.vo;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
 * @author: jiemo
 * @description: 获取项目名称列表VO
 */

@Data
@ApiModel("获取项目名称列表VO")
public class ProjectNameListVO {
    @ApiModelProperty(value = "id",example = "1508609996697505792",required = false)
    private String id;
    @ApiModelProperty(value = "备注",example = "血液",required = false)
    private String description;
    @ApiModelProperty(value = "数据名称",example = "血液",required = false)
    private String title;
    @ApiModelProperty(value = "数据值",example = "8",required = false)
    private String value;
}
