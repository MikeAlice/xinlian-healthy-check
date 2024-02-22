package com.zeroone.star.sysmanager.controller;

import com.zeroone.star.project.j1.dto.sysmanager.ModifyPasswordDTO;
import com.zeroone.star.project.j1.sysmanager.UserPasswordApis;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.sysmanager.service.UserPasswordService;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiImplicitParam;
import io.swagger.annotations.ApiOperation;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.validation.annotation.Validated;
import org.springframework.web.bind.annotation.*;

import java.util.List;

@RestController
@RequestMapping("/user-data")
@Api(tags = "用户管理-用户密码")
@Validated
public class UserPasswordController implements UserPasswordApis {

    @Autowired
    private UserPasswordService userPasswordService;

    @Override
    @PostMapping("/modify-password")
    @ApiOperation("更改密码接口")
    public JsonVO modifyPasswordToChange(@Validated @RequestBody ModifyPasswordDTO modifyPasswordDTO) {
        return userPasswordService.updatePasswordToChange(modifyPasswordDTO);
    }

    @Override
    @PostMapping("/reset-password")
    @ApiOperation("重置密码接口")
    @ApiImplicitParam(name = "ids",value = "被重置密码的所有用户的id,请求例子：['1','2','3']",required = true)
    public JsonVO modifyPasswordToReset(@RequestBody List<String> ids){
        return userPasswordService.updatePasswordToReset(ids);
    }


}
