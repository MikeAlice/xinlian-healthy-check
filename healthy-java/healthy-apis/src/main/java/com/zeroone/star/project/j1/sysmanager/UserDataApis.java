package com.zeroone.star.project.j1.sysmanager;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.j1.dto.percenter.CreateUserDTO;
import com.zeroone.star.project.j1.dto.sysmanager.ModifyUserDTO;
import com.zeroone.star.project.j1.dto.sysmanager.UserDTO;
import com.zeroone.star.project.j1.query.sysmanager.UserListQuery;
import com.zeroone.star.project.j1.vo.sysmanager.UserDataVO;
import com.zeroone.star.project.j1.vo.sysmanager.UserNameListVO;
import com.zeroone.star.project.vo.JsonVO;

import java.util.List;

/**
 * 系统管理-用户管理，获取、修改、删除用户信息、状态相关接口
 */
public interface UserDataApis {
	/**
	 * 获取用户名称列表（用于输入表单下拉列表框）
	 * @return
	 */
    JsonVO<List<UserNameListVO>> queryUserNameList();

	/**
	 * 获取用户列表（条件 + 分页）
	 * @param userListQuery
	 * @return
	 */
	JsonVO<PageDTO<UserDTO>> queryUserList(UserListQuery userListQuery);

	/**
	 * 设置用户状态
	 *
	 * @param id
	 * @param status 需要改成的状态
	 * @return
	 */
    JsonVO setUserStatus(Long id,Integer status);

	/**
	 * 获取用户详情
	 * @param id 用户id
	 * @return
	 */
    JsonVO<UserDataVO> queryUserData(Long id);

	/**
	 * 修改用户信息
	 * @param user 用户实体
	 * @return
	 */
	JsonVO modifyUser(ModifyUserDTO user);

	/**
	 * 新增用户
	 * @param user 用户实体
	 * @return
	 */
	JsonVO addUser(CreateUserDTO user);

	/**
	 * 批量删除用户
	 * @param ids 用户id
	 * @return
	 */
	JsonVO deleteUserList(List<String> ids);

}
