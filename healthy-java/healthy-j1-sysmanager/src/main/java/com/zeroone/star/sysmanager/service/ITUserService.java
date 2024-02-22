package com.zeroone.star.sysmanager.service;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.j1.dto.percenter.CreateUserDTO;
import com.zeroone.star.project.j1.dto.sysmanager.ModifyUserDTO;
import com.zeroone.star.project.j1.dto.sysmanager.UserDTO;
import com.zeroone.star.project.j1.query.sysmanager.UserListQuery;
import com.zeroone.star.project.j1.vo.sysmanager.UserNameListVO;
import com.zeroone.star.sysmanager.entity.TUser;
import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.sysmanager.entity.User;

import java.util.List;

/**
 * <p>
 * 用户 服务类
 * </p>
 *
 * @author 阿布
 * @since 2024-01-23
 */
public interface ITUserService extends IService<TUser> {

    /**
     * 获取用户名称列表（用于输入表单下拉列表框）
     * @return
     */
    List<UserNameListVO> listUsernameList();

	/**
	 * 修改用户
	 * @return
	 */
	void modifyUser(ModifyUserDTO user);

	/**
	 * 新增用户
	 * @param user
	 */
	void saveUser(CreateUserDTO user);

	/**
	 * 批量删除用户
	 * @param ids
	 */
    void removeUserList(List<Long> ids);

	/**
	 * 获取用户列表
	 * @param userListQuery
	 * @return
	 */
    PageDTO<UserDTO> listUserList(UserListQuery userListQuery);

	/**
	 * 获取全部用户数据，用于导出数据
	 * @return
	 */
    List<User> listAll();
}
