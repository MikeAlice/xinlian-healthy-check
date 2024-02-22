package com.zeroone.star.project.j3.sysconfig;

import com.zeroone.star.project.dto.j3.system.SystemNoticeDTO;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j3.sysConfig.TSettingVO;
import springfox.documentation.spring.web.json.Json;

/**
 * @description:系统配置Api
 * @author: 坚强少年
 * @date: 2024/1/15 20:36
 **/
public interface SysConfigApis {


    /**
     *@Description: 发布系统公告配置
     *@Author: Mr.Lin
     */
    JsonVO<SystemNoticeDTO> addSystemNotice(SystemNoticeDTO systemNoticeDTO) throws Exception;

    /**
     *@Description: 修改系统公告配置
     *@Author: Mr.Lin
     */
    JsonVO<SystemNoticeDTO> modifySystemNotice(SystemNoticeDTO systemNoticeDTO) throws Exception;

    /**
     *@Description: 获取当前系统公告配置
     *@Author: Mr.Lin
     */
    JsonVO<TSettingVO> querySystemNotice();
}
