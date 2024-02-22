package com.zeroone.star.project.dto.j3.typeLibrary;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

/**
 * Created with IntelliJ IDEA.
 *
 * @Author: usagi
 * @Date: 2024/01/18/1:23
 * @Description:修改类型DTO
 */
@ApiModel("修改类型DTO")
@Data
@AllArgsConstructor
@NoArgsConstructor
public class typeUpdateDTO {
    @ApiModelProperty(value = "更新者id",example = "1")
    private Long updateId;
    @ApiModelProperty(value = "修改前的类型名称",example = "经济类型")
    private String typeNamePre;
    @ApiModelProperty(value = "修改前的类型编码",example = "TYPE_003")
    private String typeCodePre;
    @ApiModelProperty(value = "类型名称",example = "经济类型")
    private String typeName;
    @ApiModelProperty(value = "类型编码",example = "TYPE_003")
    private String typeCode;
    @ApiModelProperty(value = "上级类型",example = "行业类型")
    private String parentId;
    @ApiModelProperty(value = "排序",example = "2")
    private Integer orderNum;
    @ApiModelProperty(value = "备注",example = "这里是备注")
    private String remark;
}
