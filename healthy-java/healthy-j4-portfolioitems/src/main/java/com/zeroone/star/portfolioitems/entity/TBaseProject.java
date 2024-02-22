package com.zeroone.star.portfolioitems.entity;

import com.baomidou.mybatisplus.annotation.FieldFill;
import com.baomidou.mybatisplus.annotation.TableField;
import com.baomidou.mybatisplus.annotation.TableName;
import java.io.Serializable;
import java.time.LocalDateTime;
import lombok.Getter;
import lombok.Setter;

/**
 * <p>
 * 基础项目
 * </p>
 *
 * @author ;jiemo
 * @since 2024-01-29
 */
@Getter
@Setter
@TableName("t_base_project")
public class TBaseProject implements Serializable {

    private static final long serialVersionUID = 1L;

    /**
     * 主键
     */
    private String id;

    /**
     * 项目代码
     */
    private String code;

    /**
     * 名称
     */
    private String name;

    /**
     * 简称
     */
    private String shortName;

    /**
     * 排序
     */
    private Float orderNum;

    /**
     * 科室id
     */
    private String officeId;

    /**
     * 科室名称
     */
    private String officeName;

    /**
     * 单位编码
     */
    private String unitCode;

    /**
     * 单位名称
     */
    private String unitName;

    /**
     * 默认值
     */
    private String defaultValue;

    /**
     * 结果类型
     */
    private String resultType;

    /**
     * 是否进入小结
     */
    private String inConclusion;

    /**
     * 是否进入报告
     */
    private String inReport;

    /**
     * LIS关联码
     */
    private String relationCode;

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
     * 所属部门
     */
    private String departmentId;


}
