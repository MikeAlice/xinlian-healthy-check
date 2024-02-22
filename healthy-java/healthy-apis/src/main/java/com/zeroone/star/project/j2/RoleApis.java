package com.zeroone.star.project.j2;

import com.zeroone.star.project.dto.PageDTO;

import com.zeroone.star.project.dto.cpp.SampleDTO;
import com.zeroone.star.project.j2.dto.*;
import com.zeroone.star.project.j2.query.RoleCriteriaQuery;
import com.zeroone.star.project.j2.query.RolePerSetQuery;
import com.zeroone.star.project.j2.query.RoleQuery;
import com.zeroone.star.project.vo.JsonVO;
import springfox.documentation.spring.web.json.Json;

public interface RoleApis {

    /**
     * 新增角色
     * @param roleAddDTO
     * @return
     */
    JsonVO<Long> addRole(RoleAddDTO roleAddDTO);



    /**
     * 获取角色名称列表
     *
     * @return 默认分页的角色名称列表
     */
    JsonVO<RoleNameDTO> queryAllNames();

    /**
     * 获取分页+条件角色列表
     *
     * @param roleCriteriaQuery 查询条件和分页信息
     * @return 符合条件的角色列表
     */

    JsonVO<PageDTO<RoleDTO>> queryByCondition(RoleCriteriaQuery roleCriteriaQuery);


    /**
     * 设置角色权限
     *
     * @param
     * @return 符合条件的角色列表
     */
    JsonVO<RolePerSetDTO> RolePerSetDTO(RolePerSetQuery rolePerSetQuery);


    //角色修改
    JsonVO<Long> modifyRole(RoleUpdateDTO roleUpdateDTO);

    //角色删除
    JsonVO<Long> removeRole(RoleDTO roleDTO);

}
