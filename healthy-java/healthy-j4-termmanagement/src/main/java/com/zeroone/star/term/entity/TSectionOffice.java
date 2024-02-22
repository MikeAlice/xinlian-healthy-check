package com.zeroone.star.term.entity;

import com.baomidou.mybatisplus.annotation.FieldFill;
import com.baomidou.mybatisplus.annotation.TableField;
import com.baomidou.mybatisplus.annotation.TableName;
import lombok.Getter;
import lombok.Setter;

import java.io.Serializable;
import java.time.LocalDateTime;

/**
 * <p>
 * 科室
 * </p>
 *
 * @author ;jiemo
 * @since 2024-01-29
 */
@Getter
@Setter
@TableName("t_section_office")
public class TSectionOffice implements Serializable {

    private static final long serialVersionUID = 1L;

    /**
     * 主键id	
     */
    private String id;

    /**
     * 编码
     */
    private String sectionCode;

    /**
     * 科室名称
     */
    private String sectionName;

    /**
     * 科室简拼
     */
    private String sectionAlphbet;

    /**
     * 排序
     */
    private Float orderNum;

    /**
     * 联系人
     */
    private String contact;

    /**
     * 联系人电话
     */
    private String contactMobile;

    /**
     * 检查类型
     */
    private String checkType;

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
