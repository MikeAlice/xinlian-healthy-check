package com.zeroone.star.sectionoffice.controller;


import com.zeroone.star.project.j4.tsectionoffice.TSectionOfficeApis;
import com.zeroone.star.project.j4.dto.TSectionOfficeDTO;

import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.ResultStatus;
import com.zeroone.star.sectionoffice.service.ITSectionOfficeService;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.validation.annotation.Validated;
import org.springframework.web.bind.annotation.*;

import javax.annotation.Resource;
import javax.validation.constraints.NotNull;
import java.util.List;

/**
 * <p>
 *  前端控制器
 * </p>
 *
 * @author AYuan
 * @since 2024-01-16
 */
@RestController
@Api(tags = "科室管理")
@RequestMapping("/sectionoffice")
@Validated
public class TSectionOfficeController implements TSectionOfficeApis {

    @Resource
    private ITSectionOfficeService itSectionOfficeService;


    /**
     * @Author: ayuan
     * @param: [tSectionOfficeDTO]
     * @return: com.zeroone.star.project.vo.JsonVO<com.zeroone.star.project.vo.ResultStatus>
     * @Description: 新增科室
     **/
    @PostMapping("add-section-office")
    @ApiOperation("新增科室")
    @Override
    public JsonVO<ResultStatus> addSectionOffice(@Validated @RequestBody TSectionOfficeDTO tSectionOfficeDTO) {
        return itSectionOfficeService.saveSectionOffice(tSectionOfficeDTO);
    }

    /**
     * @Author: ayuan
     * @param: [tSectionOfficeDTO]
     * @return: com.zeroone.star.project.vo.JsonVO<com.zeroone.star.project.vo.ResultStatus>
     * @Description: 修改科室
     **/
    @PutMapping("modify-section-office")
    @ApiOperation("修改科室")
    @Override
    public JsonVO<ResultStatus> modifySectionOffice(@Validated @RequestBody TSectionOfficeDTO tSectionOfficeDTO) {
        return itSectionOfficeService.updateSectionOffice(tSectionOfficeDTO);

    }

    /**
     * @Author: ayuan
     * @param: [ids]
     * @return: com.zeroone.star.project.vo.JsonVO<com.zeroone.star.project.vo.ResultStatus>
     * @Description: 删除科室
     **/
    @DeleteMapping("remove-section-office")
    @ApiOperation("删除科室")
    @Override
    public JsonVO<ResultStatus> removeSectionOffice(@NotNull(message = "List不能为空") @RequestParam List<String> ids) {
        return itSectionOfficeService.removeSectionOffice(ids);
    }


}

