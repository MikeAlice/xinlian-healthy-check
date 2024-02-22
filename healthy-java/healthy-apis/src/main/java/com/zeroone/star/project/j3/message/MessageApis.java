package com.zeroone.star.project.j3.message;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j3.message.MessageResponseDTO;
import com.zeroone.star.project.dto.j3.message.MessageSendDTO;
import com.zeroone.star.project.dto.j3.message.MsgListDTO;
import com.zeroone.star.project.query.j3.msgGetAndSendAndUpate.MsgListQuery;
import com.zeroone.star.project.query.j3.msgGetAndSendAndUpate.SendMsgQuery;
import com.zeroone.star.project.query.j3.msgGetAndSendAndUpate.UpdateMsgQuery;
import com.zeroone.star.project.vo.JsonVO;
import java.util.ArrayList;
import java.util.List;

/**
 * @description:消息管理Api
 * @author: 坚强少年
 * @date: 2024/1/15 20:36
 **/
public interface MessageApis {
    /**@description:批量删除/撤回接口
     * @author: 坚强少年
     * @date: 2024/1/15 21:51
     * @param: [id]
     * @return: com.zeroone.star.project.vo.JsonVO<java.lang.Boolean>
     **/
    JsonVO<Boolean> deleteByIds(List<String> ids);

    /**
     * @description:获取消息详情页。
     * @author: 坚强少年
     * @date: 2024/1/15 21:54
     * @param: [id]
     * @return: com.zeroone.star.project.vo.JsonVO<com.zeroone.star.project.j3.dto.MessageDTO>
     **/
    JsonVO<PageDTO<MessageResponseDTO>> selectMessageDetailPage(MessageSendDTO messageSend);

    /**
     * 消息列表查询接口
     * @param msgListQuery：查询条件
     * @return 查询结果
     */
    JsonVO<PageDTO<MsgListDTO>> queryMessageList(MsgListQuery msgListQuery);


    /**
     *  发送消息
     * @param sendMsgQuery
     * @return
     */
    JsonVO<Boolean> querySendMessage(SendMsgQuery sendMsgQuery) throws Exception;

    /**
     * 更新消息
     * @param updateMsgQuery
     * @return
     */
    JsonVO<Boolean> updateMessage(UpdateMsgQuery updateMsgQuery) throws Exception;
}
