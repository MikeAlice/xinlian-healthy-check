package com.zeroone.star.message.service;

import com.zeroone.star.message.entity.TMessage;
import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.j2.dto.MessageDTO;
import com.zeroone.star.project.j2.dto.MessageSendUnReadDTO;
import com.zeroone.star.project.j2.query.MessageQuery;
import com.zeroone.star.project.j2.query.MessageSendUnReadQuery;

/**
 * <p>
 * 消息 服务类
 * </p>
 *
 * @author camille
 * @since 2024-01-15
 */
public interface ITMessageService extends IService<TMessage> {
    //分页查询所有数据
    PageDTO<MessageDTO> listPage(MessageQuery messageQuery);

    //删除消息
    void removeMessage(String[] ids);

}
