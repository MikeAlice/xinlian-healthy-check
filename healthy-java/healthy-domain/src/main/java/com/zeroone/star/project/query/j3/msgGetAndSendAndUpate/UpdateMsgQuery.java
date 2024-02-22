package com.zeroone.star.project.query.j3.msgGetAndSendAndUpate;
import com.baomidou.mybatisplus.annotation.FieldFill;
import com.baomidou.mybatisplus.annotation.TableField;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import org.springframework.format.annotation.DateTimeFormat;

import javax.validation.constraints.NotBlank;
import java.io.Serializable;
import java.time.LocalDateTime;

/**
 * @version 1.0
 * @Author 卢守征
 * @Date 2024/1/19 16:50
 * @注释
 */

@Data
@ApiModel("修改信息DTO")
public class UpdateMsgQuery implements Serializable {
    private static final long serialVersionUID = 1L;

    @NotBlank(message = "消息id不能为空")
    @ApiModelProperty(value = "消息id不能为空",required = true)
    private String id;

//    @NotBlank(message = "消息人不能为空")
//    @ApiModelProperty(value = "修改人")
//    private String updateByID;

//    @NotBlank(message = "修改时间不能为空")
//    @ApiModelProperty(value = "修改时间不能为空", example = "2023-10-01 14:36:12")
//    @TableField(fill = FieldFill.INSERT)
//    @DateTimeFormat(pattern = "yyyy-MM-dd HH:mm:ss")
//    private LocalDateTime updateTime;

    @ApiModelProperty(value = "消息类型",required = true)
    private String type;

    @ApiModelProperty(value = "标题",required = true)
    private String title;

    @ApiModelProperty(value = "内容",required = true)
    private String content;

    @ApiModelProperty(value = "是否发送给新人 0 否 1 是",required = true)
    private Boolean createSend;
}
