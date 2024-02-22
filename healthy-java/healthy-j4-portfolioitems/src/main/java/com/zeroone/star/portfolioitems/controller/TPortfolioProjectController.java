package com.zeroone.star.portfolioitems.controller;


import com.zeroone.star.portfolioitems.service.ITPortfolioProjectService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.j4.dto.PortfolioItemDTO;
import com.zeroone.star.project.j4.dto.PortfolioItemListDTO;
import com.zeroone.star.project.j4.portfolioitems.PortfolioProjectApi;
import com.zeroone.star.project.j4.query.PortfolioItemListQuery;
import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.validation.annotation.Validated;
import org.springframework.web.bind.annotation.*;

/**
 * <p>
 * 组合项目 前端控制器
 * </p>
 *
 * @author Laputa
 * @since 2024-01-24
 */
@RestController
@RequestMapping("/portfolioitems/")
@Api(tags = "组合项目接口")
public class TPortfolioProjectController implements PortfolioProjectApi {

    @Autowired
    private ITPortfolioProjectService itPortfolioProjectService;

    @ApiOperation(value = "组合项目的详情信息")
    @GetMapping("/{id}")
    @Override
    public JsonVO<PortfolioItemDTO> queryPortfolioItem(@PathVariable String id) throws Exception {
        if (id == null) {
            throw new RuntimeException("id不能为空");
        }
        PortfolioItemDTO portfolioItemDTO =  itPortfolioProjectService.getPortfolioItemById(id);
        return JsonVO.success(portfolioItemDTO);
    }

    @ApiOperation(value = "获取项目列表 (条件+分页）")
    @GetMapping("/query-lists")
    @Override
    public JsonVO<PageDTO<PortfolioItemListDTO>> queryPortfolioItemList(@Validated PortfolioItemListQuery query) throws Exception {
        if (query== null) {
            throw new RuntimeException("query不能为空");
        }
        PageDTO<PortfolioItemListDTO> pageDTO = itPortfolioProjectService.listPortfolioItems(query);
        return JsonVO.success(pageDTO);
    }


}

