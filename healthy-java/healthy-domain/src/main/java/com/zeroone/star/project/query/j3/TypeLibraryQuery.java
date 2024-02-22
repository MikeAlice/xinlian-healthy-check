package com.zeroone.star.project.query.j3;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.io.Serializable;

@Data
@ApiModel("分页查询的请求体")
public class TypeLibraryQuery implements Serializable {
    private static final long serialVersionUID = 1L;

    @ApiModelProperty(value = "类型名称",example = "内资企业")
    private String typeName;

    @ApiModelProperty(value = "类型编码",example = "100")
    private String typeCode;

    @ApiModelProperty(value = "起始日期")
    private String startDate;

    @ApiModelProperty(value = "结束日期")
    private String endDate;
}
