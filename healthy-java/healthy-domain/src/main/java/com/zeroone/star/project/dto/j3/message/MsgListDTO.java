package com.zeroone.star.project.dto.j3.message;

import com.zeroone.star.project.dto.PageDTO;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.io.Serializable;

/**
 * @version 1.0
 * @Author 卢守征
 * @Date 2024/1/19 16:40
 * @注释
 */
@Data
@ApiModel("消息列表数据")
public class MsgListDTO extends PageDTO implements Serializable {
    private static final long serialVersionUID = 1L;

    @ApiModelProperty(value = "唯一标识", example = "1")
    private String id;

    @ApiModelProperty(value = "消息标题", example = "msn重聚")
    private String title;

    @ApiModelProperty(value = "消息内容", example = "xxxx")
    private String content;

    @ApiModelProperty(value = "消息类型", example = "文本消息")
    private String msgType;

    @ApiModelProperty(value = "消息发送人", example = "messi")
    private String sendUser;

    @ApiModelProperty(value = "消息发送时间", example = "2023-1-18")
    private String sendTime;
}
