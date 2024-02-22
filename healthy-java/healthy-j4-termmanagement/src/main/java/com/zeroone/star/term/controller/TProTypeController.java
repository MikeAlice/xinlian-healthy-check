package com.zeroone.star.term.controller;


import com.zeroone.star.project.j4.dto.OccupationalHazardTreeDTO;
import com.zeroone.star.project.j4.termanagement.TProTypeApi;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.term.service.ITProTypeService;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.validation.annotation.Validated;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestMapping;

import org.springframework.web.bind.annotation.RestController;

import java.util.List;

/**
 * <p>
 * 类型库（如：职业危害因素，经济类型、行业类别等等） 前端控制器
 * </p>
 *
 * @author Laputa
 * @since 2024-01-30
 */
@RestController
@RequestMapping("/terms")
@Api(tags = "术语管理接口")
@Validated
public class TProTypeController implements TProTypeApi {

    @Autowired
    private ITProTypeService typeService;

    @ApiOperation(value = "获取职业危害因素树")
    @PostMapping("query-occupational-hazard-tree")
    @Override
    public JsonVO<List<OccupationalHazardTreeDTO>> queryOccupationalHazardTree() throws Exception {
        return JsonVO.success(typeService.listOccupationalHazardTree("TYPE_001"));
    }
}

