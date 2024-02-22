package com.zeroone.star.sysmanager.service;


import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j3.message.MsgListDTO;
import com.zeroone.star.project.query.j3.msgGetAndSendAndUpate.MsgListQuery;
import com.zeroone.star.project.query.j3.msgGetAndSendAndUpate.SendMsgQuery;
import com.zeroone.star.project.query.j3.msgGetAndSendAndUpate.UpdateMsgQuery;
import com.zeroone.star.sysmanager.entity.MessageSend;

/**
 * <p>
 * 消息发送 服务类
 * </p>
 *
 * @author 坚强少年
 * @since 2024-01-16
 */
public interface ITMessageSendService extends IService<MessageSend> {

}
