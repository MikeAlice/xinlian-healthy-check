package com.zeroone.star.project.dto.j3.stopword;

import io.swagger.annotations.Api;
import io.swagger.annotations.ApiModelProperty;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

/**
 * @author ZhangJF
 * @date 2024/01/23 20:42
 **/
@Api("更新禁用词dto")
@Data
@AllArgsConstructor
@NoArgsConstructor
public class UpdateWordDTO {
    @ApiModelProperty(value = "ID", example = "1",required = true)
    private String id;
    @ApiModelProperty(value = "禁用词", example = "stop word")
    private String title;
}
