package com.zeroone.star.term.controller;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.j4.dto.TermDTO;
import com.zeroone.star.project.j4.dto.TermDetailDto;
import com.zeroone.star.project.j4.query.SwitchTermQuery;
import com.zeroone.star.project.j4.query.TermNameQuery;
import com.zeroone.star.project.j4.query.TermQuery;
import com.zeroone.star.project.j4.termanagement.TOfficeTermApi;
import com.zeroone.star.project.j4.termanagement.TermApis;
import com.zeroone.star.project.j4.vo.TermDetailVo;
import com.zeroone.star.project.j4.vo.TermNameVo;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.ResultStatus;
import com.zeroone.star.term.service.ITOfficeTermService;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.validation.annotation.Validated;
import org.springframework.web.bind.annotation.*;

import javax.annotation.Resource;


@RestController
@RequestMapping("/terms")
@Api(tags = "术语管理接口")
@Validated
public class TOfficeTermController implements TermApis, TOfficeTermApi {
    @Resource
    private ITOfficeTermService itOfficeTermService;
    @Autowired
    private ITOfficeTermService termService;


    @Override
    @ApiOperation("修改术语")
    @PostMapping("/modify-term")
    public JsonVO<ResultStatus> modifyOfficeTerm(@Validated @RequestBody TermDTO termDTO) {
        return itOfficeTermService.updateOfficeTerm(termDTO);
    }

    @ApiOperation(value = "启用/禁止术语")
    @PostMapping("switch-term")
    @Override
    public JsonVO<Boolean> switchTerm(SwitchTermQuery query) throws Exception {
        if (query == null) {
            throw new RuntimeException("请求参数不能为空");
        }
        Boolean b = termService.switchTerm(query);
        if (b != true) {
            return JsonVO.fail(false);
        }
        return JsonVO.success(true);
    }

    @ApiOperation("获取术语列表")
    @GetMapping("query-term-list")
    @Override
    public JsonVO<PageDTO<TermDTO>> queryTermListAll(@Validated TermQuery condition) {
        return JsonVO.success(itOfficeTermService.queryTermList(condition));
    }

    @ApiOperation("获取术语名称列表")
    @GetMapping("query-termname-list")
    @Override
    public JsonVO<PageDTO<TermNameVo>> queryTermnameList(@Validated TermNameQuery condition1) {
        return JsonVO.success(itOfficeTermService.queryTermnameList(condition1));

    }

    @ApiOperation("获取术语详情")
    @GetMapping("/query-term-detail/{id}")
    @Override
    public JsonVO<TermDetailVo> queryTermDetail(@PathVariable String id) {
        return JsonVO.success(itOfficeTermService.queryTermDetail(id));

    }

    @ApiOperation("新增术语")
    @GetMapping("add—term")
    @Override
    public JsonVO<Boolean> addTerm(@Validated TermDetailDto termDetailDto) throws Exception {
        return itOfficeTermService.addTerm(termDetailDto);
    }

}


