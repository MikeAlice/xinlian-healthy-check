package com.zeroone.star.project.j4.dto;

import com.baomidou.mybatisplus.annotation.FieldFill;
import com.baomidou.mybatisplus.annotation.TableField;
import com.baomidou.mybatisplus.annotation.TableName;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.time.LocalDateTime;

@TableName("t_template")
@Data
public class TemplateDto {
    @ApiModelProperty(value = "主键id", example = "12345")
    private String id;


    @ApiModelProperty(value = "报告类型", example = "通用")
    private String reportType;


    @ApiModelProperty(value = "状态", example = "1")
    private String status;

    @ApiModelProperty(value = "模板在fastfds的地址", example = "group1|M00/00/00/oYYBAGW6HkmAQWGyABqYHQnuNMw636.pdf")
    private String content;

    @ApiModelProperty(value = "排序", example = "1")
    private Float orderNum;

    @ApiModelProperty(value = "模板内容文件名",example = "复查报告.docx")
    private String contentName;

    /**
     * 创建时间
     */
    @TableField(fill = FieldFill.INSERT)
    private LocalDateTime createTime;

}
