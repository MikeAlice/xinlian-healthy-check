package com.zeroone.star.project.j2.query;


import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

@Data
@ApiModel("消息未读查询对象")
public class MessageSendUnReadQuery {

    //状态
    @ApiModelProperty(value = "状态",example = "0",required = true)
    private Integer Status;

    @ApiModelProperty(value = "查询Id",example = "1",required = true)
    private String Id;

    @ApiModelProperty(value = "消息编号",example = "1")
    private String messageId;
}
