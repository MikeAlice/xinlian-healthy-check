package com.zeroone.star.project.j4.query;

import com.baomidou.mybatisplus.annotation.TableField;
import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.util.Date;

/**
 * @author 刘静
 * 时间：2024.1.1
 * 功能：
 */
@Data
@ApiModel(value = "术语名称查询参数")
public class TermNameQuery extends PageQuery {

    @TableField(value = "office_id")
    @ApiModelProperty(value = "科室名称",example = "肺功能")
    private String officeName;

    @TableField(value = "inspect_type")
    @ApiModelProperty(value = "体检类型", example = "健康体检")
    private String inspectType;


    @ApiModelProperty(value = "术语类型", example = "职业检查结果")
    private String type;

    @TableField(value = "hazard_factors")
    @ApiModelProperty(value = "危害因素", example = "溴甲烷")
    private String hazardFactors;

    @TableField(value = "work_state_code")
    @ApiModelProperty(value = "在岗状态", example = "在职期间")
    private String workStateText;

    @ApiModelProperty(value = "术语内容", example = "它能干扰细胞代谢，造成神经系统、肺、肾、肝及心血管系统的损害")
    private String content;

    @ApiModelProperty(value = "创建时间")
    private Date createTime;
}
