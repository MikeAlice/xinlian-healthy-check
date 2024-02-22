package com.zeroone.star.oauth2.entity;

import com.baomidou.mybatisplus.annotation.IdType;
import com.baomidou.mybatisplus.annotation.TableField;
import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import lombok.Getter;
import lombok.Setter;

import java.io.Serializable;

/**
 * <p>
 * 菜单
 * </p>
 *
 * @author 阿伟
 */
@Getter
@Setter
@TableName(value = "t_permission")
public class Menu implements Serializable {

    private static final long serialVersionUID = 1L;

    /**
     * 菜单编号
     */
    @TableId(value = "id", type = IdType.AUTO)
    private Long id;

    /**
     * 菜单名
     */
    private String name;

    /**
     * 链接地址
     */
    private String url;

    /**
     * 路由地址
     */
    private String path;

    /**
     * 显示优先级别
     */
    @TableField(exist = false)
    private Integer priority;

    /**
     * 图标
     */
    private String icon;

    /**
     * 描述
     */
    private String description;

    /**
     * 父级菜单编号
     */
    private Long parentId;

    /**
     * 层次级别
     */
    private Integer level;

    /**
     * 是否启用 0 禁用 1 启用
     */
    private boolean status;


}
