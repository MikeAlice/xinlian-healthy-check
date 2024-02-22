package com.zeroone.star.project.j2.dto;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;


@Data
@ApiModel("未读消息传输对象")
public class MessageSendUnReadDTO {
    @ApiModelProperty(value = "Id",example = "1",required = true)
    private String id;

    @ApiModelProperty(value = "标题",example = "标题")
    private String title;

    @ApiModelProperty(value = "内容",example = "内容")
    private String content;



}
