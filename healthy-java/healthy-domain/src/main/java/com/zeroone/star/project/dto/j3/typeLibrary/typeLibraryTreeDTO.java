package com.zeroone.star.project.dto.j3.typeLibrary;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.io.Serializable;
@Data
@ApiModel("获取类型树的dto")
public class typeLibraryTreeDTO implements Serializable {
    private static final long serialVersionUID = 1L;

    @ApiModelProperty(value = "类型父节点id",example = "0")
    private String parentId;

    @ApiModelProperty(value = "类型名称",example = "内资企业")
    private String typeName;
}
