package com.zeroone.star.project.j4.vo;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
 * @author: jiemo
 * @description: 获取基础项目列表VO
 */

@Data
@ApiModel("获取基础项目列表展示")
public class BasePortfolioListVO{
    @ApiModelProperty(value = "id",example = "8be4be563eb711ec96d5b42e99af990f",required = false)
    private String id;
    @ApiModelProperty(value = "项目代码",example = "11500",required = false)
    private String code;
    @ApiModelProperty(value = "项目名称",example = "甲状腺",required = false)
    private String name;
    @ApiModelProperty(value = "简称",example = "jzx",required = false)
    private String shortName;
    @ApiModelProperty(value = "排序",example = "1",required = false)
    private Float orderNum;
    @ApiModelProperty(value = "科室id",example = "191",required = false)
    private String officeId;
    @ApiModelProperty(value = "科室名称",example = "外科",required = false)
    private String officeName;
    @ApiModelProperty(value = "单位编码",example = "1049",required = false)
    private String unitCode;
    @ApiModelProperty(value = "单位名称",example = "无",required = false)
    private String unitName;
//    @ApiModelProperty(value = "结果类型",example = "选择",required = false)
//    private String resultType;
//    @ApiModelProperty(value = "科室id",example = "191",required = false)
//    private String inConclusion;
//    @ApiModelProperty(value = "科室id",example = "191",required = false)
//    private String inReport;
}
