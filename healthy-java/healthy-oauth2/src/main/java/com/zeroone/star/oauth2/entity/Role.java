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
 * 角色表
 * </p>
 *
 * @author 阿伟
 */
@Getter
@Setter
@TableName(value = "t_role")
public class Role implements Serializable {

    private static final long serialVersionUID = 1L;

    /**
     * 唯一ID
     */
    @TableId(value = "id", type = IdType.AUTO)
    private Long id;

    /**
     * 角色名
     */
    private String name;

//    /**
//     * 关键词
//     */
//    @TableField(exist = false)
//    private String keyword;

    /**
     * 角色描述
     */
    private String description;


}
