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
@ApiModel(value = "术语查询参数")
public class TermQuery extends PageQuery {

    @TableField(value = "inspect_type")
    @ApiModelProperty(value = "体检类型", example = "健康体检")
    private String inspect_type;


    @ApiModelProperty(value = "术语类型", example = "职业检查结果")
    private String type;

    @TableField(value = "hazard_factors")
    @ApiModelProperty(value = "危害因素", example = "溴甲烷")
    private String hazard_factors;

    @TableField(value = "work_state_code")
    @ApiModelProperty(value = "在岗状态", example = "在职期间")
    private String work_state_text;

    @ApiModelProperty(value = "术语内容", example = "它能干扰细胞代谢，造成神经系统、肺、肾、肝及心血管系统的损害")
    private String content;

    @ApiModelProperty(value = "创建时间")
    private Date create_time;



}
