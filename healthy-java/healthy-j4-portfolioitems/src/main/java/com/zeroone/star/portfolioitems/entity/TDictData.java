package com.zeroone.star.portfolioitems.entity;

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
 * 字典数据
 * </p>
 *
 * @author ;jiemo
 * @since 2024-01-29
 */
@Getter
@Setter
@TableName("t_dict_data")
public class TDictData implements Serializable {

    private static final long serialVersionUID = 1L;

    /**
     * 唯一标识
     */
    private String id;

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
     * 备注
     */
    private String description;

    /**
     * 对应字典编号
     */
    private Long dictId;

    /**
     * 排序号
     */
    private BigDecimal sortOrder;

    /**
     * 是否启用 0 启用 1 禁用
     */
    private Boolean status;

    /**
     * 数据名称
     */
    private String title;

    /**
     * 数据值
     */
    private String value;


}
