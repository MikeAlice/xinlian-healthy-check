package com.zeroone.star.project.j4.dto;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.io.Serializable;
@Data
@ApiModel(value = "获取科室管理名称列表")
public class GetSecNameDTO extends PageQuery implements Serializable {
    private static final long serialVersionUID = 1L;
    @ApiModelProperty(value = "ID",example = "1454369800754171904",required = true)
    private String id;
    //编码
    @ApiModelProperty(value = "编码",example = "001")
    private String sectionCode;
    //科室名称
    @ApiModelProperty(value = "科室名称",example = "心电图")
    private String sectionName;
    //科室简拼
    @ApiModelProperty(value = "科室简拼",example = "XDT")
    private String sectionAlphbet;
}
