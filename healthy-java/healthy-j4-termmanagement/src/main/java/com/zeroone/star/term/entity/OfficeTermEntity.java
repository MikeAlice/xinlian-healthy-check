package com.zeroone.star.term.entity;

import java.util.Date;

import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

/**
 * 科室术语表(OfficeTerm)表实体类
 *
 * @author makejava
 * @since 2024-01-30 14:43:18
 */
@SuppressWarnings("serial")
@Data
@NoArgsConstructor
@AllArgsConstructor
public class OfficeTermEntity {
    //主键
    private String id;
    //科室Id
    private String officeId;
    //危害因素text
    private String hazardFactorsText;
    //体检类型
    private String inspectType;
    //危害因素
    private String hazardFactors;
    //类型
    private String type;
    //状态(0-启用，1-停用)
    private String status;
    //术语内容
    private String content;
    //排序
    private String orderNum;
    //是否删除(0-未删除，1-已删除)
    private Integer delFlag;
    //创建人
    private String createId;
    //创建时间
    private Date createTime;
    //修改人
    private String updateId;
    //修改时间
    private Date updateTime;
    //删除人
    private String deleteId;
    //删除时间
    private Date deleteTime;
    //在岗状态编码
    private String workStateCode;
    //在岗状态
    private String workStateText;

}
