package com.zeroone.star.role.controller;


import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.j2.RoleApis;
import com.zeroone.star.project.j2.dto.*;
import com.zeroone.star.project.j2.query.RoleCriteriaQuery;
import com.zeroone.star.project.j2.query.RolePerSetQuery;
import com.zeroone.star.project.j2.query.RoleQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.role.service.ITRoleService;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.transaction.annotation.Transactional;
import org.springframework.validation.annotation.Validated;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestMapping;

import org.springframework.web.bind.annotation.RestController;

import javax.annotation.Resource;

/**
 * <p>
 * 角色 前端控制器
 * </p>
 *
 * @author camille
 * @since 2024-01-15
 */


@RestController
@Api(tags = "角色信息")
@RequestMapping("/role/t-role")
public class TRoleController implements RoleApis{

    @Resource
    ITRoleService roleService;

    @GetMapping("/get-role-names")
    @ApiOperation(value = "获取角色名称列表")
    @Override
    public JsonVO<RoleNameDTO> queryAllNames() {

        return JsonVO.success(roleService.getRoleNames());
    }

    @GetMapping("/query-by-condition")
    @ApiOperation(value = "获取角色列表（分页+条件）")
    @Transactional
    @Override
    public JsonVO<PageDTO<RoleDTO>> queryByCondition(@Validated RoleCriteriaQuery roleCriteriaQuery) {
        return JsonVO.success(roleService.getByCondition(roleCriteriaQuery));
    }

    @PostMapping("/add-role")
    @ApiOperation(value = "新增角色")
    @Override
    public JsonVO<Long> addRole(RoleAddDTO roleAddDTO) {
        return null;
    }


    @PostMapping("/RolePermission")
    @ApiOperation(value = "设置角色权限")
    @Override
    public JsonVO<RolePerSetDTO> RolePerSetDTO(RolePerSetQuery rolePerSetQuery
    ) {
        return null;
    }

    @PostMapping("/modify-role")
    @ApiOperation(value = "修改角色")
    @Override
    public JsonVO<Long> modifyRole(RoleUpdateDTO roleUpdateDTO) {
        return null;
    }

    @PostMapping("/delete-role")
    @ApiOperation(value = "删除")
    @Override
    public JsonVO<Long> removeRole(RoleDTO roleDTO) {
        return null;
    }


}


