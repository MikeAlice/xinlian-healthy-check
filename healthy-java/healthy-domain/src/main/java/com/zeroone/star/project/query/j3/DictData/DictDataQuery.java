package com.zeroone.star.project.query.j3.DictData;

import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import javax.validation.constraints.NotBlank;
import java.math.BigDecimal;

/**
 * *作者：MSNzqs
 * *日期：2024/1/27 16:31
 * *文件描述：
 */

@Data
@ApiModel("字典数据查询对象")
public class DictDataQuery extends PageQuery {

    /**
     * 数据名称
     */
    @ApiModelProperty(value = "数据名称", example = "mysql")
    private String title;

    /**
     * 是否启用 0 启用 1 禁用
     */
    @ApiModelProperty(value = "状态", example = "0")
    private int status;
}
