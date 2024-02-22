package com.zeroone.star.role.config.entity;

import com.baomidou.mybatisplus.annotation.FieldFill;
import com.baomidou.mybatisplus.annotation.TableField;
import com.baomidou.mybatisplus.annotation.TableName;
import java.io.Serializable;
import java.time.LocalDateTime;
import lombok.Getter;
import lombok.Setter;

/**
 * <p>
 * 角色与部分关系映射
 * </p>
 *
 * @author camille
 * @since 2024-01-15
 */
@Getter
@Setter
@TableName("t_role_department")
public class TRoleDepartment implements Serializable {

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
     * 逻辑删除标识 0不删除 1已删除
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
     * 部门唯一标识
     */
    private Long departmentId;

    /**
     * 角色编号
     */
    private Long roleId;


}
