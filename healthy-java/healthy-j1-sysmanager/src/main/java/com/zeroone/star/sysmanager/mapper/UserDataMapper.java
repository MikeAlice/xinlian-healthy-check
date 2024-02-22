package com.zeroone.star.sysmanager.mapper;

import com.zeroone.star.project.j1.dto.percenter.entity.TUser;
import org.apache.ibatis.annotations.Insert;
import org.apache.ibatis.annotations.Mapper;

import java.util.List;

@Mapper
public interface UserDataMapper {

    void createUser(TUser user);


    void deleteUserList(List<String> ids);
}
