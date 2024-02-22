package com.zeroone.star.sysmanager.entity;

import lombok.Data;

import java.time.LocalDateTime;

/**
 * 用户数据导出实体类
 */
@Data
public class User {
    private String username;
    private String avatar;
    private Long departmentId;
    private String departmentTitle;
    private String mobile;
    private String email;
    private String sex;
    private Integer type;
    private Integer status;
    private Boolean delFlag;
    private LocalDateTime createTime;
    private LocalDateTime updateTime;
}
