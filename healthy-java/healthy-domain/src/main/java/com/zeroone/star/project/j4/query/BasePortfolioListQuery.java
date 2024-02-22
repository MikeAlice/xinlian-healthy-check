package com.zeroone.star.project.j4.query;

import com.baomidou.mybatisplus.annotation.TableField;
import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
 * @author: jiemo
 * @description:获取基础项目列表query
 */
@Data
@ApiModel("获取基础项目列表条件")
public class BasePortfolioListQuery extends PageQuery {

    @ApiModelProperty(value = "关键字（基础项目名称）",example = "甲状腺",required = false)
    private String name;
    @ApiModelProperty(value = "科室id",example = "191",required = false)
    private String officeId;
}
