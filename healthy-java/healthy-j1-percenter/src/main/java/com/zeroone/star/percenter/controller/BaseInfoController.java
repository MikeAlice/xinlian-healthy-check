package com.zeroone.star.percenter.controller;

import com.zeroone.star.percenter.service.ITUserService;
import com.zeroone.star.project.j1.dto.percenter.ModifyPersonalInfoDTO;
import com.zeroone.star.project.j1.percenter.BaseInfoApis;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.ResultStatus;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiModelProperty;
import io.swagger.annotations.ApiOperation;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import javax.annotation.Resource;

@RestController
@RequestMapping("/base-info")
@Api(tags = "基本信息")
public class BaseInfoController implements BaseInfoApis {

    @Resource
    private ITUserService userService;
    /**
     * 修改个人基础信息
     * @param modifyPersonalInfoDTO 可修改的个人基础信息
     * @return
     */
    @Override
    @PostMapping("/modify-personal-info")
    @ApiOperation("修改个人基础信息")
    public JsonVO<String> modifyPersonalInfo(@RequestBody ModifyPersonalInfoDTO modifyPersonalInfoDTO) throws Exception {
        userService.updatePersonalInfo(modifyPersonalInfoDTO);
        return JsonVO.success(ResultStatus.SUCCESS.getMessage());
    }
}
