package com.zeroone.star.sysmanager.service;

import com.zeroone.star.project.j1.dto.sysmanager.ModifyPasswordDTO;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.sysmanager.entity.TUser;
import com.baomidou.mybatisplus.extension.service.IService;

import java.util.List;

/**
 * <p>
 * 用户 服务类
 * </p>
 *
 * @author light
 * @since 2024-01-18
 */
public interface UserPasswordService extends IService<TUser> {
    JsonVO updatePasswordToChange(ModifyPasswordDTO modifyPasswordDTO);

    JsonVO updatePasswordToReset(List<String> ids);
}
