package com.zeroone.star.project.vo.j3.sysConfig;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

@Data
@ApiModel("系统公告配置返回vo")
public class TSettingVO {
    private static final long serialVersionUID = 1L;

    @ApiModelProperty(value = "设置值，，多个值存储json字符串",example = "{title:11,context:22}")
    private String value;
}
