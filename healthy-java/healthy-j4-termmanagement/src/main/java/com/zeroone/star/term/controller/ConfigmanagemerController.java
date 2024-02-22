package com.zeroone.star.term.controller;

import com.zeroone.star.project.j4.termanagement.ConfigmanagemerAPI;
import com.zeroone.star.project.j4.vo.SectionNameListVO;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.term.service.ITSectionOfficeService;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.validation.annotation.Validated;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import javax.annotation.Resource;
import java.util.List;

/**
 * @author: ;jiemo
 * @description: 组合项目controller
 */
@RestController
@RequestMapping("/terms")
@Api(tags = "术语管理接口")
@Validated
public class ConfigmanagemerController implements ConfigmanagemerAPI {
    @Resource
    private ITSectionOfficeService itSectionOfficeService;

    @ApiOperation(value = "获取科室名称" )
    @GetMapping("query-secion-name-list")
    @Override
    public JsonVO<List<SectionNameListVO>> querySectionName() {
        return JsonVO.success(itSectionOfficeService.listSectionName());
    }
}
