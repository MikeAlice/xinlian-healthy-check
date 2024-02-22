package com.zeroone.star.term.controller;

import com.zeroone.star.project.j4.termanagement.TermanagementApi;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.ResultStatus;
import com.zeroone.star.term.service.OfficeTermService;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.validation.annotation.Validated;
import org.springframework.web.bind.annotation.*;

import javax.validation.constraints.NotNull;
import java.util.List;

@RestController
@RequestMapping("/terms")
@Api(tags = "术语管理接口")
@Validated
public class TermanagementController implements TermanagementApi {
    @Autowired
    private OfficeTermService officeTermService;

    @Override
    @DeleteMapping("delete-termanagement")
    @ApiOperation(value = "删除术语")
    public JsonVO<ResultStatus> deletetermanagement(@NotNull(message = "List不能为空") @RequestParam List<String> ids) {
        return officeTermService.deletetermanagement(ids);
    }
}
