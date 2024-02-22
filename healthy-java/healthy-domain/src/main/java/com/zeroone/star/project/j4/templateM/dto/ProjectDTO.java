package com.zeroone.star.project.j4.templateM.dto;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.util.List;

/**
 * <p>
 * 描述：包装t_template和t_portfolio_project的字段
 * </p>
 *
 * @author Triple Gold
 * @version 1.0.0
 */
@Data
@ApiModel("组合项目列表数据传输")
public class ProjectDTO {
    /**
     * 报告类型列表
     */
    @ApiModelProperty(value = "报告类型列表")
    private List<String> reportTypeList;
    /**
     * 模板类型列表
     */
    @ApiModelProperty(value = "模板类型列表")
    private List<String> typeList;
    /**
     * 项目名称列表
     */
    @ApiModelProperty(value = "项目名称列表")
    private List<String> nameList;
    /**
     * 模板状态列表
     */
    @ApiModelProperty(value = "模板状态列表")
    private List<String> statusList;
}
