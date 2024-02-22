package com.zeroone.star.menu.controller;


import com.zeroone.star.project.j2.PermissionApis;
import com.zeroone.star.project.j2.dto.PermissionDTO;
import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestMapping;

import org.springframework.web.bind.annotation.RestController;

import java.util.List;

/**
 * <p>
 * 资源（菜单/操作权限） 前端控制器
 * </p>
 *
 * @author camille
 * @since 2024-01-15
 */
@RestController
@Api(tags = "菜单列表")
@RequestMapping("/menu/permission")
public class PermissionController implements PermissionApis {

    @ApiOperation("获取用户页面菜单数据")
    @GetMapping("getMenuList")
    @Override
    public JsonVO<List<PermissionDTO>> getAllMenuList() {
        return null;
    }

    @ApiOperation("获取权限菜单树")
    @GetMapping("allList")
    @Override
    public JsonVO<List<PermissionDTO>> getAllList() {
        return null;
    }

    @ApiOperation("添加资源")
    @PostMapping("add")
    @Override
    public JsonVO<PermissionDTO> add(PermissionDTO permission) {
        return null;
    }


    @ApiOperation("获取资源名称树")
    @GetMapping("getResourcesNameTree")
    @Override
    public JsonVO<List<PermissionDTO>> getResourcesNameTree() {
        return null;
    }

    @ApiOperation("搜索资源列表")
    @GetMapping("getResourceList")
    @Override
    public JsonVO<List<PermissionDTO>> getResourceList() {
        return null;
    }

}


