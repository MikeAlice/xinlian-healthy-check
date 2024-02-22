package com.zeroone.star.sysmanager.mapper;


import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.project.dto.j3.system.SystemNoticeDTO;
import com.zeroone.star.sysmanager.entity.TSetting;
import org.apache.ibatis.annotations.Mapper;
import org.mapstruct.factory.Mappers;

/**
 * <p>
 * 系统配置（系统公告、其他自定义配置） Mapper 接口
 * </p>
 *
 * @author car
 * @since 2024-01-24
 */
@Mapper
public interface TSettingMapper extends BaseMapper<TSetting> {


}
