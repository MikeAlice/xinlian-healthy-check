package com.zeroone.star.department.entity;

import com.baomidou.mybatisplus.annotation.FieldFill;
import com.baomidou.mybatisplus.annotation.TableField;
import com.baomidou.mybatisplus.annotation.TableName;
import java.io.Serializable;
import java.time.LocalDateTime;
import lombok.Getter;
import lombok.Setter;

/**
 * <p>
 * 部门负责人
 * </p>
 *
 * @author camille
 * @since 2024-01-15
 */
@Getter
@Setter
@TableName("t_department_header")
public class TDepartmentHeader implements Serializable {

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
     * 逻辑删除标识 0 未删除 1 已删除
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
     * 对应部门编号
     */
    private Long departmentId;

    /**
     * 负责人类型 0 主负责人 1 副负责人
     */
    private Boolean type;

    /**
     * 对应负责人用户编号
     */
    private Long userId;


}
