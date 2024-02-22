package com.zeroone.star.login.service;


import com.zeroone.star.project.vo.login.LoginVO;

public interface UserService {
    /**
     * 获取当前用户
     * @param id
     * @return
     */
    LoginVO getUserById(Long id);
}
