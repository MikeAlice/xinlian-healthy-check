package com.zeroone.star.project.j4.dto;

import com.baomidou.mybatisplus.annotation.TableId;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.time.LocalDateTime;
import java.util.List;

/**
 * @Description: 职业危害因素树
 * @Author: Laputa
 * @CreateTime: 2024-01-30  04:06
 * @Version: 1.0
 */

@Data
@ApiModel("职业危害因素树DTO")
public class OccupationalHazardTreeDTO {
    @ApiModelProperty(value = "主键", example = "1")
    private String id;

    @ApiModelProperty(value = "子节点")
    private List<OccupationalHazardTreeDTO> child;

    @ApiModelProperty(value = "类型名称", example = "矽尘")
    private String typeName;

    @ApiModelProperty(value = "类型编码", example = "110001")
    private String typeCode;

    @ApiModelProperty(value = "父节点id", example = "1")
    private String parentId;

    @ApiModelProperty(value = "删除状态(0-未删除，1-已删除)", example = "0")
    private Integer delFlag;
}
