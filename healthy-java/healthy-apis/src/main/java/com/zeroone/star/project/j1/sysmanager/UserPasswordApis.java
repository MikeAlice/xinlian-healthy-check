package com.zeroone.star.project.j1.sysmanager;

import com.zeroone.star.project.j1.dto.sysmanager.ModifyPasswordDTO;
import com.zeroone.star.project.vo.JsonVO;

import java.util.List;

/**
 * 系统管理-用户管理，用户密码相关接口（修改用户密码、重置用户密码）
 */
public interface UserPasswordApis {
    JsonVO modifyPasswordToChange(ModifyPasswordDTO modifyPasswordDTO);

    JsonVO modifyPasswordToReset(List<String> ids);


}
