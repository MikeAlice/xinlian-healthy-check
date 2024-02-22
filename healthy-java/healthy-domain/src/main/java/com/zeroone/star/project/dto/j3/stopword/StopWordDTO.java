package com.zeroone.star.project.dto.j3.stopword;

import com.zeroone.star.project.dto.PageDTO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiModelProperty;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

import java.util.Date;

/**
 * 禁用词列表dto
 *
 * @Author Qi
 * @Date 2024/1/16
 */
@Api("禁用词列表dto")
@Data
@AllArgsConstructor
@NoArgsConstructor
public class StopWordDTO extends PageDTO {
    @ApiModelProperty(value = "ID", example = "1",required = true)
    private String id;
    @ApiModelProperty(value = "创建者", example = "John Doe",required = true)
    private String createBy;
    @ApiModelProperty(value = "创建时间", example = "2022-01-01 12:00:00",required = true)
    private String createTime;
    @ApiModelProperty(value = "删除标志", example = "0",required = true)
    private String delFlag;
    @ApiModelProperty(value = "更新者", example = "Jane Smith",required = true)
    private String updateBy;
    @ApiModelProperty(value = "更新时间", example = "2022-01-02 15:00:00",required = true)
    private String updateTime;
    @ApiModelProperty(value = "禁用词", example = "stop word",required = true)
    private String title;

}
