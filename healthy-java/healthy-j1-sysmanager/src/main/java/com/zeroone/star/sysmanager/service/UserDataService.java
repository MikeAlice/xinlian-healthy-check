package com.zeroone.star.sysmanager.service;

import com.zeroone.star.project.j1.dto.percenter.CreateUserDTO;
import com.zeroone.star.project.j1.dto.percenter.entity.TUser;
import com.zeroone.star.project.vo.JsonVO;
import org.springframework.context.annotation.Bean;
import org.springframework.stereotype.Service;

import java.util.List;

@Service
public interface UserDataService {

    //新增用户
    void createUser(TUser tUser) throws Exception;

    //删除用户
    JsonVO deleteUserList(List<String> ids);

}
