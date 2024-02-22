package com.zeroone.star.project.j4.query;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import javax.validation.constraints.NotNull;
@Data
@ApiModel("获取科室信息条件")
public class GetSectionOfficeQuery extends PageQuery{
    /**
     * 当科室编码为空时，调用查询全部科室的方法
     */
    @ApiModelProperty(value = "编码",example = "001",required = true)
    private String sectionCode;
    /**
     *  当科室名称为空时，调用查询全部科室的方法
     */
    @ApiModelProperty(value = "科室名称",example = "心电图",required = true)
    private String sectionName;
    /**
     *  当科室简拼为空时，调用查询全部科室的方法
     */
    @ApiModelProperty(value = "科室简拼",example = "XDT",required = true)
    private String sectionAlphbet;
    /**
     *  当检查类型为空时，调用查询全部科室的方法
     */
    @ApiModelProperty(value = "检查类型",example = "健康体检",required = true)
    private String checkType;
}
