package com.zeroone.star.message.controller;


import com.zeroone.star.message.entity.TMessageSend;
import com.zeroone.star.message.service.ITMessageSendService;
import com.zeroone.star.message.service.ITMessageService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.j2.MessageSendApis;
import com.zeroone.star.project.j2.dto.MessageSendDTO;
import com.zeroone.star.project.j2.dto.MessageSendUnReadDTO;
import com.zeroone.star.project.j2.dto.MessageSendUpdateDTO;
import com.zeroone.star.project.j2.query.MessageSendQuery;
import com.zeroone.star.project.j2.query.MessageSendUnReadQuery;
import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;

import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.RestController;

import javax.annotation.Resource;

/**
 * <p>
 * 消息发送 前端控制器
 * </p>
 *
 * @author camille
 * @since 2024-01-15
 */
@RestController
@Api(tags = "消息详情")
@RequestMapping("/message/t-message-send")
public class TMessageSendControllerSend implements MessageSendApis {

    @Resource
    ITMessageSendService itMessageSendService;
    @ApiOperation("查询未读消息")
    @GetMapping("MessageSendUnRead")
    @Override
    public JsonVO<MessageSendUnReadDTO> queryMessageSendUnRead(MessageSendUnReadQuery messageSendUnReadQuery) {
        return null;
    }


    @ApiOperation("获取消息详情")
    @GetMapping("MessageSendQuery")
    @Override
    public JsonVO<MessageSendDTO> queryMessageSend(@RequestParam String id) {
        return JsonVO.success(itMessageSendService.listAllMessage(id));
    }

    @Override
    @ApiOperation("修改消息状态")
    @GetMapping("updateMessageSend")
    public JsonVO<Integer> updateMessageSend(@RequestParam String id,@RequestParam String status) {

        return JsonVO.success(itMessageSendService.updateMessage(id,status));
    }
}

