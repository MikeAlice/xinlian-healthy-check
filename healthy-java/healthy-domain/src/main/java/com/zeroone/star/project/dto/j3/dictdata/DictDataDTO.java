package com.zeroone.star.project.dto.j3.dictdata;

import com.baomidou.mybatisplus.annotation.FieldFill;
import com.baomidou.mybatisplus.annotation.TableField;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

import java.io.Serializable;
import java.math.BigDecimal;
import java.time.LocalDateTime;

/**
 * *作者：MSNzqs
 * *日期：2024/1/27 16:16
 * *文件描述：字典数据传输对象
 */

@Data
@AllArgsConstructor
@NoArgsConstructor
@ApiModel("字典数据DTO")
public class DictDataDTO implements Serializable {
    private static final long serialVersionUID = 1L;

    /**
     * 唯一标识
     */
    @ApiModelProperty(value = "id",example = "1443382289869443073")
    private String id;

    /**
     * 创建人
     */
    @ApiModelProperty(value = "创建者",example = "admin")
    private String createBy;

    /**
     * 创建时间
     */
    @TableField(fill = FieldFill.INSERT)
    @ApiModelProperty(value = "创建时间",example = "2021-09-30 14:51:15")
    private LocalDateTime createTime;

    /**
     * 删除标记 0不删除 1已删除
     */
    @ApiModelProperty(value = "删除标记",example = "0")
    private Boolean delFlag;

    /**
     * 修改人
     */
    @ApiModelProperty(value = "修改人",example = "admin")
    private String updateBy;

    /**
     * 修改时间
     */
    @ApiModelProperty(value = "删除时间",example = "2021-10-09 09:23:26")
    private LocalDateTime updateTime;

    /**
     * 备注
     */
    @ApiModelProperty(value = "备注",example = "健康体检")
    private String description;

    /**
     * 对应字典编号
     */
    @ApiModelProperty(value = "字典编号",example = "1452607630634782720")
    private Long dictId;

    /**
     * 排序号
     */
    @ApiModelProperty(value = "排序号",example = "1")
    private BigDecimal sortOrder;

    /**
     * 是否启用 0 启用 1 禁用
     */
    @ApiModelProperty(value = "状态",example = "0")
    private Boolean status;

    /**
     * 数据名称
     */
    @ApiModelProperty(value = "数据名称",example = "大型")
    private String title;

    /**
     * 数据值
     */
    @ApiModelProperty(value = "数据值",example = "健康体检")
    private String value;
}
