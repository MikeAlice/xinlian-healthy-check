package com.zeroone.star.project.query.j3.msgGetAndSendAndUpate;

import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.io.Serializable;

/**
 * @version 1.0
 * @Author 卢守征
 * @Date 2024/1/19 16:11
 * @注释 消息查询对象
 */
@Data
@ApiModel("消息查询")
public class MsgListQuery  extends PageQuery implements Serializable {

    // 序列化ID
    private static final long serialVersionUID = 1L;

    @ApiModelProperty(value = "消息标题", example = "大话西游")
    private String msgTitle;

    @ApiModelProperty(value = "消息内容", example = "取得真经")
    private String msgContent;

    @ApiModelProperty(value = "消息类型", example = "文本")
    private String msgType;

    @ApiModelProperty(value = "创建时间", example = "2000-09-15 22:25:07.000000")
    private String createTime;
}
