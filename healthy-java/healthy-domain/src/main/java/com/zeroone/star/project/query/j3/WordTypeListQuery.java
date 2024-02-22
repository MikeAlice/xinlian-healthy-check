package com.zeroone.star.project.query.j3;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
 * @author: chenxiaxin
 * @date: 2024/1/18
 **/
@Data
@ApiModel("获取工作名称列表请求体")
public class WordTypeListQuery extends PageQuery {

    @ApiModelProperty(value = "不需要填")
    private String name;

    @ApiModelProperty(value = "是否启用 0 启用 -1 禁用")
    private int status;

    @ApiModelProperty(value = "根据xx分类",example = "sortOrder")
    private String sort;

    @ApiModelProperty(value = "排序规则",example = "asc")
    private String order;

    @ApiModelProperty(value = "字典id",example = "1456812385326206976")
    private String dictId;

    @ApiModelProperty(value = "数据名称")
    private String title;

}
