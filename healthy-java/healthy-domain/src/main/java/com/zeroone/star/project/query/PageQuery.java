package com.zeroone.star.project.query;

import io.swagger.annotations.ApiModelProperty;
import lombok.Getter;
import lombok.Setter;
import lombok.ToString;

import javax.validation.constraints.Min;
import javax.validation.constraints.NotBlank;

/**
 * <p>
 * 描述：分页查询父类对象
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author 阿伟学长
 * @version 1.0.0
 */
@Getter
@Setter
@ToString
public class PageQuery {
    @NotBlank(message = "页码不能为空")
    @Min(value = 1, message = "页码最小值为1")
    @ApiModelProperty(value = "查询页码", example = "1",required = true)
    private long pageIndex;
    @NotBlank(message = "条数不能为空")
    @Min(value = 1, message = "条数最小值为1")
    @ApiModelProperty(value = "查询条数", example = "10",required = true)
    private long pageSize;
}
