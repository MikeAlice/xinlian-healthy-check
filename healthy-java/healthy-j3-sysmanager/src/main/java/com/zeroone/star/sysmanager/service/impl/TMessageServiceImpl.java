package com.zeroone.star.sysmanager.service.impl;


import cn.hutool.core.util.StrUtil;
import cn.hutool.json.JSONConfig;
import cn.hutool.json.JSONUtil;
import com.baomidou.mybatisplus.core.conditions.query.LambdaQueryWrapper;
import com.baomidou.mybatisplus.core.conditions.update.LambdaUpdateWrapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.zeroone.star.project.components.user.UserDTO;
import com.zeroone.star.project.components.user.UserHolder;
import com.zeroone.star.project.constant.RedisConstant;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j3.message.MessageResponseDTO;
import com.zeroone.star.project.dto.j3.message.MessageSendDTO;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.dto.j3.message.MsgListDTO;
import com.zeroone.star.project.query.j3.msgGetAndSendAndUpate.MsgListQuery;
import com.zeroone.star.project.query.j3.msgGetAndSendAndUpate.SendMsgQuery;
import com.zeroone.star.project.query.j3.msgGetAndSendAndUpate.UpdateMsgQuery;
import com.zeroone.star.sysmanager.entity.Message;
import com.zeroone.star.sysmanager.entity.MessageSend;
import com.zeroone.star.sysmanager.mapper.MessageMapper;
import com.zeroone.star.sysmanager.mapper.MessageSendMapper;
import com.zeroone.star.sysmanager.service.ITMessageService;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import org.springframework.data.redis.core.StringRedisTemplate;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;
import java.time.LocalDateTime;
import java.util.concurrent.TimeUnit;

/**
 * <p>
 * 消息 服务实现类
 * </p>
 *
 * @author 坚强少年
 * @since 2024-01-16
 */
@Service
public class TMessageServiceImpl extends ServiceImpl<MessageMapper, Message> implements ITMessageService {

    @Resource
    private MessageSendMapper messageSendMapper;

    @Resource
    private StringRedisTemplate stringRedisTemplate;

    @Resource
    private UserHolder userHolder;
    /**
     * @description:消息详情业务
     * @author: 坚强少年
     * @date: 2024/1/17 17:05
     * @param: [detailDTO]
     * @return: com.zeroone.star.project.dto.PageDTO<com.zeroone.star.project.dto.j3.message.MessageDTO>
     **/
    @Override
    public PageDTO<MessageResponseDTO> selectMessageDetailPage(MessageSendDTO messageSend) {
        Page page = new Page(messageSend.getPageIndex(),messageSend.getPageSize());
        LambdaQueryWrapper<MessageSend> wrapper = new LambdaQueryWrapper<>();
        if (messageSend.getUserId() != null){
            wrapper.eq(MessageSend::getUserId,messageSend.getUserId());
        }
        page = messageSendMapper.selectPage(page, wrapper);
        PageDTO<MessageResponseDTO> message = PageDTO.create(page);
        return message;
    }

    @Resource
    private MessageMapper messageMapper;
    @Override
    public PageDTO<MsgListDTO> queryMessageList(MsgListQuery msgListQuery) {
        //构建分页条件对象
        Page page = new Page(msgListQuery.getPageIndex(),msgListQuery.getPageSize());

        //查询条件
        LambdaQueryWrapper<Message> wrapper = new LambdaQueryWrapper<>();
        if (msgListQuery.getMsgTitle()!= null){
            wrapper.eq(Message::getTitle,msgListQuery.getMsgTitle());
        }
        if (msgListQuery.getMsgType() != null ) {
            wrapper.eq(Message::getType,msgListQuery.getMsgType());
        }
        if (msgListQuery.getMsgContent() != null) {
            wrapper.like(Message::getContent,msgListQuery.getMsgContent());
        }
        if (msgListQuery.getCreateTime()!= null) {
            wrapper.like(Message::getCreateTime,msgListQuery.getCreateTime());
        }
        //执行查询
        Page result = messageMapper.selectPage(page, wrapper);

        //PageDTO.create() 可以将分页插件的page对象转换成当前pageDto对象
        PageDTO<MsgListDTO> message = PageDTO.create(result);
        return message;
    }


    @Override
    public JsonVO<Boolean> sendMsg(SendMsgQuery sendMsgQuery) throws Exception {
        Message message = new Message();
        UserDTO currentUser = userHolder.getCurrentUser();

        message.setTitle(sendMsgQuery.getId());

        message.setCreateBy(currentUser.getUsername());

//        DateTimeFormatter formatter = DateTimeFormatter.ofPattern("yyyy-MM-dd HH:mm:ss");
//        LocalDateTime localDateTime = LocalDateTime.parse(sendMsgQuery.getCreateTime(), formatter);
//        message.setCreateTime(localDateTime);

//        message.setCreateTime(sendMsgQuery.getCreateTime());
        message.setCreateTime(LocalDateTime.now());
        message.setType(sendMsgQuery.getType());
        message.setTitle(sendMsgQuery.getTitle());
        message.setContent(sendMsgQuery.getContent());
        message.setCreateSend(sendMsgQuery.getCreateSend());
        //执行修改
        boolean success = messageMapper.insert(message) > 0;
        if (success) {
            return JsonVO.success(success);
        }
        return JsonVO.fail(success);
    }



    @Override
    public JsonVO<Boolean> updateMsg(UpdateMsgQuery updateMsgQuery) throws Exception {
        //获取元消息
        Message message = messageMapper.selectById(updateMsgQuery.getId());

        /**
         * 根据userHolder  token根据ID获取元消息
         */
        UserDTO currentUser = userHolder.getCurrentUser();

        Message messageUpdate = new Message();
        messageUpdate.setId(updateMsgQuery.getId());
        messageUpdate.setUpdateBy(currentUser.getUsername());
        messageUpdate.setUpdateTime(LocalDateTime.now());
        messageUpdate.setType(updateMsgQuery.getType());
        messageUpdate.setTitle(updateMsgQuery.getTitle());
        messageUpdate.setContent(updateMsgQuery.getContent());
        messageUpdate.setCreateSend(updateMsgQuery.getCreateSend());
        //执行修改
        Boolean success = messageMapper.updateById(messageUpdate) > 0;
        if (success) {
            return JsonVO.success(success);
        }
        return JsonVO.fail(success);
    }
    public JsonVO getJsonVO(MessageSendDTO messageSend) {
        String key = RedisConstant.MESSAGE_DETAIL + ":" + messageSend.getMessageId();
        //1.从redis当中查询缓存
        String mesJson = stringRedisTemplate.opsForValue().get(key);
        //2.判断是否命中
        if (StrUtil.isNotBlank(mesJson)) {
            //3.命中直接返回
            PageDTO bean = JSONUtil.toBean(mesJson, PageDTO.class);
            return JsonVO.success(bean);
        }
        //4.不存在从数据库中读取消息详情页，写入redis
        PageDTO<MessageResponseDTO> data = selectMessageDetailPage(messageSend);
        //定义JSONConfig防止日期改为时间戳
        JSONConfig jsonConfig = new JSONConfig();
        jsonConfig.setDateFormat("yyyy-MM-dd");
        stringRedisTemplate.opsForValue().set(key,JSONUtil.toJsonStr(data,jsonConfig), 3, TimeUnit.MINUTES);
        return JsonVO.success(data);
    }
}
