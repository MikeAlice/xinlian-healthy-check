package com.zeroone.star.sysmanager.controller;

import com.alibaba.nacos.shaded.com.google.protobuf.ServiceException;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j3.stopword.StopWordDTO;
import com.zeroone.star.project.dto.j3.stopword.UpdateWordDTO;
import com.zeroone.star.project.j3.stopword.StopWordApis;
import com.zeroone.star.project.query.j3.StopWordQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.sysmanager.entity.StopWord;
import com.zeroone.star.sysmanager.service.ITStopWordService;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.validation.annotation.Validated;
import org.springframework.web.bind.annotation.*;

import javax.annotation.Resource;
import javax.servlet.http.HttpServletRequest;
import java.util.ArrayList;
import java.util.List;
import java.util.logging.ErrorManager;

/**
 * 禁用词
 *
 * @author ZhangJF
 * @date 2024/01/23 19:41
 **/
@RestController
@RequestMapping("/sysconfig-stopWord")
@Api("禁用词管理")
public class StopWordController implements StopWordApis {

    @Resource
    private ITStopWordService stopWordService;
    @ApiOperation("获取禁用词列表（条件+分页）")
    @GetMapping("/queryStopWord")
    @Override
    public JsonVO<PageDTO<StopWordDTO>> queryStopWord(StopWordQuery query) {
        return JsonVO.success(stopWordService.listpage(query));
    }

    @ApiOperation("添加禁用词")
    @PostMapping("/addStopWord")
    @Override
    public JsonVO<Boolean> addStopWord(@Validated StopWordDTO addWord) {
            boolean count = stopWordService.addWord(addWord);
            if (count) {
                return JsonVO.success(true);
            }
            return JsonVO.fail(false);
    }

    @PutMapping("/updateWord")
    @ApiOperation("修改禁用词")
    @Override
    public JsonVO<Boolean> updateWord(UpdateWordDTO updateWord) {
        int count = stopWordService.updateWord(updateWord);
        if (count > 0) {
            return JsonVO.success(true);
        }
        return JsonVO.fail(false);
    }

    @DeleteMapping("/deleteWordsByIds")
    @ApiOperation("删除禁用词（支持批量删除）")
    @Override
    public JsonVO<Boolean> deleteWordsByIds(@RequestParam List<String> ids) {
        boolean success = stopWordService.removeByIds(ids);
        if (success) {
            return JsonVO.success(success);
        }
        return JsonVO.fail(success);
    }
}
