package com.zeroone.star.login.mapper;

import com.zeroone.star.login.entity.Menu;
import com.zeroone.star.login.entity.TPermission;
import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import org.apache.ibatis.annotations.Mapper;
import org.apache.poi.ss.formula.functions.T;

import java.util.List;

/**
 * <p>
 * 资源（菜单/操作权限） Mapper 接口
 * </p>
 *
 * @author 阿布
 * @since 2024-01-24
 */
@Mapper
public interface TPermissionMapper extends BaseMapper<TPermission> {

    /**
     * 通过角色名获取对应的菜单资源
     * @param roleName 角色名
     * @return 返回菜单列表
     */
    List<TPermission> selectByRoleName(String roleName);
}
