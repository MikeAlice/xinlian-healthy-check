package com.zeroone.star.project.j4.vo;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.io.Serializable;
@Data
@ApiModel(value = "科室管理列表名字")
public class GetSecNameVO implements Serializable {
    private static final long serialVersionUID = 1L;

    @ApiModelProperty(value = "ID",example = "1454369800754171904",required = true)
    private String id;
    //编码
    @ApiModelProperty(value = "编码",example = "001",required = true)
    private String sectionCode;
    //科室名称
    @ApiModelProperty(value = "科室名称",example = "心电图",required = true)
    private String sectionName;
    //科室简拼
    @ApiModelProperty(value = "科室简拼",example = "XDT",required = true)
    private String sectionAlphbet;
}
