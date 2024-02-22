package com.zeroone.star.project.dto.j3.system;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.io.Serializable;
import java.util.Date;

@Data
@ApiModel("获取系统公告的dto")
public class SystemNoticeDTO implements Serializable {
    @ApiModelProperty(value = "id", required = true, example = "100")
    private String id;
    @ApiModelProperty(value = "创建人",required = true)
    private String createBy;
    @ApiModelProperty(value = "创建时间",required = true)
    private Date createTime;
    @ApiModelProperty(value = "删除标记",required = true)
    private Boolean delFlag;
    @ApiModelProperty(value = "修改人",required = true)
    private String updateBy;
    @ApiModelProperty(value = "修改时间",required = true)
    private Date updateTime;
    @ApiModelProperty(value = "设置值",required = true)
    private String value;
}
