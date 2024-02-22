package com.zeroone.star.project.j2.query;

import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
 * <p>
 * 描述：消息查询对象
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author camille
 * @version 1.0.0
 */

@Data
@ApiModel("消息详情查询对象")
public class MessageSendQuery  {
    //查询Id
    @ApiModelProperty(value = "查询Id",example = "1")
    private Integer id;


}
