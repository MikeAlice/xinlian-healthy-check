package com.zeroone.star.login.service.impl;

import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.login.entity.Menu;
import com.zeroone.star.login.entity.TPermission;
import com.zeroone.star.login.mapper.MenuMapper;
import com.zeroone.star.login.mapper.TPermissionMapper;
import com.zeroone.star.login.service.IMenuService;
import com.zeroone.star.project.utils.tree.TreeNode;
import com.zeroone.star.project.utils.tree.TreeNodeMapper;
import com.zeroone.star.project.utils.tree.TreeUtils;
import com.zeroone.star.project.vo.login.MenuTreeVO;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;
import java.util.ArrayList;
import java.util.List;

/**
 * <p>
 * 描述：定义一个Menu数据到MenuTreeNode的属性映射配器
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author 阿伟学长
 * @version 1.0.0
 */
class MenuTreeNodMapper implements TreeNodeMapper<TPermission> {
    @Override
    public TreeNode objectMapper(TPermission menu) {
        MenuTreeVO treeNode = new MenuTreeVO();
        // 首先设置TreeNode计算层数使用属性
        treeNode.setTnId(menu.getId().toString());
        if (menu.getParentId() == null) {
            treeNode.setTnPid(null);
        } else {
            treeNode.setTnPid(menu.getParentId().toString());
        }
        // 设置扩展属性
        treeNode.setId(menu.getId().intValue());
        treeNode.setIcon(menu.getIcon());
        treeNode.setText(menu.getName());
        treeNode.setHref(menu.getPath());
        if (menu.getParentId() != null) {
            treeNode.setPid(menu.getParentId().intValue());
        }
        return treeNode;
    }
}

/**
 * <p>
 * 菜单 服务实现类
 * </p>
 * @author 阿伟
 */
@Service
public class MenuServiceImpl extends ServiceImpl<MenuMapper, Menu> implements IMenuService {

    @Resource
    private TPermissionMapper permissionMapper;

    @Override
    public List<MenuTreeVO> listMenuByRoleName(List<String> roleNames) {
        //1 定义一个存储数据库查询菜单数据的容器
        List<TPermission> permissions = new ArrayList<>();
        //2 遍历获取角色获取所有的菜单列表
        roleNames.forEach(roleName -> {
            //通过角色名获取菜单列表
            List<TPermission> tPermissions = permissionMapper.selectByRoleName(roleName);
            if (tPermissions != null && !tPermissions.isEmpty()) {
                permissions.addAll(tPermissions);
            }
        });
        //3 转换树形结构并返回
        MenuTreeNodMapper menuTreeNodMapper = new MenuTreeNodMapper();
        return TreeUtils.listToTree(permissions, menuTreeNodMapper);
    }
}
