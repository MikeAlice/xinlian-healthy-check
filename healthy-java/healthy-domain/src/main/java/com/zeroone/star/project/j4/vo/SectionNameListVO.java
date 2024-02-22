package com.zeroone.star.project.j4.vo;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
 * @author: jiemo
 * @description: 获取科室名称VO
 */
@Data
@ApiModel("获取科室名称VO")
public class SectionNameListVO {
    @ApiModelProperty(value = "id",example = "1454369800754171904",required = false)
    private String id;
    @ApiModelProperty(value = "编码",example = "013",required = false)
    private String sectionCode;
    @ApiModelProperty(value = "科室名称",example = "问诊科",required = false)
    private String sectionName;
    @ApiModelProperty(value = "科室简拼",example = "wzk",required = false)
    private String sectionAlphbet;
    @ApiModelProperty(value = "检查类型",example = "职业体检,健康体检,从业体检",required = false)
    private String checkType;
    @ApiModelProperty(value = "所属部门",example = "186",required = false)
    private String departmentId;

}
