package com.zeroone.star.menu.entity;

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
 * 资源（菜单/操作权限）
 * </p>
 *
 * @author camille
 * @since 2024-01-15
 */
@Getter
@Setter
@TableName("t_permission")
public class TPermission implements Serializable {

    private static final long serialVersionUID = 1L;

    /**
     * 主键
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
     * 更新人
     */
    private String updateBy;

    /**
     * 更新时间
     */
    private LocalDateTime updateTime;

    /**
     * 资源类型 （-1顶部菜单  0界面菜单 1操作按钮）
     */
    private Boolean type;

    /**
     * 上级资源
     */
    private Long parentId;

    /**
     * 中文名称
     */
    private String title;

    /**
     * 英文名称
     */
    private String name;

    /**
     * 路径（如果是菜单对应路由地址，如果是操作对应接口地址）
     */
    private String path;

    /**
     * 图标
     */
    private String icon;

    /**
     * 前端组件
     */
    private String component;

    /**
     * 第三方链接
     */
    private String url;

    /**
     * 排序
     */
    private BigDecimal sortOrder;

    /**
     * 是否启用（0 启动 1禁用）
     */
    private Boolean status;

    /**
     * 按钮类型
     */
    private String buttonType;

    /**
     * 始终显示
     */
    private Boolean showAlways;

    /**
     * 系统站内菜单
     */
    private Boolean isMenu;

    /**
     * 是否显示左侧菜单
     */
    private Boolean showLeft;

    /**
     * 等级
     */
    private Integer level;

    /**
     * 备注
     */
    private String description;

    /**
     * 删除标记 0正常 1删除
     */
    private Boolean delFlag;


}
