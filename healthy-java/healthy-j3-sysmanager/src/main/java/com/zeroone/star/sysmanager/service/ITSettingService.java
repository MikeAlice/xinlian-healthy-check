package com.zeroone.star.sysmanager.service;


import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.project.dto.j3.system.SystemNoticeDTO;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j3.sysConfig.TSettingVO;
import com.zeroone.star.sysmanager.entity.TSetting;
import org.springframework.web.bind.annotation.RequestBody;

import javax.validation.Valid;

/**
 * <p>
 * 系统配置（系统公告、其他自定义配置） 服务类
 * </p>
 *
 * @author car
 * @since 2024-01-24
 */
public interface ITSettingService extends IService<TSetting> {
    JsonVO<SystemNoticeDTO> addSystemNotice(SystemNoticeDTO systemNoticeDTO) throws Exception;

    JsonVO<SystemNoticeDTO> modifySystemNotice(@RequestBody @Valid SystemNoticeDTO systemNoticeDTO) throws Exception;

    JsonVO<TSettingVO> querySystemNotice();
}
