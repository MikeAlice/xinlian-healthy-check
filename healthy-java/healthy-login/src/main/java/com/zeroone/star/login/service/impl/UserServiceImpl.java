package com.zeroone.star.login.service.impl;

import com.zeroone.star.login.mapper.RoleMapper;
import com.zeroone.star.login.mapper.UserMapper;
import com.zeroone.star.login.service.UserService;
import com.zeroone.star.project.vo.login.LoginVO;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;
import java.util.List;

@Service
public class UserServiceImpl implements UserService {

    @Resource
    UserMapper userMapper;

    @Resource
    RoleMapper roleMapper;
    /**
     * 获取当前用户
     * @param id
     * @return
     */
    @Override
    public LoginVO getUserById(Long id) {
        LoginVO loginVO = userMapper.selectUserById(id);
        List<String> roles = roleMapper.selectUserRoles(id);
        loginVO.setRoles(roles);
        return loginVO;
    }
}
