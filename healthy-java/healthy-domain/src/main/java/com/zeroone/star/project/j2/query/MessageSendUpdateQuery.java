package com.zeroone.star.project.j2.query;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

@Data
@ApiModel("消息修改查询对象")
public class MessageSendUpdateQuery {
    @ApiModelProperty(value = "查询Id",example = "1")
    private Integer id;

    @ApiModelProperty(value = "发送用户Id",example = "1")
    private String UserId;
    //状态
    @ApiModelProperty(value = "状态",example = "0")
    private Integer Status;
}
