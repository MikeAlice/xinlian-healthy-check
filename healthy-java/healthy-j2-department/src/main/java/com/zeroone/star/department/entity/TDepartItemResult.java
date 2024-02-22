package com.zeroone.star.department.entity;

import com.baomidou.mybatisplus.annotation.TableName;
import java.io.Serializable;
import java.time.LocalDateTime;
import lombok.Getter;
import lombok.Setter;

/**
 * <p>
 * 诊台结果明细项
 * </p>
 *
 * @author camille
 * @since 2024-01-15
 */
@Getter
@Setter
@TableName("t_depart_item_result")
public class TDepartItemResult implements Serializable {

    private static final long serialVersionUID = 1L;

    /**
     * 主键id
     */
    private String id;

    /**
     * 体检人员Id
     */
    private String personId;

    /**
     * 选中的基础项目id
     */
    private String orderGroupItemProjectId;

    /**
     * 选中的基础项目名称
     */
    private String orderGroupItemProjectName;

    /**
     * 科室id
     */
    private String officeId;

    /**
     * 科室名称
     */
    private String officeName;

    /**
     * 体检结果
     */
    private String result;

    /**
     * 计量单位
     */
    private String unitCode;

    /**
     * 单位名称
     */
    private String unitName;

    /**
     * 范围
     */
    private String scope;

    /**
     * 检查医生
     */
    private String checkDoc;

    /**
     * 检查日期
     */
    private LocalDateTime checkDate;

    /**
     * 危急程度
     */
    private String crisisDegree;

    /**
     * 删除状态
     */
    private Integer delFlag;

    /**
     * 创建人id
     */
    private String createId;

    /**
     * 创建日期
     */
    private LocalDateTime createDate;

    /**
     * 更新人id
     */
    private String updateId;

    /**
     * 更新时间
     */
    private LocalDateTime updateDate;

    /**
     * 删除人id
     */
    private String deleteId;

    /**
     * 删除时间
     */
    private LocalDateTime deleteDate;

    /**
     * 指标箭头
     */
    private String arrow;

    /**
     * 影像图片，多个以逗号分隔
     */
    private String imgUrl;

    /**
     * 是否忽略异常（1-否，2-是）
     */
    private Integer ignoreStatus;

    /**
     * 基础项目检查结果id
     */
    private String departResultId;

    /**
     * 是否复查（0-否，1-是）
     */
    private Integer isRecheck;

    /**
     * 组合项目id
     */
    private String orderGroupItemId;

    /**
     * 组合项目名称
     */
    private String orderGroupItemName;

    /**
     * 排序
     */
    private Integer orderNum;

    /**
     * 诊断小结
     */
    private String diagnoseSum;

    /**
     * 阳性
     */
    private Integer positive;


}
