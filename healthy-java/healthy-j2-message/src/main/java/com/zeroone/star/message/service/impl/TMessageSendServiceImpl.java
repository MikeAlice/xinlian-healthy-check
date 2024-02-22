package com.zeroone.star.message.service.impl;

import com.baomidou.mybatisplus.core.conditions.Wrapper;
import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.core.conditions.update.UpdateWrapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.zeroone.star.message.entity.TMessage;
import com.zeroone.star.message.entity.TMessageSend;
import com.zeroone.star.message.mapper.TMessageSendMapper;
import com.zeroone.star.message.service.ITMessageSendService;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.j2.dto.MessageDTO;
import com.zeroone.star.project.j2.dto.MessageSendDTO;
import com.zeroone.star.project.j2.dto.MessageSendUnReadDTO;
import com.zeroone.star.project.j2.dto.MessageSendUpdateDTO;
import com.zeroone.star.project.j2.query.MessageQuery;
import com.zeroone.star.project.j2.query.MessageSendQuery;
import com.zeroone.star.project.j2.query.MessageSendUnReadQuery;
import org.apache.poi.ss.formula.functions.T;
import org.mapstruct.Mapper;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;
import java.util.List;

/**
 * <p>
 * 消息发送 服务实现类
 * </p>
 *
 * @author camille
 * @since 2024-01-15
 */


@Mapper(componentModel = "spring")
interface MsMessageSendMapper{
    //将DO转换成DTO
    MessageSendDTO MessageToMessageDTO(TMessageSend tmessagesend);
}

@Mapper(componentModel = "spring")
interface MsMessageSendUnReadMapper{
    //将DO转换成DTO
    MessageSendUnReadDTO MessageUnReadToMessageUnReadDTO(TMessageSend tmessagesend);
}
@Service
public class TMessageSendServiceImpl extends ServiceImpl<TMessageSendMapper, TMessageSend> implements ITMessageSendService {

    @Resource
    MsMessageSendMapper msMessageSendMapper;
    MsMessageSendUnReadMapper msMessageSendUnReadMapper;
    TMessageSendMapper tMessageSendMapper;
    @Override
    public MessageSendDTO listAllMessage(String id) {

        TMessageSend tMessageSend = baseMapper.selectById(id);
        if (tMessageSend != null) {
            return msMessageSendMapper.MessageToMessageDTO(tMessageSend);
        }
        return null;
    }

    @Override
    public int updateMessage(String id,String status) {
        TMessageSend tMessageSend = new TMessageSend();
        UpdateWrapper<TMessageSend> wrapper = new UpdateWrapper<>();
        wrapper.eq("id",id)
                .set("status",status);
        int result = baseMapper.update(tMessageSend,wrapper);
        return result;
    }


}
