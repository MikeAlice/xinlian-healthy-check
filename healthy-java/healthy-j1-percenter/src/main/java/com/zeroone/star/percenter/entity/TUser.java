package com.zeroone.star.percenter.entity;

import com.baomidou.mybatisplus.annotation.FieldFill;
import com.baomidou.mybatisplus.annotation.TableField;
import com.baomidou.mybatisplus.annotation.TableName;
import java.io.Serializable;
import java.time.LocalDateTime;
import lombok.Getter;
import lombok.Setter;

/**
 * <p>
 * 用户
 * </p>
 *
 * @author feng
 * @since 2024-01-25
 */
@Getter
@Setter
@TableName("t_user")
public class TUser implements Serializable {

    private static final long serialVersionUID = 1L;

    /**
     * 唯一ID
     */
    private Long id;

    /**
     * 用户名用于登录
     */
    private String username;

    /**
     * 密码
     */
    private String password;

    /**
     * 密码强度
     */
    private String passStrength;

    /**
     * 账号类型 0 普通用户 1 管理员
     */
    private Integer type;

    /**
     * 账号状态 0 启用 1 禁用
     */
    private Integer status;

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
     * 昵称
     */
    private String nickname;

    /**
     * 头像图
     */
    private String avatar;

    /**
     * 性别
     */
    private String sex;

    /**
     * 个人简介
     */
    private String description;

    /**
     * 邮箱地址
     */
    private String email;

    /**
     * 移动电话
     */
    private String mobile;

    /**
     * 所在省市
     */
    private String address;

    /**
     * 街道地址
     */
    private String street;

    /**
     * 生日
     */
    private LocalDateTime birth;

    /**
     * 医师签名图
     */
    private String autograph;

    /**
     * 所属部门编号
     */
    private Long departmentId;

    /**
     * 所属部门名称
     */
    private String departmentTitle;

    /**
     * 逻辑删除标记 0 未删除 1 已删除
     */
    private Boolean delFlag;


}
