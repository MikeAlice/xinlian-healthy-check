package com.zeroone.star.project.j4.dto;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import javax.validation.constraints.NotBlank;
import javax.validation.constraints.NotNull;
import java.util.Date;

@Data
@ApiModel(value = "列表")
public class TermDTO {
    @ApiModelProperty(value = "唯一编号",example = "1")
    private String id;

    @ApiModelProperty(value = "科室名称",example = "肺功能")
    @NotBlank(message = "科室名称不能为空")
    private String officeName;

    @ApiModelProperty(value = "体检类型",example = "职业体检")
    @NotBlank(message = "体检类型不能为空")
    private String inspectType;

    @ApiModelProperty(value = "术语类型",example = "诊断小结")
    @NotBlank(message = "术语类型不能为空")
    private String type;

    @ApiModelProperty(value = "危害因素",example = "溴甲烷")
    private String hazardFactors;

    @ApiModelProperty(value = "在岗状态",example = "在岗期间")
    private String workStateText;

    @ApiModelProperty(value = "状态",example = "0")
    @NotBlank(message = "状态不能为空")
    private String status;

    @ApiModelProperty(value = "术语内容",example = "它能干扰细胞代谢，造成神经系统、肺、肾、肝及心血管系统的损害")
    @NotBlank(message = "术语内容不能为空")
    private String content;

    @ApiModelProperty(value = "排序",example = "1")
    @NotNull(message = "排序不能为空")
    private Float orderNum;

    @ApiModelProperty(value = "创建时间",example = "2021-12-06 10:36:14")
    private Date createTime;


}