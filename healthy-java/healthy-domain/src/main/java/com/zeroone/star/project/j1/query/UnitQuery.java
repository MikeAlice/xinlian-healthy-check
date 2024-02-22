package com.zeroone.star.project.j1.query;

import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
 * <p>
 * 描述：体检单位查询对象
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author 阿伟学长
 * @version 1.0.0
 */
@Data
@ApiModel("单位查询对象")
public class UnitQuery extends PageQuery {
    /**
     * 查询类型
     */
    @ApiModelProperty(value = "查询类型", example = "1")
    private Integer type;
    /**
     * 单位名称
     */
    @ApiModelProperty(value = "单位名称", example = "牟丹单位")
    private String name;
    /**
     * 信用代码
     */
    @ApiModelProperty(value = "信用代码", example = "gb12222")
    private String uscc;
    /**
     * 联系人
     */
    @ApiModelProperty(value = "联系人", example = "89999")
    private String linkMan;
    /**
     * 联系电话
     */
    @ApiModelProperty(value = "联系电话", example = "138xxxxxxx")
    private String linkPhone;
}
