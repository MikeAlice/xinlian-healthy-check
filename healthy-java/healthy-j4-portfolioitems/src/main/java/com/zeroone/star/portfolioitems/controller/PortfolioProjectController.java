package com.zeroone.star.portfolioitems.controller;

import com.baomidou.mybatisplus.core.toolkit.StringUtils;
import com.zeroone.star.portfolioitems.service.PortfolioProjectService;
import com.zeroone.star.project.j4.dto.TPortfolioProjectDTO;
import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;

import java.util.List;

/**
 * @author rakkaus
 */
@RestController
@RequestMapping("portfolioitems")
@Api(tags = "组合项目接口")
public class PortfolioProjectController {

    @Autowired
    private PortfolioProjectService portfolioProjectService;

    @PostMapping("addproject")
    @ApiOperation("新增组合项目数据")
    public JsonVO addproject(@RequestBody TPortfolioProjectDTO TPortfolioProjectDTO){
        return portfolioProjectService.save(TPortfolioProjectDTO);
    }


    @ApiOperation("根据主键来删除组合项目数据")
    @PostMapping("deletePproject")
    private JsonVO deleteproject(@RequestParam List<String> ids){
        if (ids==null){
            return JsonVO.fail("删除失败,参数错误");
        }
        return portfolioProjectService.delete(ids);
    }
    @ApiOperation("根据主键来修改组合项目数据")
    @PostMapping("updatePproject")
    private JsonVO updateproject(@RequestBody TPortfolioProjectDTO TPortfolioProjectDTO){
        if (StringUtils.isBlank( TPortfolioProjectDTO.getId())) {
            return JsonVO.fail("删除失败,参数错误");
        }
        return portfolioProjectService.updateById(TPortfolioProjectDTO);

    }
}
