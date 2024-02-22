package com.zeroone.star.project.j4.dto;

import io.swagger.annotations.ApiModelProperty;

import java.util.Date;

public class UpdateTermanagementDTO {
    //主键
    @ApiModelProperty(value = "主键")
    private String id;
    //科室Id
    @ApiModelProperty(value = "科室Id")
    private String officeId;
    //危害因素text
    @ApiModelProperty(value = "危害因素text")
    private String hazardFactorsText;
    //体检类型
    @ApiModelProperty(value = "体检类型")
    private String inspectType;
    //危害因素
    @ApiModelProperty(value = "危害因素")
    private String hazardFactors;
    //类型
    @ApiModelProperty(value = "类型")
    private String type;
    //状态(0-启用，1-停用)
    @ApiModelProperty(value = "状态(0-启用，1-停用)")
    private String status;
    //术语内容
    @ApiModelProperty(value = "术语内容")
    private String content;
    //排序
    @ApiModelProperty(value = "排序")
    private String orderNum;
    //是否删除(0-未删除，1-已删除)
    @ApiModelProperty(value = "是否删除(0-未删除，1-已删除)")
    private Integer delFlag;
    //创建人
    @ApiModelProperty(value = "创建人")
    private String createId;
    //创建时间
    @ApiModelProperty(value = "创建时间")
    private Date createTime;
    //修改人
    @ApiModelProperty(value = "修改人")
    private String updateId;
    //修改时间
    @ApiModelProperty(value = "修改时间")
    private Date updateTime;
    //删除人
    @ApiModelProperty(value = "删除人")
    private String deleteId;
    //删除时间
    @ApiModelProperty(value = "删除时间")
    private Date deleteTime;
    //在岗状态编码
    @ApiModelProperty(value = "在岗状态编码")
    private String workStateCode;
    //在岗状态
    @ApiModelProperty(value = "在岗状态")
    private String workStateText;
}
