package com.zeroone.star.project.dto.j3.typeLibrary;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

/**
* @Description: 新增类型的DTO对象
* @Author: usagi
* @Date: 2024/1/18
* @Time:1:00
*/

@ApiModel("新增类型DTO")
@Data
@AllArgsConstructor
@NoArgsConstructor
public class typeAddDTO {
    @ApiModelProperty(value = "创建者id",example = "1",required = true)
    private Long createId;
    @ApiModelProperty(value = "类型名称",example = "经济类型",required = true)
    private String typeName;
    @ApiModelProperty(value = "类型编码",example = "TYPE_003",required = true)
    private String typeCode;
    @ApiModelProperty(value = "上级类型",example = "行业类型",required = true)
    private String fatherType;
    @ApiModelProperty(value = "排序",example = "2",required = true)
    private Integer orderNum;
    @ApiModelProperty(value = "备注",example = "这里是备注",required = true)
    private String remark;
}
