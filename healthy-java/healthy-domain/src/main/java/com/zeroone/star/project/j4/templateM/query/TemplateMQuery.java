package com.zeroone.star.project.j4.templateM.query;

import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import org.springframework.format.annotation.DateTimeFormat;

import java.util.Date;

/**
 * <p>
 * 描述：模板管理查询对象 TemplateManagementQuery
 * </p>
 *
 * @author Triple Gold
 * @version 1.0.0
 */
@Data
@ApiModel(value = "模板管理查询对象")
public class TemplateMQuery extends PageQuery {
    /**
     * 报告类型
     */
    @ApiModelProperty(value = "报告类型", example = "放射体检")
    private String reportType;
    /**
     * 模板类型
     */
    @ApiModelProperty(value = "模板类型", example = "引导单")
    private String type;
    /**
     * 项目名称
     */
    @ApiModelProperty(value = "项目名称", example = "")
    private String name;
    /**
     * 模板状态
     */
    @ApiModelProperty(value = "模板状态", example = "")
    private String status;
    /**
     * 起始时间
     */
    @DateTimeFormat(pattern = "yyyy-MM-dd HH:mm:ss")    // 规范标准
    @ApiModelProperty(value = "起始时间", example = "")
    private Date startTime;
    /**
     * 结束时间
     */
    @DateTimeFormat(pattern = "yyyy-MM-dd HH:mm:ss")
    @ApiModelProperty(value = "结束时间", example = "")
    private Date endTime;
}
