package com.zeroone.star.project.dto.j3.dictdata;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

import javax.validation.constraints.NotBlank;

@ApiModel("新增字典数据DTO")
@Data
@AllArgsConstructor
@NoArgsConstructor
public class AddDictDataDTO {
    @NotBlank(message = "名称不能为空")
    @ApiModelProperty(value = "名称",example = "健康体检",required = true)
    private String title;
    @NotBlank(message = "数据值不能为空")
    @ApiModelProperty(value = "数据值",example = "健康体检",required = true)
    private String value;
    @NotBlank(message = "备注不能为空")
    @ApiModelProperty(value = "备注",example = "A")
    private String description;
    @NotBlank(message = "排序值不能为空")
    @ApiModelProperty(value = "排序值",example = "1.00")
    private  java.math.BigDecimal sort_order;
    @NotBlank(message = "状态不能为空")
    @ApiModelProperty(value = "是否启用",example = "0",required = true)
    private Boolean status ;
    @NotBlank(message = "字典编号不能为空")
    @ApiModelProperty(value = "对应字典编号",example = "1534030617061232640",required = true)
    private Long dictId;
}
