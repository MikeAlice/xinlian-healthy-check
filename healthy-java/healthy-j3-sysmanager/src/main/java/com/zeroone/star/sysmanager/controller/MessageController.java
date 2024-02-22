package com.zeroone.star.sysmanager.controller;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j3.message.MessageResponseDTO;
import com.zeroone.star.project.dto.j3.message.MessageSendDTO;
import com.zeroone.star.project.dto.j3.message.MsgListDTO;
import com.zeroone.star.project.j3.message.MessageApis;
import com.zeroone.star.project.query.j3.msgGetAndSendAndUpate.MsgListQuery;
import com.zeroone.star.project.query.j3.msgGetAndSendAndUpate.SendMsgQuery;
import com.zeroone.star.project.query.j3.msgGetAndSendAndUpate.UpdateMsgQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.sysmanager.service.ITMessageService;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.web.bind.annotation.*;
import javax.annotation.Resource;
import java.util.ArrayList;
import java.util.List;


/**
 * 消息管理Controller
 *
 * @author ZhangJF
 * @date 2024/01/15 21:57
 **/
@RestController
@RequestMapping("/sysconfig-message")
@Api("消息管理")
public class MessageController implements MessageApis {
    @Resource
    private ITMessageService messageService;

    @ApiOperation("删除撤回消息")
    @DeleteMapping("/deleteByIds")
    @Override
    public JsonVO<Boolean> deleteByIds(@RequestParam List<String> ids) {
        boolean success = messageService.removeByIds(ids);
        if (success) {
            return JsonVO.success(success);
        }
        return JsonVO.fail(success);
    }

    @ApiOperation("获取指定消息发送详情列表")
    @GetMapping("/queryMessageDetail")
    @Override
    public JsonVO<PageDTO<MessageResponseDTO>> selectMessageDetailPage(MessageSendDTO messageSend) {
        return messageService.getJsonVO(messageSend);
    }

    @ApiOperation("获取消息列表")
    @GetMapping("/queryMsgList")
    @Override
    public JsonVO<PageDTO<MsgListDTO>> queryMessageList(MsgListQuery msgListQuery) {
        PageDTO<MsgListDTO> data = messageService.queryMessageList(msgListQuery);
        return JsonVO.success(data);
    }

    @ApiOperation("发送消息")
    @PostMapping("/sendMessage")
    @Override
    public JsonVO<Boolean> querySendMessage(SendMsgQuery sendMsgQuery) throws Exception {
        JsonVO<Boolean> booleanJsonVO = messageService.sendMsg(sendMsgQuery);

        return booleanJsonVO;
    }

    @ApiOperation("修改消息")
    @PutMapping("/updateMessage")
    @Override
    public JsonVO<Boolean> updateMessage(UpdateMsgQuery updateMsgQuery) throws Exception {
        JsonVO<Boolean> booleanJsonVO = messageService.updateMsg(updateMsgQuery);

        return booleanJsonVO;
    }

}
