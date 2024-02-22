package com.zeroone.star.message.mapper;

import com.zeroone.star.message.entity.TMessageSend;
import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.j2.dto.MessageSendUnReadDTO;
import com.zeroone.star.project.j2.query.MessageSendUnReadQuery;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Select;

/**
 * <p>
 * 消息发送 Mapper 接口
 * </p>
 *
 * @author camille
 * @since 2024-01-15
 */
@Mapper
public interface TMessageSendMapper extends BaseMapper<TMessageSend> {

    @Select("select t_message.content from  t_message,t_message_send \n" +
            "where t_message_send.message_id=t_message.id \n" +
            "AND t_message_send.`status`=0\n" +
            "ORDER BY t_message_send.create_time\n" +
            "desc")
    MessageSendUnReadDTO selectUnRead();
}
