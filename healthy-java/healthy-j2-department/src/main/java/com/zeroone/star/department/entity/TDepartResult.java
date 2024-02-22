package com.zeroone.star.department.entity;

import com.baomidou.mybatisplus.annotation.TableName;
import java.io.Serializable;
import java.time.LocalDateTime;
import lombok.Getter;
import lombok.Setter;

/**
 * <p>
 * 诊台结果
 * </p>
 *
 * @author camille
 * @since 2024-01-15
 */
@Getter
@Setter
@TableName("t_depart_result")
public class TDepartResult implements Serializable {

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
     * 分组项目id
     */
    private String groupItemId;

    /**
     * 分组项目名称
     */
    private String groupItemName;

    /**
     * 诊断提醒
     */
    private String diagnoseTip;

    /**
     * 诊断小结
     */
    private String diagnoseSum;

    /**
     * 科室id
     */
    private String officeId;

    /**
     * 科室名称
     */
    private String officeName;

    /**
     * 检查次数
     */
    private Integer checkNum;

    /**
     * 检查医生
     */
    private String checkDoc;

    /**
     * 检查日期
     */
    private LocalDateTime checkDate;

    /**
     * 删除状态
     */
    private Integer delFlag;

    /**
     * 结果状态(0-一般，1-最优)
     */
    private Integer state;

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
     * 是否为附件
     */
    private String isFile;

    /**
     * 检查医生签名
     */
    private String checkSign;

    /**
     * 附件地址
     */
    private String url;

    /**
     * 是否复查（0-否，1-是）
     */
    private Integer isRecheck;


}
