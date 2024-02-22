package com.zeroone.star.sectionoffice.controller;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.j4.query.SectionOfficeDetailQuery;
import com.zeroone.star.project.j4.tsectionoffice.SectionOfficeApi;
import com.zeroone.star.project.j4.dto.GetSecNameDTO;
import com.zeroone.star.project.j4.dto.GetSectionOfficetDTO;
import com.zeroone.star.project.j4.query.GetSectionOfficeQuery;
import com.zeroone.star.project.j4.vo.GetSecNameVO;
import com.zeroone.star.project.j4.vo.GetSectionOfficeVO;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.sectionoffice.service.SectionOfficeService;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import java.util.List;

/**
 * (SectionOffice)表控制层
 *
 * @author makejava
 * @since 2024-01-17 21:52:28
 */
@RestController
@RequestMapping("/sectionoffice")
@Api(tags = "科室管理")
public class SectionOfficeController implements SectionOfficeApi {
    private final SectionOfficeService sectionOfficeService;

    @Autowired
    public SectionOfficeController(SectionOfficeService sectionOfficeService) {
        this.sectionOfficeService = sectionOfficeService;
    }

    @Override
    @GetMapping("query-allsection-office")
    @ApiOperation(value = "获取科室列表（分页+条件）")
    public JsonVO<PageDTO<GetSectionOfficeVO>> queryAllSectionOffice(GetSectionOfficeQuery query) {
        return JsonVO.success(sectionOfficeService.listAllSectionOffice(query));

    }

    @Override
    @GetMapping("query-allsection-office-name")
    @ApiOperation(value = "获取科室名称列表")
    public JsonVO<PageDTO<GetSecNameVO>> GetAllSecName(GetSecNameDTO getSecNameDTO) {
        return JsonVO.success(sectionOfficeService.listAllName(getSecNameDTO));
    }


    @Override
    @GetMapping("query-section-office-detail")
    @ApiOperation(value = "获取科室详情")
    public JsonVO<GetSectionOfficeVO> GetAllSectionOffice(SectionOfficeDetailQuery query) {
        return JsonVO.success((sectionOfficeService.getAllSectionOffice(query)));
    }


}

