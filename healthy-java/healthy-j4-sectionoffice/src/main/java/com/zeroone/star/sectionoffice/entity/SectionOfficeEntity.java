package com.zeroone.star.sectionoffice.entity;

import java.io.Serializable;
import java.util.Date;

import com.baomidou.mybatisplus.annotation.IdType;
import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import io.swagger.annotations.Api;
import lombok.*;

/**
 * (SectionOffice)表实体类
 *
 * @author makejava
 * @since 2024-01-17 21:52:30
 */
@SuppressWarnings("serial")
@Data
@Getter
@Setter
@TableName("t_section_office")
public class SectionOfficeEntity implements Serializable {
    private static final long serialVersionUID = 1L;
    //主键id
    @TableId(value = "id", type = IdType.AUTO)
    private String id;
    //编码
    private String sectionCode;
    //科室名称
    private String sectionName;
    //科室简拼
    private String sectionAlphbet;
    //排序
    private String orderNum;
    //联系人
    private String contact;
    //联系人电话
    private String contactMobile;
    //检查类型
    private String checkType;
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
    //所属部门
    private String departmentId;


}
