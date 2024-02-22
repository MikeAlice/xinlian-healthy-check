package com.zeroone.star.project.j4.dto;

import com.zeroone.star.project.dto.PageDTO;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
 * @author lj
 * 时间：2024.1.1
 * 功能：
 */
@Data
public class TermNameDto extends PageDTO {
    @ApiModelProperty(value = "体检类型", example = "健康体检")
    private String inspectType;


    @ApiModelProperty(value = "术语类型", example = "职业检查结果")
    private String type;


    @ApiModelProperty(value = "危害因素", example = "溴甲烷")
    private String hazardFactorsText;



    @ApiModelProperty(value = "术语内容", example = "它能干扰细胞代谢，造成神经系统、肺、肾、肝及心血管系统的损害")
    private String content;
}
