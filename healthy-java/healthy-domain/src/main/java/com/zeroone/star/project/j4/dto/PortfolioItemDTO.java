package com.zeroone.star.project.j4.dto;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.time.LocalDateTime;

/**
 * @Description: 组合项目的详情信息
 * @Author: Laputa
 * @CreateTime: 2024-01-20  11:36
 * @Version: 1.0
 */
@Data
@ApiModel("项目详情DTO")
public class PortfolioItemDTO {

    @ApiModelProperty(value = "主键", example = "1")
    private String id;

    @ApiModelProperty(value = "名称", example = "Project A")
    private String name;

    @ApiModelProperty(value = "简称", example = "PA")
    private String shortName;

    @ApiModelProperty(value = "排序", example = "1.0")
    private float orderNum;

    @ApiModelProperty(value = "父节点ID", example = "parent1")
    private String parentId;

    @ApiModelProperty(value = "科室名称", example = "Department A")
    private String officeName;

    @ApiModelProperty(value = "科室ID", example = "office123")
    private String officeId;

    @ApiModelProperty(value = "原价（元）", example = "100")
    private Integer marketPrice;

    @ApiModelProperty(value = "销售价（元）", example = "80")
    private Integer salePrice;

    @ApiModelProperty(value = "成本价（元）", example = "60")
    private Integer costPrice;

    @ApiModelProperty(value = "适合人群", example = "Adults")
    private String suitableRange;

    @ApiModelProperty(value = "项目介绍", example = "This is a project description.")
    private String introduce;

    @ApiModelProperty(value = "检查地址", example = "123 Main St")
    private String address;

    @ApiModelProperty(value = "备注", example = "Additional notes")
    private String remark;

    @ApiModelProperty(value = "是否删除(0-未删除，1-已删除)", example = "0")
    private int delFlag;

    @ApiModelProperty(value = "创建人", example = "John Doe")
    private String createId;

    @ApiModelProperty(value = "创建时间", example = "2024-01-20T11:36:00")
    private LocalDateTime createTime;

    @ApiModelProperty(value = "修改人", example = "Jane Doe")
    private String updateId;

    @ApiModelProperty(value = "修改时间", example = "2024-01-20T12:00:00")
    private LocalDateTime updateTime;

    @ApiModelProperty(value = "删除人", example = "Admin")
    private String deleteId;

    @ApiModelProperty(value = "删除时间", example = "2024-01-21T09:45:00")
    private LocalDateTime deleteTime;

    @ApiModelProperty(value = "所属部门", example = "Department XYZ")
    private String departmentId;

    @ApiModelProperty(value = "诊断模板", example = "Template ABC")
    private String template;

    @ApiModelProperty(value = "服务类型", example = "Type X")
    private String serviceType;

    @ApiModelProperty(value = "标本", example = "Sample XYZ")
    private String specimen;

    @ApiModelProperty(value = "诊台是否显示", example = "true")
    private String diagnostic;

    @ApiModelProperty(value = "是否为附件", example = "false")
    private String isFile;

    @ApiModelProperty(value = "获取影像结果的标识", example = "image123")
    private String url;

    @ApiModelProperty(value = "lis标本", example = "LIS Sample ABC")
    private String lisSpecimen;

    @ApiModelProperty(value = "lis标本名字", example = "LIS Sample Name XYZ")
    private String lisSpecimenName;

    @ApiModelProperty(value = "lis系统对应Id", example = "lisId123")
    private String lisId;

    @ApiModelProperty(value = "lis系统对应编码", example = "lisCode456")
    private String lisCode;

    @ApiModelProperty(value = "部位名称", example = "Body Part ABC")
    private String deptName;

    @ApiModelProperty(value = "危险因素编码", example = "HFC001")
    private String hazardFactorCode;
}
