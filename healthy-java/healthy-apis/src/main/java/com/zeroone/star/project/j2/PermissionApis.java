package com.zeroone.star.project.j2;

import com.zeroone.star.project.j2.dto.PermissionDTO;
import com.zeroone.star.project.vo.JsonVO;

import java.util.List;

/**
 * @author 滑溜溜
 * @version 1.0.0
 * @desc 菜单操作api
 * @since 2024-01-17
 */
public interface PermissionApis {
//JsonVO<PageDTO<MessageDTO>> queryMessage(MessageQuery messageQuery);

    public JsonVO<List<PermissionDTO>> getAllMenuList(); //获取用户页面菜单数据

    public JsonVO<List<PermissionDTO>> getAllList();  //获取权限菜单树

    public JsonVO<PermissionDTO> add(PermissionDTO permission);

    /**
     * @author 黑子的篮球
     */
    public JsonVO<List<PermissionDTO>> getResourcesNameTree(); //获取名称资源树

    public JsonVO<List<PermissionDTO>> getResourceList();  //搜索资源列表

}
