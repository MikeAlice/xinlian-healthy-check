package com.zeroone.star.project.query.j3.msgGetAndSendAndUpate;

import com.baomidou.mybatisplus.annotation.FieldFill;
import com.baomidou.mybatisplus.annotation.TableField;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import org.springframework.format.annotation.DateTimeFormat;

import javax.validation.constraints.Max;
import javax.validation.constraints.Min;
import javax.validation.constraints.NotBlank;
import java.io.Serializable;
import java.time.LocalDateTime;

/**
 * @version 1.0
 * @Author 卢守征
 * @Date 2024/1/19 16:49
 * @注释
 */

@Data
@ApiModel("发送信息Query")
public class SendMsgQuery implements Serializable {
    private static final long serialVersionUID = 1L;

    @NotBlank(message = "消息id不能为空")
    @ApiModelProperty(value = "消息id不能为空", example = "1",required = true)
    private String id;

//    @NotBlank(message = "创建人不能为空")
//    @ApiModelProperty(value = "创建人", example = "梅西")
//    private String createBy;

//    @NotBlank(message = "创建时间不能为空")
//    @ApiModelProperty(value = "创建时间", example = "2024-01-17 14:36:12")
//    @TableField(fill = FieldFill.INSERT)
//    @DateTimeFormat(pattern = "yyyy-MM-dd HH:mm:ss")
//    private LocalDateTime createTime;

    @ApiModelProperty(value = "消息类型",required = true)
    private String type;

    @ApiModelProperty(value = "标题",required = true)
    private String title;

    @ApiModelProperty(value = "内容",required = true)
    private String content;

    @ApiModelProperty(value = "是否发送给新人 0 否 1 是",required = true)
    private Boolean createSend;

    @Min(value = 0, message = "全体用户")
    @Max(value = 1, message = "指定用户")
    @TableField(exist = false)
    @ApiModelProperty(value = "发送范围",required = true)
    private Integer range;

    @TableField(exist = false)
    @ApiModelProperty(value = "发送指定用户id",required = true)
    private String[] userIds;
}