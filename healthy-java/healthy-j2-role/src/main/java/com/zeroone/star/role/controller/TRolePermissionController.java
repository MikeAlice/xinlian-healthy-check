package com.zeroone.star.role.controller;


import com.zeroone.star.project.j2.RolePermissionApis;
import com.zeroone.star.project.j2.dto.MessageDTO;
import com.zeroone.star.project.j2.dto.RoleDTO;
import com.zeroone.star.project.j2.dto.RolePermissionDTO;
import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestMapping;

import org.springframework.web.bind.annotation.RestController;

/**
 * <p>
 * 角色资源关系映射 前端控制器
 * </p>
 *
 * @author camille
 * @since 2024-01-15
 */
@RestController
@Api(tags = "角色权限")
@RequestMapping("/role/t-role-permission")
public class TRolePermissionController implements RolePermissionApis {
    @GetMapping("/permission")
    @ApiOperation(value = "获取角色菜单权限")
    @Override
    public JsonVO<RolePermissionDTO> queryRoleMenuPermission(long id) {
        return null;
    }


}

