package com.zeroone.star.project.j4.vo;

import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.io.Serializable;

/**
 * @author lj
 * 时间：2024.1.1
 * 功能：
 */
@Data
public class TermDetailVo implements Serializable {
    @ApiModelProperty(value = "科室名称",example = "肺功能")
    private String sectionName;

    @ApiModelProperty(value = "体检类型",example = "职业体检")
    private String inspectType;

    @ApiModelProperty(value = "术语类型",example = "诊断小结")
    private String type;

    @ApiModelProperty(value = "危害因素",example = "溴甲烷")
    private String hazardFactorsText;

    @ApiModelProperty(value = "在岗状态",example = "上岗前")
    private String workStateText;

    @ApiModelProperty(value = "状态",example = "启用")
    private String status;

    @ApiModelProperty(value = "术语内容",example = "它能干扰细胞代谢，造成神经系统、肺、肾、肝及心血管系统的损害")
    private String content;

    @ApiModelProperty(value = "排序",example = "0")
    private Float orderNum;
}
