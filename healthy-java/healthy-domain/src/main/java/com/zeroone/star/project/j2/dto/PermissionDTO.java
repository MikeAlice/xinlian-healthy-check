package com.zeroone.star.project.j2.dto;

/**
 * @author 滑溜溜
 * @version 1.0.0
 * @desc 菜单详情传输对象
 * @since 2024-01-17
 */

import com.baomidou.mybatisplus.annotation.FieldFill;
import com.baomidou.mybatisplus.annotation.TableField;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.math.BigDecimal;
import java.time.LocalDateTime;

@Data
@ApiModel
public class PermissionDTO {

    @ApiModelProperty(value = "查询Id",example = "123456789")
    private String id;

    @ApiModelProperty(value = "菜单类型",example = "0")
    private Boolean type;

    @ApiModelProperty(value = "上级id",example = "123456789")
    private Long parentId;

    @ApiModelProperty(value = "标题名",example = "从检报告")
    private String title;

    @ApiModelProperty(value = "路由英文名",example = "healthCertificate")
    private String name;

    @ApiModelProperty(value = "路径",example = "/healthCertificate")
    private String path;

    @ApiModelProperty(value = "图标",example = "md-apps")
    private String icon;

    @ApiModelProperty(value = "前端组件",example = "Main")
    private String component;

    @ApiModelProperty(value = "第三方链接",example = "http://6.66.666.6666:6666/")
    private String url;

    @ApiModelProperty(value = "排序的权值",example = "10.2")
    private BigDecimal sortOrder;

    @ApiModelProperty(value = "是否启用",example = "0")
    private Boolean status;

    @ApiModelProperty(value = "按钮类型",example = "disable")
    private String buttonType;

    @ApiModelProperty(value = "始终显示",example = "0")
    private Boolean showAlways;

    /**
     * 系统站内菜单
     */
    @ApiModelProperty(value = "系统站内菜单",example = "1")
    private Boolean isMenu;

    @ApiModelProperty(value = "是否显示左侧菜单",example = "1")
    private Boolean showLeft;

    @ApiModelProperty(value = "等级",example = "1")
    private Integer level;

}
