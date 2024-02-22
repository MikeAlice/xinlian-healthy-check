package com.zeroone.star.term.entity;

import java.io.Serializable;

import com.baomidou.mybatisplus.annotation.*;
import lombok.Data;
import lombok.EqualsAndHashCode;
import java.time.LocalDateTime;


@Data
@EqualsAndHashCode(callSuper = false)
public class TOfficeTerm implements Serializable {

    private static final long serialVersionUID = 1L;

    /**
     * 主键
     */
    @TableId(value = "id", type = IdType.ASSIGN_UUID)
    private String id;

    /**
     * 科室Id
     */
    private String officeId;

    /**
     * 危害因素text
     */
    private String hazardFactorsText;

    /**
     * 体检类型
     */
    private String inspectType;

    /**
     * 危害因素
     */
    private String hazardFactors;

    /**
     * 类型
     */
    private String type;

    /**
     * 状态(0-启用，1-停用)
     */
    private String status;

    /**
     * 术语内容
     */
    private String content;

    /**
     * 排序
     */
    private Float orderNum;

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
     * 在岗状态编码
     */
    private String workStateCode;

    /**
     * 在岗状态
     */
    private String workStateText;

}