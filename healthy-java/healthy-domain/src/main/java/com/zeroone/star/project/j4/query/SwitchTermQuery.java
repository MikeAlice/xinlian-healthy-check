package com.zeroone.star.project.j4.query;

import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import org.springframework.validation.annotation.Validated;

/**
 * @Description: 启用/禁用术语
 * @Author: Laputa
 * @CreateTime: 2024-01-30  01:09
 * @Version: 1.0
 */

@Validated
@Data
@ApiModel("启用/禁用术语")
public class SwitchTermQuery {
    @ApiModelProperty(value = "主键", example = "1", required = true)
    private String id;

    @ApiModelProperty(value = "状态(0-启用，1-停用)", example = "0", required = true)
    private String status;
}

