package com.zeroone.star.sysmanager.entity;

import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import lombok.Data;

import java.io.Serializable;
import java.time.LocalDateTime;

@Data
@TableName("t_user_role")
public class TUserRole implements Serializable {

    private static final long serialVersionUID = 1L;

    /**
     * 唯一ID
     */
    private Long id;

    /**
     *  创建人
     */
    private String createBy;

    /**
     * 创建时间
     */
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
     * 角色编号
     */
    private Long roleId;

    /**
     * 用户编号
     */
    private Long userId;
}
