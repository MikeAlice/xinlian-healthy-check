package com.zeroone.star.sysmanager.service;

import com.zeroone.star.project.j1.vo.sysmanager.UserDataVO;

public interface UserService {
    void setUserStatus(Long id, Integer status);

    UserDataVO getUserData(Long id);

}
