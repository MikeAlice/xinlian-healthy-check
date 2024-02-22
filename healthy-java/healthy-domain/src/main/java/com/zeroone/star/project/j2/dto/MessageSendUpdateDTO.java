package com.zeroone.star.project.j2.dto;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
 * <p>
 * 描述：消息详情传输对象
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author camille
 * @version 1.0.0
 */
@Data
@ApiModel("消息详情")
public class MessageSendUpdateDTO {


    @ApiModelProperty(value = "查询Id",example = "1", required = true)
    private String id;
    //用户Id
    @ApiModelProperty(value = "发送用户Id",example = "1")
    private String UserId;
    //消息Id
    @ApiModelProperty(value = "消息Id",example = "1")
    private String MessageId;
    //创建人
    @ApiModelProperty(value = "创建人",example = "张三")
    private String CreateBy;
    //创建时间
    @ApiModelProperty(value = "创建时间",example = "2024-01-15")
    private String CreateTime;
    //状态
    @ApiModelProperty(value = "状态",required = true ,example = "1")
    private Integer Status;
    //更新时间
    @ApiModelProperty(value = "查询Id",example = "1")
    private String UpdateTime;

}