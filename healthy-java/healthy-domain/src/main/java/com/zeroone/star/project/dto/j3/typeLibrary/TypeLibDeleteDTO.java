package com.zeroone.star.project.dto.j3.typeLibrary;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.io.Serializable;
import java.util.Date;

/**
 * @program:IntelliJ IDEA
 * @Description:类型库
 * @author:Mr.CheCheHuiBujianO
 * @data: 2024/1/17 12:23
 */
@Data
@Api("类型库")
public class TypeLibDeleteDTO implements Serializable {
    @ApiModelProperty(value = "id",required = true,example = "100")
    private Integer id;
    @ApiModelProperty(value = "类型名称",required = false,example = "内资企业")
    private String typeName;
    @ApiModelProperty(value = "类型编码",required = false,example = "100")
    private String typeCode;
    @ApiModelProperty(value = "排序")
    private Integer orderNum;
    @ApiModelProperty(value = "备注")
    private String  remark;
    @ApiModelProperty(value = "父节点",required = false,example = "100")
    private String  parentId;
    @ApiModelProperty(value = "创建人id")
    private String  createId;
    @ApiModelProperty(value = "创建时间")
    private Date createTime;
    @ApiModelProperty(value = "修改人id")
    private String updateId;
    @ApiModelProperty(value = "修改时间")
    private Date updateTime;
    @ApiModelProperty(value = "删除人id")
    private String deleteId;
    @ApiModelProperty(value = "删除时间")
    private String deleteTime;
    @ApiModelProperty(value = "删除标志,(0为未删除，1为删除)")
    private Date deleteFlag;

}
