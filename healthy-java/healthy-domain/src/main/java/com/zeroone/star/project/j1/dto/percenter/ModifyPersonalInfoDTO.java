package com.zeroone.star.project.j1.dto.percenter;

import cn.hutool.core.date.DateTime;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import org.springframework.format.annotation.DateTimeFormat;

import java.sql.Timestamp;
import java.time.LocalDateTime;

@Data
@ApiModel("修改个人信息传输的数据")
public class ModifyPersonalInfoDTO {
    @ApiModelProperty(value = "用户头像")
    private String avatar;
    @ApiModelProperty(value = "用户名")
    private String nickname;
    @ApiModelProperty(value = "性别", example = "男")
    private String sex;
    @ApiModelProperty(value = "生日", example = "1980-12-26 15:24:03")
    private LocalDateTime birth;
    @ApiModelProperty(value = "所在省市", example = "四川省,成都市,武侯区")
    private String address;
    @ApiModelProperty(value = "街道地址", example = "天府一街")
    private String street;
    @ApiModelProperty(value = "个人简介", example = "系统默认提供用户")
    private String description;
    @ApiModelProperty(value = "签名文件")
    private String autograph;
}
