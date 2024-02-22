package com.zeroone.star.project.j1.dto.sysmanager;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

@Data
@ApiModel("科室管理数据模型")
public class DepartmentManagementDTO {
    @ApiModelProperty(value = "科室编码",example = "001")
    private String sectionCode;

    @ApiModelProperty(value = "科室名称",example = "心电图")
    private String sectionName;

    @ApiModelProperty(value = "科室编码",example = "XDT")
    private String sectionAlphbet;

    @ApiModelProperty(value = "排序",example = "1,2,3,4...")
    private String orderNum;

    @ApiModelProperty(value = "联系人",example = "李四")
    private String contact;

    @ApiModelProperty(value = "联系人电话",example = "18121971136")
    private String contactMobile;

    @ApiModelProperty(value = "检查类型",example = "职业检查,健康体检...")
    private String checkType;
}
