package com.zeroone.star.project.j1.percenter;

import com.zeroone.star.project.j1.dto.percenter.ModifyPersonalInfoDTO;
import com.zeroone.star.project.vo.JsonVO;

/**
 * 个人中心-基本信息相关接口
 */
public interface BaseInfoApis {
    /**
     * 修改个人基础信息
     * @param modifyPersonalInfoDTO 可修改的个人基础信息
     * @return
     */
    JsonVO<String> modifyPersonalInfo(ModifyPersonalInfoDTO modifyPersonalInfoDTO) throws Exception;
}
