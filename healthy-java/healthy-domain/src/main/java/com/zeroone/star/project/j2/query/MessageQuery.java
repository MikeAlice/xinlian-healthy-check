package com.zeroone.star.project.j2.query;

import com.baomidou.mybatisplus.annotation.FieldFill;
import com.baomidou.mybatisplus.annotation.TableField;
import com.fasterxml.jackson.annotation.JsonFormat;
import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import org.springframework.format.annotation.DateTimeFormat;

import java.time.LocalDateTime;


@Data
@ApiModel("消息列表查询对象")
public class MessageQuery extends PageQuery {
    @ApiModelProperty(value = "查询Id",example = "1",required = true)
    private String id;

//    /**
//     * 创建人
//     */
//    @ApiModelProperty(value = "创建人",example = "zhangsan")
//    private String createBy;
//
    /**
     * 创建时间
     */
    @ApiModelProperty(value = "创建时间",example = "2018-04-22 23:03:49")
    @DateTimeFormat(pattern="yyyy-MM-dd HH:mm:ss")
    @JsonFormat(
            pattern = "yyyy-MM-dd HH:mm:ss",
            timezone = "GMT+8"

    )
    @TableField(fill = FieldFill.INSERT)

    private LocalDateTime createTime;

//    /**
//     * 修改人
//     */
//    @ApiModelProperty(value = "修改人",example = "lisi")
//    private String updateBy;
//
//    /**
//     * 修改时间
//     */
//    @DateTimeFormat(pattern="yyyy-MM-dd HH:mm:ss")
//    @JsonFormat(
//            pattern = "yyyy-MM-dd HH:mm:ss",
//            timezone = "GMT+8"
//
//    )
//
//    @ApiModelProperty(value = "修改时间",example = "2018-04-22 23:03:49")
//    private LocalDateTime updateTime;
//
//    /**
//     * 删除标记 0 不删除 1 已删除
//     */
//    @ApiModelProperty(value = "删除标记",example = "0")
//    private Integer delFlag;

    /**
     * 标题
     */
    @ApiModelProperty(value = "标题",example = "标题")
    private String title;

    /**
     * 内容
     */
    @ApiModelProperty(value = "内容",example = "内容")
    private String content;

//    /**
//     * 是否发送给新人 0 否 1 是
//     */
//    @ApiModelProperty(value = "是否发送给新人",example = "0")
//    private Boolean createSend;
//
    /**
     * 消息类型
     */
    @ApiModelProperty(value = "消息类型",example = "通知")
    private String type;
}
