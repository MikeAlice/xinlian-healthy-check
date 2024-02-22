package com.zeroone.star.project.dto.j3.dictory;

import com.baomidou.mybatisplus.annotation.FieldFill;
import com.baomidou.mybatisplus.annotation.TableField;
import com.baomidou.mybatisplus.annotation.TableName;
import java.io.Serializable;
import java.math.BigDecimal;
import java.time.LocalDateTime;

import io.github.classgraph.json.Id;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.*;
import org.apache.ibatis.annotations.SelectKey;

import javax.validation.constraints.NotBlank;

/**
 * <p>
 * 字典
 * </p>
 *
 * @author Anemon
 * @since 2024-01-16
 */
@ApiModel("字典基本数据对象")
@Data
@AllArgsConstructor
@NoArgsConstructor
@TableName("t_dict")
public class DictDTO implements Serializable {

    /**
     * 显示声明序列化 uid
     */
    private static final long serialVersionUID = 1L;

    /**
     * 创建人
     */
    @NotBlank(message = "创建人不能为空")
    @ApiModelProperty(value = "创建人",required = true)
    private String createBy;

    /**
     * 创建时间
     */
    @ApiModelProperty(value = "创建时间",required = true)
    @TableField(fill = FieldFill.INSERT)
    private LocalDateTime createTime;

    /**
     * 删除标记 0不删除 1已删除
     */
    @NotBlank(message = "删除标记不为空")
    @ApiModelProperty(value = "逻辑删除字段",example = "0",required = true)
    private Boolean delFlag;

    /**
     * 修改人
     */
    @ApiModelProperty(value = "修改人",required = true)
    private String updateBy;

    /**
     * 修改时间
     */
    @ApiModelProperty(value = "修改时间",required = true)
    @TableField(fill = FieldFill.UPDATE)
    private LocalDateTime updateTime;

    /**
     * 字典备注
     */
    @ApiModelProperty(value = "字典备注")
    private String description;

    /**
     * 字典名称
     */
    @NotBlank(message = "字典名称不为空")
    @ApiModelProperty(value = "字典名称",required = true)
    private String title;

    /**
     * 类型名称，用英文单词，并且唯一，它会用于查询
     */
    @NotBlank(message = "字典类型不为空")
    @ApiModelProperty(value = "字典类型",required = true)
    private String type;

    /**
     * 显示序号
     */
    @NotBlank(message = "字典序号不为空")
    @ApiModelProperty(value = "字典序号",required = true)
    private BigDecimal sortOrder;

}
