package com.zeroone.star.message.service;

import com.zeroone.star.message.entity.TMessageSend;
import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.j2.dto.MessageDTO;
import com.zeroone.star.project.j2.dto.MessageSendDTO;
import com.zeroone.star.project.j2.dto.MessageSendUnReadDTO;
import com.zeroone.star.project.j2.dto.MessageSendUpdateDTO;
import com.zeroone.star.project.j2.query.MessageQuery;
import com.zeroone.star.project.j2.query.MessageSendQuery;
import com.zeroone.star.project.j2.query.MessageSendUnReadQuery;
import com.zeroone.star.project.vo.JsonVO;

import java.util.List;

/**
 * <p>
 * 消息发送 服务类
 * </p>
 *
 * @author camille
 * @since 2024-01-15
 */
public interface ITMessageSendService extends IService<TMessageSend> {
  MessageSendDTO listAllMessage(String id);

 int updateMessage(String id,String status);



}
