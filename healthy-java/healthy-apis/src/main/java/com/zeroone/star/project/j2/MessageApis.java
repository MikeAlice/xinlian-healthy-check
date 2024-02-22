package com.zeroone.star.project.j2;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.j2.dto.MessageDTO;
import com.zeroone.star.project.j2.query.MessageQuery;
import com.zeroone.star.project.vo.JsonVO;

public interface MessageApis {

    //获取消息列表
    JsonVO<PageDTO<MessageDTO>> queryMessageAll(MessageQuery messageQuery);

    //删除消息
    JsonVO<Object> removeMessage(String[] ids);


    //获取系统公告
    JsonVO<MessageDTO> queryMessage(String id);
}
