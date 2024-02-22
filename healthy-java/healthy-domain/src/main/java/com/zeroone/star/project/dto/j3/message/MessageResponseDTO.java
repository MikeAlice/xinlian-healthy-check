package com.zeroone.star.project.dto.j3.message;

import com.fasterxml.jackson.annotation.JsonFormat;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import java.util.Date;

/**
 * 响应消息详情
 *
 * @author ZhangJF
 * @date 2024/01/20 15:49
 **/
@ApiModel("响应消息详情对象")
@Data
@AllArgsConstructor
@NoArgsConstructor
public class MessageResponseDTO {
    @GeneratedValue(strategy = GenerationType.AUTO)
    @ApiModelProperty(value = "自增id",example = "1",required = true)
    private Integer id;
    @ApiModelProperty(value = "发送用户",required = true)
    private String createBy;
    @ApiModelProperty(value = "状态",example = "0",required = true)
    private Integer status;
    @JsonFormat(pattern = "yyyy-MM-dd HH:mm:ss",timezone = "GMT+8")
    @ApiModelProperty(value = "创建时间",required = true)
    private Date createTime;
    @JsonFormat(pattern = "yyyy-MM-dd HH:mm:ss",timezone = "GMT+8")
    @ApiModelProperty(value = "更新时间",required = true)
    private Date updateTime;
}
