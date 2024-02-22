package com.zeroone.star.TemplateManagement.controller;

import com.zeroone.star.TemplateManagement.service.ITemplateMService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.j4.templateM.TemplateMApis;
import com.zeroone.star.project.j4.templateM.dto.ProjectDTO;
import com.zeroone.star.project.j4.templateM.dto.TemplateMListDTO;
import com.zeroone.star.project.j4.templateM.query.TemplateMQuery;
import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.validation.annotation.Validated;
import org.springframework.web.bind.annotation.*;

import javax.annotation.Resource;
import javax.validation.constraints.NotBlank;
import java.util.Objects;

/**
 * <p>
 * 描述：模板管理控制器
 * </p>
 *
 * @author Triple Gold
 * @version 1.0.0
 */
@RestController
@RequestMapping("/template")
@Api(tags = "模板管理接口")
@Validated
public class TemplateMController implements TemplateMApis {
    @Resource
    ITemplateMService service;

    @ApiOperation(value = "获取组合项目名称列表")
    @GetMapping("query-project-list")
    @Override
    public JsonVO<ProjectDTO> queryProjectList() {
        return JsonVO.success(service.listProjectList());
    }

    @ApiOperation(value = "获取模板列表")
    @GetMapping("query-list")
    @Override
    public JsonVO<PageDTO<TemplateMListDTO>> queryTemplateList(@Validated TemplateMQuery query) {
        return JsonVO.success(service.listTemplateList(query));
    }

    /*
     * 对于单参数，直接加如@NotBlank 注解可能会报错 A method overriding another method must not redefine the parameter constraint configuration
     * 因此再定义一个modifyTemplateStatusValidated 来调用原方法
     * */
    @Override
    public JsonVO<String> modifyTemplateStatus(String id) {
        String res = service.updateTemplateStatus(id);
        return JsonVO.success(res);
    }
    @ApiOperation(value = "启用/禁用模板")
    @PostMapping("modify-status")
    public JsonVO<String> modifyTemplateStatusValidated(
            @NotBlank(message = "id不能为空")
            @RequestParam String id) {
        return modifyTemplateStatus(id);
    }


    @Override
    public JsonVO<String> previewTemplate(String id) {
        String res = service.getTemplate(id);
        return JsonVO.success(res);
    }
    @ApiOperation(value = "预览模板")
    @GetMapping("query-content")
    public JsonVO<String> previewTemplateValidated(
            @NotBlank(message = "id不能为空")
            @RequestParam String id) {
        return previewTemplate(id);
    }
}
