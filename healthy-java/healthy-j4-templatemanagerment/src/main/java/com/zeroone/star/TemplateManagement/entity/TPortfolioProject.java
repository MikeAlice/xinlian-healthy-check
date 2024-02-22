package com.zeroone.star.TemplateManagement.entity;

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
 * 组合项目
 * </p>
 *
 * @author Triple Gold
 * @since 2024-01-21
 */
@Getter
@Setter
@TableName("t_portfolio_project")
public class TPortfolioProject implements Serializable {

    private static final long serialVersionUID = 1L;

    /**
     * 主键
     */
    private String id;

    /**
     * 名称
     */
    private String name;

    /**
     * 简称
     */
    private String shortName;

    /**
     * 排序
     */
    private Float orderNum;

    /**
     * 父节点ID
     */
    private String parentId;

    /**
     * 科室名称
     */
    private String officeName;

    /**
     * 科室id
     */
    private String officeId;

    /**
     * 原价（元）
     */
    private BigDecimal marketPrice;

    /**
     * 销售价（元）
     */
    private BigDecimal salePrice;

    /**
     * 成本价（元）
     */
    private BigDecimal costPrice;

    /**
     * 适合人群
     */
    private String suitableRange;

    /**
     * 项目介绍
     */
    private String introduce;

    /**
     * 检查地址
     */
    private String address;

    /**
     * 备注
     */
    private String remark;

    /**
     * 是否删除(0-未删除，1-已删除)
     */
    private Integer delFlag;

    /**
     * 创建人
     */
    private String createId;

    /**
     * 创建时间
     */
    @TableField(fill = FieldFill.INSERT)
    private LocalDateTime createTime;

    /**
     * 修改人
     */
    private String updateId;

    /**
     * 修改时间
     */
    private LocalDateTime updateTime;

    /**
     * 删除人
     */
    private String deleteId;

    /**
     * 删除时间
     */
    private LocalDateTime deleteTime;

    /**
     * 所属部门
     */
    private String departmentId;

    /**
     * 诊断模板
     */
    private String template;

    /**
     * 服务类型
     */
    private String serviceType;

    /**
     * 标本
     */
    private String specimen;

    /**
     * 诊台是否显示
     */
    private String diagnostic;

    /**
     * 是否为附件
     */
    private String isFile;

    /**
     * 获取影像结果的标识
     */
    private String url;

    /**
     * lis标本
     */
    private String lisSpecimen;

    /**
     * lis标本名字
     */
    private String lisSpecimenName;

    /**
     * lis系统对应Id
     */
    private String lisId;

    /**
     * lis系统对应编码
     */
    private String lisCode;

    /**
     * 部位名称
     */
    private String deptName;

    private String hazardFactorCode;


}
