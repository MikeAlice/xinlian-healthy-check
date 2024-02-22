package com.zeroone.star.project.j2;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.j2.dto.MessageSendDTO;
import com.zeroone.star.project.j2.dto.MessageSendUnReadDTO;
import com.zeroone.star.project.j2.dto.MessageSendUpdateDTO;
import com.zeroone.star.project.j2.query.MessageQuery;
import com.zeroone.star.project.j2.query.MessageSendQuery;
import com.zeroone.star.project.j2.query.MessageSendUnReadQuery;
import com.zeroone.star.project.vo.JsonVO;

public interface MessageSendApis {
    //获取最新未读消息列表
    JsonVO<MessageSendUnReadDTO> queryMessageSendUnRead(MessageSendUnReadQuery messageSendUnReadQuery);


    //获取消息详情
    JsonVO<MessageSendDTO> queryMessageSend(String id);

    //修改消息状态
    JsonVO<Integer>  updateMessageSend(String id,String status);


}
