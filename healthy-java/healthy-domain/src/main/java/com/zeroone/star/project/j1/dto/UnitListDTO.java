package com.zeroone.star.project.j1.dto;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
 * <p>
 * 描述：单位列表数据传输对象
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author 阿伟学长
 * @version 1.0.0
 */
@Data
@ApiModel("单位列表数据")
public class UnitListDTO {
    @ApiModelProperty(value = "唯一编号", example = "gb12222")
    private String id;
    @ApiModelProperty(value = "单位名称", example = "gb12222")
    private String name;
    @ApiModelProperty(value = "信用代码", example = "gb12222")
    private String uscc;
    @ApiModelProperty(value = "体检类型", example = "1")
    private Integer type;
    @ApiModelProperty(value = "所属地区", example = "gb12222")
    private String regionName;
    @ApiModelProperty(value = "行业类别", example = "gb12222")
    private String industryName;
    @ApiModelProperty(value = "经济类型", example = "gb12222")
    private String economicTypeName;
    @ApiModelProperty(value = "企业规模", example = "gb12222")
    private String businessScaleName;
    @ApiModelProperty(value = "联系人", example = "gb12222")
    private String linkMan;
    @ApiModelProperty(value = "联系电话", example = "gb12222")
    private String linkPhone;
}
