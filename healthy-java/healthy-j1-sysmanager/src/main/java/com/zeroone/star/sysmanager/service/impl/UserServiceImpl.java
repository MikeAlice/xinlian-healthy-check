package com.zeroone.star.sysmanager.service.impl;

import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.project.components.user.UserDTO;
import com.zeroone.star.project.components.user.UserHolder;
import com.zeroone.star.project.j1.vo.sysmanager.UserDataVO;
import com.zeroone.star.project.j1.vo.sysmanager.entiy.Role;
import com.zeroone.star.project.vo.ResultStatus;
import com.zeroone.star.sysmanager.entity.TUser;
import com.zeroone.star.sysmanager.mapper.RoleMapper;
import com.zeroone.star.sysmanager.mapper.UserMapper;
import com.zeroone.star.sysmanager.service.UserService;
import org.springframework.beans.BeanUtils;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;
import java.time.LocalDateTime;
import java.util.List;

@Service
public class UserServiceImpl implements UserService {
    @Autowired
    private UserMapper userMapper;

    @Autowired
    private RoleMapper roleMapper;

    @Resource
    private UserHolder userHolder;
    @Override
    public void setUserStatus(Long id, Integer status) {
        TUser user = getUserByToken();
        TUser tUser = userMapper.selectById(id);
        if (tUser == null) {
            throw new RuntimeException("用户不存在");
        }
        if (status == null) {
            throw new RuntimeException("状态不能为空");
        }
        userMapper.updateUserStatus(id, status, LocalDateTime.now(), user.getUsername());
    }

    @Override
    public UserDataVO getUserData(Long id) {
        TUser tUser = userMapper.selectById(id);
        if (tUser == null) {
            throw new RuntimeException("用户不存在");
        }
        UserDataVO userDataVO = new UserDataVO();
        BeanUtils.copyProperties(tUser,userDataVO);
        List<Role> rolelist = roleMapper.selectRoleByUserId(id);
        userDataVO.setRoleList(rolelist);
        return userDataVO;
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
        TUser user = userMapper.selectById(userId);
        if (user == null || user.getDelFlag()) {
            throw new RuntimeException("用户不存在");
        }
        if (user.getStatus() == 1) {
            throw new RuntimeException("用户处于禁用状态");
        }
        return user;
    }

}
