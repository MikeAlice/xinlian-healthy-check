package com.zeroone.star.TemplateManagement.entity;

import com.baomidou.mybatisplus.annotation.FieldFill;
import com.baomidou.mybatisplus.annotation.TableField;
import com.baomidou.mybatisplus.annotation.TableName;
import java.io.Serializable;
import java.time.LocalDateTime;
import lombok.Getter;
import lombok.Setter;

/**
 * <p>
 * 模板
 * </p>
 *
 * @author Triple Gold
 * @since 2024-01-21
 */
@Getter
@Setter
@TableName("t_template")
public class TTemplate implements Serializable {

    private static final long serialVersionUID = 1L;

    /**
     * 主键id	
     */
    private String id;

    /**
     * 组合项目id
     */
    private String baseProjectId;

    /**
     * 项目名称
     */
    @TableField(exist = false)
    private String name;

    /**
     * 报告类型
     */
    private String reportType;

    /**
     * 类型
     */
    private String type;

    /**
     * 状态
     */
    private String status;

    /**
     * 模板内容
     */
    private String content;

    /**
     * 排序
     */
    private Float orderNum;

    /**
     * 是否删除(0-未删除，1-已删除)
     */
    private Integer delFlag;

    /**
     * 创建人
     */
    private String createId;

    /**
     * 创建时间
     */
    @TableField(fill = FieldFill.INSERT)
    private LocalDateTime createTime;

    /**
     * 修改人
     */
    private String updateId;

    /**
     * 修改时间
     */
    private LocalDateTime updateTime;

    /**
     * 删除人
     */
    private String deleteId;

    /**
     * 删除时间
     */
    private LocalDateTime deleteTime;

    /**
     * 模板内容文件名
     */
    private String contentName;


}
