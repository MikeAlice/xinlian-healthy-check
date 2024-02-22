package com.zeroone.star.sysmanager.controller;

import com.zeroone.star.project.dto.j3.system.SystemNoticeDTO;
import com.zeroone.star.project.j3.sysconfig.SysConfigApis;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j3.sysConfig.TSettingVO;
import com.zeroone.star.sysmanager.service.impl.TSettingServiceImpl;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;

import javax.validation.Valid;

/**
 * 系统配置Controller
 *
 * @author ZhangJF
 * @date 2024/01/15 22:10
 **/
@RestController
@RequestMapping("/sysconfig-sysConfig")
@Api("系统公告配置")
public class SysConfigController implements SysConfigApis {
    @Autowired
    private TSettingServiceImpl tSettingService;
    @ApiOperation("新增公告")
    @PostMapping("/addSystemNotice")
    @Override
    public JsonVO<SystemNoticeDTO> addSystemNotice(SystemNoticeDTO systemNoticeDTO) throws Exception {
        JsonVO<SystemNoticeDTO> jsonVO = tSettingService.addSystemNotice(systemNoticeDTO);
        return jsonVO;
    }

    @ApiOperation("修改公告")
    @PutMapping("/modifySystemNotice")
    @Override
    public JsonVO<SystemNoticeDTO> modifySystemNotice(SystemNoticeDTO systemNoticeDTO) throws Exception {
        JsonVO<SystemNoticeDTO> jsonVO = tSettingService.modifySystemNotice(systemNoticeDTO);
        return jsonVO;
    }

    @ApiOperation("获取公告")
    @GetMapping("/querySystemNotice")
    @Override
    public JsonVO<TSettingVO> querySystemNotice() {
        return tSettingService.querySystemNotice();
    }
}
