package com.zeroone.star.sysmanager.service.impl;

import com.zeroone.star.project.components.user.UserDTO;
import com.zeroone.star.project.components.user.UserHolder;
import com.zeroone.star.project.j1.dto.percenter.CreateUserDTO;
import com.zeroone.star.project.j1.dto.percenter.entity.TUser;
import com.zeroone.star.project.j1.vo.sysmanager.UserNameListVO;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.sysmanager.mapper.UserDataMapper;
import com.zeroone.star.sysmanager.service.UserDataService;
import org.mapstruct.Mapper;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;

import java.time.LocalDateTime;
import java.util.List;



@Service
public class UserDataServiceImpl implements UserDataService {


    @Autowired
    private UserDataMapper userDataMapper;



    @Override
    @Transactional
    public void createUser(TUser tUser) throws Exception {
        // TODO 测试未通过，待修改
        /*
        报错如下：
        "JSON parse error: Cannot deserialize value of type
        `java.time.LocalDateTime` from String \"2021/12/12\":
        Failed to deserialize java.time.LocalDateTime: (java.time.format.DateTimeParseException)
         Text '2021/12/12' could not be parsed at index 4;
         */

//        UserDTO currentUser = userHolder.getCurrentUser();
//        if (currentUser != null) {
//            // 设置创建人、修改人以及相应的时间
//            tUser.setCreateBy(currentUser.getUsername());
//            tUser.setUpdateBy(currentUser.getUsername());
//            tUser.setCreateTime(LocalDateTime.now());
//            tUser.setUpdateTime(LocalDateTime.now());
//        }
        // 调用Mapper插入用户
        userDataMapper.createUser(tUser);
    }

    @Override
    public JsonVO deleteUserList(List<String> ids) {
        // TODO 缺少对参数的合法性判断，参数不合法时缺少相应的提示
        userDataMapper.deleteUserList(ids);
        return null;
    }
}
