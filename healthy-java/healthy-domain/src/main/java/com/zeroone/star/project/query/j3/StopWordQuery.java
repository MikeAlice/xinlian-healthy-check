package com.zeroone.star.project.query.j3;

import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import lombok.Getter;
import lombok.Setter;
import lombok.ToString;

import javax.validation.constraints.Min;

/**
 * 禁用词查询
 *
 * @Author Qi
 * @Date 2024/1/16
 */
@Data
@ApiModel("禁用词单位查询")
public class StopWordQuery extends PageQuery{
    /**
     * 禁用词
     */
    @ApiModelProperty(value = "禁用词", example = "sb")
    private String title;
}
