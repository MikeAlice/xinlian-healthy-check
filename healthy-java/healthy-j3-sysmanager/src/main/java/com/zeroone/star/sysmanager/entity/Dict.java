package com.zeroone.star.sysmanager.entity;

import com.baomidou.mybatisplus.annotation.FieldFill;
import com.baomidou.mybatisplus.annotation.TableField;
import com.baomidou.mybatisplus.annotation.TableName;
import java.io.Serializable;
import java.math.BigDecimal;
import java.time.LocalDateTime;
import lombok.Getter;
import lombok.Setter;

/**
 * <p>
 * 字典
 * </p>
 *
 * @author 坚强少年
 * @since 2024-01-16
 */
@Getter
@Setter
@TableName("t_dict")
public class Dict implements Serializable {

    private static final long serialVersionUID = 1L;

    /**
     * 唯一标识
     */
    private Long id;

    /**
     * 创建人
     */
    private String createBy;

    /**
     * 创建时间
     */
    @TableField(fill = FieldFill.INSERT)
    private LocalDateTime createTime;

    /**
     * 删除标记 0不删除 1已删除
     */
    private Boolean delFlag;

    /**
     * 修改人
     */
    private String updateBy;

    /**
     * 修改时间
     */
    private LocalDateTime updateTime;

    /**
     * 字典备注
     */
    private String description;

    /**
     * 字典名称
     */
    private String title;

    /**
     * 类型名称，用英文单词，并且唯一，它会用于查询
     */
    private String type;

    /**
     * 显示序号
     */
    private BigDecimal sortOrder;


}
