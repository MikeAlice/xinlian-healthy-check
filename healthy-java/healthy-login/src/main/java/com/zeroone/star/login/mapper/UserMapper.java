package com.zeroone.star.login.mapper;

import com.zeroone.star.project.vo.login.LoginVO;
import org.apache.ibatis.annotations.Mapper;

@Mapper
public interface UserMapper {
    LoginVO selectUserById(Long id);
}
