package com.zeroone.star.sysmanager.service.impl;


import com.baomidou.mybatisplus.core.conditions.query.LambdaQueryWrapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j3.message.MessageResponseDTO;
import com.zeroone.star.project.dto.j3.message.MsgListDTO;
import com.zeroone.star.project.query.j3.msgGetAndSendAndUpate.MsgListQuery;
import com.zeroone.star.project.query.j3.msgGetAndSendAndUpate.SendMsgQuery;
import com.zeroone.star.project.query.j3.msgGetAndSendAndUpate.UpdateMsgQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.sysmanager.entity.MessageSend;
import com.zeroone.star.sysmanager.mapper.MessageSendMapper;
import com.zeroone.star.sysmanager.service.ITMessageSendService;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;

/**
 * <p>
 * 消息发送 服务实现类
 * </p>
 *
 * @author 坚强少年
 * @since 2024-01-16
 */
@Service
public class TMessageSendServiceImpl extends ServiceImpl<MessageSendMapper, MessageSend> implements ITMessageSendService {
}
