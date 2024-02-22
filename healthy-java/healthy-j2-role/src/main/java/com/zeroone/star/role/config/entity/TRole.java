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
 * 角色
 * </p>
 *
 * @author camille
 * @since 2024-01-15
 */
@Getter
@Setter
@TableName("t_role")
public class
TRole implements Serializable {

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
     * 修改人
     */
    private String updateBy;

    /**
     * 修改时间
     */
    private LocalDateTime updateTime;

    /**
     * 角色名称，命名规则以 “ROLE_” 开头，如ROLE_TEST
     */
    private String name;

    /**
     * 逻辑删除标识 0 未删除 1 已删除
     */
    private Boolean delFlag;

    /**
     * 是否为注册默认包含角色 0 否 1 是
     */
    private Boolean defaultRole;

    /**
     * 备注
     */
    private String description;

    /**
     * 数据权限 0全部 1自定义 2本部门及以下 3本部门
     */
    private Boolean dataType;


}
