package com.zeroone.star.message.service.impl;

import com.baomidou.mybatisplus.core.conditions.query.LambdaQueryWrapper;
import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.zeroone.star.message.entity.TMessage;
import com.zeroone.star.message.entity.TMessageSend;
import com.zeroone.star.message.mapper.TMessageMapper;
import com.zeroone.star.message.service.ITMessageSendService;
import com.zeroone.star.message.service.ITMessageService;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.j2.dto.MessageDTO;
import com.zeroone.star.project.j2.dto.MessageSendUnReadDTO;
import com.zeroone.star.project.j2.query.MessageQuery;
import com.zeroone.star.project.j2.query.MessageSendUnReadQuery;
import org.apache.logging.log4j.message.Message;
import org.mapstruct.Mapper;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;

import javax.annotation.Resource;

//Message对应MapStruct映射接口
@Mapper(componentModel = "spring")
interface MsMessageMapper{
    //将DO转换成DTO
    MessageDTO MessageToMessageDTO(TMessage tmessage);
}
/**
 * <p>
 * 消息 服务实现类
 * </p>
 *
 * @author camille
 * @since 2024-01-15
 */
@Service
public class TMessageServiceImpl extends ServiceImpl<TMessageMapper, TMessage> implements ITMessageService {

    @Resource
    MsMessageMapper msMessageMapper;
    @Override
    public PageDTO<MessageDTO> listPage(MessageQuery messageQuery) {
        //构建分页对象
        Page<TMessage> page = new Page<>(messageQuery.getPageIndex(),messageQuery.getPageSize());
        //构建查询条件
        QueryWrapper<TMessage> wrapper = new QueryWrapper<>();
        wrapper.like("title",messageQuery.getTitle())
                .or()
                .like("content",messageQuery.getContent())
                .or()
                .like("type",messageQuery.getType())
                .or()
                .like("create_time",messageQuery.getCreateTime());
        //执行查询
        Page<TMessage> result = baseMapper.selectPage(page,wrapper);
        return PageDTO.create(result, src -> msMessageMapper.MessageToMessageDTO(src));
    }


    @Resource
    private ITMessageSendService messageSendService;
    @Override
    @Transactional
    public void removeMessage(String[] ids) {
        for (String id : ids) {
            //在t_message表中删除
            removeById(id);
            //在t_message_send表中删除
            LambdaQueryWrapper<TMessageSend> wrapper = new LambdaQueryWrapper<>();
            wrapper.eq(TMessageSend::getMessageId,id);
            messageSendService.remove(wrapper);
        }
    }



}
