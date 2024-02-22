package com.zeroone.star.project.dto.j3.message;


import com.fasterxml.jackson.annotation.JsonFormat;
import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

import java.util.Date;

/**
 * 发送消息/消息查看公共类
 *
 * @author ZhangJF
 * @date 2024/01/15 16:53
 **/
@ApiModel("接收消息详情对象")
@Data
@AllArgsConstructor
@NoArgsConstructor
public class MessageSendDTO extends PageQuery {
    /*pageNumber=1&pageSize=10&sort=createTime&order=desc&userId=&messageId=8&status=*/
    @JsonFormat(pattern = "yyyy-MM-dd HH:mm:ss",timezone = "GMT+8")
    @ApiModelProperty(value = "创建时间")
   private Date createTime;
    @ApiModelProperty(value = "用户id")
   private String userId;
    @ApiModelProperty(value = "消息Id")
   private String messageId;
    @ApiModelProperty(value = "状态(未读-0，已读-1，回收站-2)",example = "0")
    private Integer status;
}
