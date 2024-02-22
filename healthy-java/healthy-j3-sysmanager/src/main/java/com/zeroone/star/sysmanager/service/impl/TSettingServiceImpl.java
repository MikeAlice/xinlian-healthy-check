package com.zeroone.star.sysmanager.service.impl;


import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.core.conditions.update.UpdateWrapper;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.project.components.user.UserDTO;
import com.zeroone.star.project.components.user.UserHolder;
import com.zeroone.star.project.dto.j3.system.SystemNoticeDTO;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j3.sysConfig.TSettingVO;
import com.zeroone.star.sysmanager.entity.TSetting;
import com.zeroone.star.sysmanager.mapper.TSettingMapper;
import com.zeroone.star.sysmanager.service.ITSettingService;
import org.mapstruct.Mapper;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import org.springframework.web.bind.annotation.RequestBody;

import javax.annotation.Resource;
import java.time.LocalDateTime;
import java.time.LocalTime;
import java.util.Calendar;
import java.util.Date;

/**
 * <p>
 * 系统配置（系统公告、其他自定义配置） 服务实现类
 * </p>
 *
 * @author car
 * @since 2024-01-24
 */
@Mapper(componentModel = "spring")
interface MySetting{

    /**
     * @Author car
     * @Description //TODO 将dto转化为do
     * @Date 13:53 2024/1/29
     * @Param [com.zeroone.star.project.dto.j3.system.SystemNoticeDTO]
     * @return com.zeroone.star.sysmanager.entity.TSetting
     **/
    TSetting tSetting(SystemNoticeDTO systemNoticeDTO);
}

@Service
public class TSettingServiceImpl extends ServiceImpl<TSettingMapper, TSetting> implements ITSettingService {

    @Autowired
    private TSettingMapper settingMapper;
    @Autowired
    private MySetting mySetting;
    @Resource
    private UserHolder userHolder;
    @Override
    public JsonVO<SystemNoticeDTO> addSystemNotice(SystemNoticeDTO systemNoticeDTO) throws Exception {
        //获得当前用户
        systemNoticeDTO.setCreateBy(userHolder.getCurrentUser().getUsername());
        //设置插入时间
        Calendar calendar = Calendar.getInstance();
        Date date = calendar.getTime();
        systemNoticeDTO.setCreateTime(date);
        //设置删除标记
        systemNoticeDTO.setDelFlag(false);
        //转化对象
        TSetting tSetting = mySetting.tSetting(systemNoticeDTO);
        //插入行数
        int insert = settingMapper.insert(tSetting);
        //判断插入成功与否
        JsonVO<SystemNoticeDTO> jsonVO = new JsonVO<>();
        if (insert > 0){
            jsonVO.setMessage("新增成功");
            jsonVO.setData(systemNoticeDTO);
        }else {
            jsonVO.setMessage("新增失败");
        }
        return jsonVO;
    }

    @Override
    public JsonVO<SystemNoticeDTO> modifySystemNotice(SystemNoticeDTO systemNoticeDTO) throws Exception {
        //查找del_flag为0 也就是还没删除的
        QueryWrapper<TSetting> wrapper = new QueryWrapper<>();
        wrapper.eq("del_flag",false);
        TSetting tSetting = settingMapper.selectOne(wrapper);
        tSetting.setDelFlag(true);
        //更新时间
        LocalDateTime date = LocalDateTime.now();
        tSetting.setUpdateTime(date);
        //获得更新人
        systemNoticeDTO.setCreateBy(userHolder.getCurrentUser().getUsername());
        //标记上一个数据已经删除 更新
        settingMapper.updateById(tSetting);
        //插入新公告
        return addSystemNotice(systemNoticeDTO);
    }

    @Override
    public JsonVO<TSettingVO> querySystemNotice() {
        QueryWrapper<TSetting> wrapper = new QueryWrapper<>();
        wrapper.eq("del_flag",false);
        TSetting tSetting = settingMapper.selectOne(wrapper);
        TSettingVO tSettingVO = new TSettingVO();
        tSettingVO.setValue(tSetting.getValue());
        JsonVO<TSettingVO> vo = new JsonVO<>();
        vo.setData(tSettingVO);
        vo.setMessage("查询成功");
        return vo;
    }


}
