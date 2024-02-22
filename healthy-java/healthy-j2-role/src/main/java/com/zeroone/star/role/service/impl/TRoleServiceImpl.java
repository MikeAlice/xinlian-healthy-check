package com.zeroone.star.role.service.impl;

import com.baomidou.mybatisplus.core.conditions.query.LambdaQueryWrapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.j2.dto.RoleDTO;
import com.zeroone.star.project.j2.dto.RoleNameDTO;
import com.zeroone.star.project.j2.query.RoleCriteriaQuery;
import com.zeroone.star.role.config.entity.TRole;
import com.zeroone.star.role.mapper.TRoleMapper;
import com.zeroone.star.role.service.ITRoleService;
import org.mapstruct.Mapper;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;
import java.util.List;
import java.util.stream.Collectors;
/**
 * <p>
 * 描述：TRole对应MapStruct映射接口
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author 阿伟学长
 * @version 1.0.0
 */
@Mapper(componentModel = "spring")
interface MsRoleMapper {
    /**
     * 将TRoleDO 转换成 RoleDTO
     * @param tRole 待转换的DO
     * @return 转换结果
     */
    RoleDTO troleToRoleDto(TRole tRole);
}
/**
 * <p>
 * 角色 服务实现类
 * </p>
 *
 * @author camille
 * @since 2024-01-15
 */
@Service
public class TRoleServiceImpl extends ServiceImpl<TRoleMapper, TRole> implements ITRoleService {
    @Resource
    TRoleMapper roleMapper;
    @Resource
    MsRoleMapper msRoleMapper;
    //获取角色名称列表
    @Override
    public RoleNameDTO getRoleNames() {
        //构造条件查询器
        LambdaQueryWrapper<TRole> wrapper = new LambdaQueryWrapper<>();
        //查询字段：名称，查询条件，未被逻辑删除
        wrapper.select(TRole::getName).eq(TRole::getDelFlag,false);
        //查询角色名称列表
        List<TRole> roles = roleMapper.selectList(wrapper);
        List<String> roleNames = roles.stream().map((item)-> item.getName()).collect(Collectors.toList());
        RoleNameDTO roleNameDTO = new RoleNameDTO();
        roleNameDTO.setRoleNames(roleNames);
        return roleNameDTO;
    }
    //根据分页和条件查询角色列表
    @Override
    public PageDTO<RoleDTO> getByCondition(RoleCriteriaQuery roleCriteriaQuery) {
        //获取分页条件对象
        long pageSize = roleCriteriaQuery.getPageSize();
        long pageIndex = roleCriteriaQuery.getPageIndex();
        //获取查询条件
        String name = roleCriteriaQuery.getName();
        //构造分页查询对象
        Page<TRole> page = new Page<>(pageIndex,pageSize);
        //构造条件查询对象
        LambdaQueryWrapper<TRole> wrapper = new LambdaQueryWrapper<>();
        wrapper.like(true,TRole::getName,name).eq(TRole::getDelFlag,false);
        //执行查询
        Page<TRole> result = roleMapper.selectPage(page, wrapper);
        return PageDTO.create(result,src->msRoleMapper.troleToRoleDto(src));
    }
}
