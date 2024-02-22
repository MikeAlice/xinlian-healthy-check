package com.zeroone.star.sysmanager.service.impl;

import cn.hutool.core.bean.BeanUtil;
import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.zeroone.star.project.components.user.UserDTO;
import com.zeroone.star.project.components.user.UserHolder;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.j1.dto.percenter.CreateUserDTO;
import com.zeroone.star.project.j1.dto.sysmanager.ModifyUserDTO;
import com.zeroone.star.project.j1.query.sysmanager.UserListQuery;
import com.zeroone.star.project.j1.vo.sysmanager.UserNameListVO;
import com.zeroone.star.project.vo.ResultStatus;
import com.zeroone.star.sysmanager.entity.TUser;
import com.zeroone.star.sysmanager.entity.TUserRole;
import com.zeroone.star.sysmanager.entity.User;
import com.zeroone.star.sysmanager.mapper.DepartmentMapper;
import com.zeroone.star.sysmanager.mapper.RoleMapper;
import com.zeroone.star.sysmanager.mapper.TUserMapper;
import com.zeroone.star.sysmanager.mapper.UserRoleMapper;
import com.zeroone.star.sysmanager.service.ITUserService;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import org.mapstruct.Mapper;
import org.springframework.security.crypto.password.PasswordEncoder;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;

import javax.annotation.Resource;
import java.time.LocalDateTime;
import java.util.ArrayList;
import java.util.List;

/**
 * User对应的MapStruct映射接口
 */
@Mapper(componentModel = "spring")
interface MsUserMapper{
    /**
     * 将 TUser 转成 UserNameListVO
     * @param user 待转换的DO
     * @return 转换结果
     */
    UserNameListVO userToUserNameListVO(TUser user);

    /**
     * 将 CreateUserDTO 转换成 TUser
     * @param createUserDTO 待转换的DTO
     * @return 转换结果
     */
    TUser CreateUserDTOToTUser(CreateUserDTO createUserDTO);

    /**
     * 将 TUser 转换成 UserDTO
     * @param tUser 待转换的DTO
     * @return 转换结果
     */
    com.zeroone.star.project.j1.dto.sysmanager.UserDTO TUserToUserDTO(TUser tUser);

    /**
     * 将 ModifyUserDTO 转换成 TUser
     * @param modifyUserDTO 待转换的DTO
     * @return 转换结果
     */
    TUser ModifyUserDTOToTUser(ModifyUserDTO modifyUserDTO);

    /**
     * 将 TUser 转换成 User
     * @param tUser 待转换的DTO
     * @return 转换结果
     */
    User TUserToUser(TUser tUser);
}
/**
 * <p>
 * 用户 服务实现类
 * </p>
 *
 * @author 阿布
 * @since 2024-01-23
 */
@Service
public class TUserServiceImpl extends ServiceImpl<TUserMapper, TUser> implements ITUserService {

    @Resource
    private MsUserMapper msUserMapper;

    @Resource
    private PasswordEncoder passwordEncoder;

    /**
     * t_user表相关的Mapper
     */
    @Resource
    private TUserMapper tUserMapper;

    @Resource
    private UserHolder userHolder;

    @Resource
    private DepartmentMapper departmentMapper;

    @Resource
    private UserRoleMapper userRoleMapper;

    @Resource
    private RoleMapper roleMapper;

    /**
     * 获取用户名称列表（用于输入表单下拉列表框）
     * @return
     */
    @Override
    public List<UserNameListVO> listUsernameList() {
        QueryWrapper<TUser> wrapper = new QueryWrapper<>();
        List<TUser> users = tUserMapper.selectList(wrapper);
        List<UserNameListVO> list = new ArrayList<>();
        if (BeanUtil.isNotEmpty(users) && users.size() > 0) {
            for (TUser user : users) {
                if (user.getStatus() == 0 && !user.getDelFlag()) {
                    UserNameListVO userNameListVO = msUserMapper.userToUserNameListVO(user);
                    list.add(userNameListVO);
                }
            }
        }
        return list;
    }

    /**
     * 修改用户
     * @param user
     */
	@Override
	public void modifyUser(ModifyUserDTO user) {
        TUser userByToken = getUserByToken();
        if (userByToken.getType() == 0) {
            throw new RuntimeException("用户权限不足");
        }
        TUser selectById = tUserMapper.selectById(user.getId());
        if (selectById.getDelFlag()) {
            throw new RuntimeException("该用户已被删除");
        }
        TUser tUser = msUserMapper.ModifyUserDTOToTUser(user);
        if (tUser.getDepartmentId() != 0) {
            String departmentTitle = departmentMapper.selectTitleById(tUser.getDepartmentId());
            tUser.setDepartmentTitle(departmentTitle);
        }
        tUser.setUpdateTime(LocalDateTime.now());
        tUser.setUpdateBy(userByToken.getUsername());
        tUserMapper.updateUser(tUser);
        // 修改用户角色
        List<String> roles = user.getRoles();
        List<TUserRole> tUserRoles = new ArrayList<>();
        if (BeanUtil.isNotEmpty(roles) && roles.size() > 0) {
            for (String role : roles) {
                TUserRole tUserRole = new TUserRole();
                Long roleId = roleMapper.selectRoleIdByName(role);
                tUserRole.setCreateBy(userByToken.getUsername());
                tUserRole.setCreateTime(LocalDateTime.now());
                tUserRole.setDelFlag(true);
                tUserRole.setUpdateBy(userByToken.getUsername());
                tUserRole.setUpdateTime(LocalDateTime.now());
                tUserRole.setRoleId(roleId);
                tUserRole.setUserId(tUser.getId());
                tUserRoles.add(tUserRole);
            }
            userRoleMapper.insert(tUserRoles);
        }
    }

    /**
     * 新增用户
     * @param createUserDTO
     */
    @Override
    @Transactional
    public void saveUser(CreateUserDTO createUserDTO) {
        // 获取当前用户信息
        TUser tUser = getUserByToken();
        if (tUser.getType() != 1) {
            throw new RuntimeException("用户权限不足");
        }

        // 将DTO转换成TUser实体
        TUser user = msUserMapper.CreateUserDTOToTUser(createUserDTO);
        user.setPassword(passwordEncoder.encode(user.getPassword()));
        // 设置新增、修改的时间和修改人
        user.setCreateBy(tUser.getUsername());
        user.setUpdateBy(tUser.getUsername());
        user.setCreateTime(LocalDateTime.now());
        user.setUpdateTime(LocalDateTime.now());
        // 设置逻辑删除标记为未删除(0)
        user.setDelFlag(false);
        // 获取部门名称
        String departmentTitle = departmentMapper.selectTitleById(tUser.getDepartmentId());
        user.setDepartmentTitle(departmentTitle);
        // 设置账号状态为启用(0)
        user.setStatus(0);
        // 新增用户
        save(user);

        // 为新账号添加角色
        List<Long> roleIds = createUserDTO.getRoleIds();
        if (BeanUtil.isNotEmpty(roleIds) && roleIds.size() > 0) {
            List<TUserRole> list = new ArrayList<>();
            for (Long roleId : roleIds) {
                TUserRole tUserRole = new TUserRole();
                tUserRole.setCreateBy(tUser.getUsername());
                tUserRole.setCreateTime(LocalDateTime.now());
                tUserRole.setDelFlag(false);
                tUserRole.setUpdateBy(tUser.getUsername());
                tUserRole.setUpdateTime(LocalDateTime.now());
                tUserRole.setRoleId(roleId);
                tUserRole.setUserId(user.getId());
                list.add(tUserRole);
            }
            userRoleMapper.insert(list);
        }
    }

    /**
     * 批量删除用户
     * @param ids
     */
    @Override
    public void removeUserList(List<Long> ids) {
        TUser userByToken = getUserByToken();
        if (userByToken.getType() != 1) {
            throw new RuntimeException("用户权限不足");
        }
        List<TUser> tUserList = tUserMapper.selectBatchIds(ids);
        if (BeanUtil.isEmpty(tUserList) || tUserList.size() == 0) {
            throw new RuntimeException("未找到相关用户");
        }
        for (TUser user : tUserList) {
            if (user.getDelFlag()) {
                ids.remove(user.getId());
            }
        }
        tUserMapper.deleteUserByIds(ids, LocalDateTime.now(), userByToken.getUsername());
    }

    @Override
    public PageDTO<com.zeroone.star.project.j1.dto.sysmanager.UserDTO> listUserList(UserListQuery userListQuery) {
        // 构建分页对象
        Page<TUser> page = new Page<>(userListQuery.getPageIndex(), userListQuery.getPageSize());
        // 构建查询条件
        QueryWrapper<TUser> wrapper = new QueryWrapper<>();
        if (userListQuery.getNickname() != null) {
            wrapper.like("nickname", userListQuery.getNickname());
        }
        if (userListQuery.getDepartmentTitle() != null) {
            wrapper.like("department_title", userListQuery.getDepartmentTitle());
        }
        if (userListQuery.getMobile() != null) {
            wrapper.like("mobile", userListQuery.getMobile());
        }
        if (userListQuery.getEmail() != null) {
            wrapper.like("email", userListQuery.getEmail());
        }
        if (userListQuery.getSex() != null) {
            wrapper.like("sex", userListQuery.getSex());
        }
        if (userListQuery.getUsername() != null) {
            wrapper.like("userName", userListQuery.getUsername());
        }
        if (userListQuery.getId() != null) {
            wrapper.like("id", userListQuery.getId());
        }
        if (userListQuery.getCreateTime() != null) {
            wrapper.like("create_time", userListQuery.getCreateTime());
        }
        // 执行查询
        Page<TUser> result = baseMapper.selectPage(page, wrapper);
        return PageDTO.create(result, src -> msUserMapper.TUserToUserDTO(src));
    }

    /**
     * 获取全部数据，用于导出
     * @return
     */
    @Override
    public List<User> listAll() {
        QueryWrapper<TUser> wrapper = new QueryWrapper<>();
        List<TUser> list = tUserMapper.selectList(wrapper);
        List<User> userList = new ArrayList<>();
        for (TUser user : list) {
            User toUser = msUserMapper.TUserToUser(user);
            userList.add(toUser);
        }
        return userList;
    }

    /**
     * 从userHolder中获取用户信息
     * @return
     */
    public TUser getUserByToken() {
        UserDTO currentUser = null;
        try {
            currentUser = userHolder.getCurrentUser();
        } catch (Exception e) {
            throw new RuntimeException(ResultStatus.UNAUTHORIZED.getMessage());
        }
        Long userId = currentUser.getId();
        TUser user = tUserMapper.selectById(userId);
        if (user == null || user.getDelFlag()) {
            throw new RuntimeException("用户不存在");
        }
        if (user.getStatus() == 1) {
            throw new RuntimeException("用户处于禁用状态");
        }
        return user;
    }


}
