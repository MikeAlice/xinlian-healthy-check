package com.zeroone.star.sysmanager.service;


import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j3.message.MessageResponseDTO;
import com.zeroone.star.project.dto.j3.message.MessageSendDTO;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.dto.j3.message.MsgListDTO;
import com.zeroone.star.project.query.j3.msgGetAndSendAndUpate.MsgListQuery;
import com.zeroone.star.project.query.j3.msgGetAndSendAndUpate.SendMsgQuery;
import com.zeroone.star.project.query.j3.msgGetAndSendAndUpate.UpdateMsgQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.sysmanager.entity.Message;

import java.util.List;

/**
 * <p>
 * 消息 服务类
 * </p>
 *
 * @author 坚强少年
 * @since 2024-01-16
 */
public interface ITMessageService extends IService<Message> {

    PageDTO<MessageResponseDTO> selectMessageDetailPage(MessageSendDTO messageSend);

    JsonVO<PageDTO<MessageResponseDTO>> getJsonVO(MessageSendDTO messageSend);

    //获取消息列表
    PageDTO<MsgListDTO> queryMessageList(MsgListQuery msgListQuery);

    /**
     * 发送消息
     * @param sendMsgQuery：请求体
     * @return boolean值
     */
    JsonVO<Boolean> sendMsg(SendMsgQuery sendMsgQuery) throws Exception;


    JsonVO<Boolean> updateMsg(UpdateMsgQuery updateMsgQuery) throws Exception;
}
