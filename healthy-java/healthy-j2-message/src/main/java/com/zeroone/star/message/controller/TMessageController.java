package com.zeroone.star.message.controller;


import cn.hutool.core.bean.BeanUtil;
import com.zeroone.star.message.entity.TMessage;
import com.zeroone.star.message.mapper.TMessageMapper;
import com.zeroone.star.message.mapper.TMessageSendMapper;
import com.zeroone.star.message.service.ITMessageService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.j2.MessageApis;
import com.zeroone.star.project.j2.dto.MessageDTO;
import com.zeroone.star.project.j2.query.MessageQuery;
import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;

import javax.annotation.Resource;
import javax.validation.constraints.NotBlank;
import java.util.Arrays;
import java.util.Date;
import java.util.List;

/**
 * <p>
 * 消息 前端控制器
 * </p>
 *
 * @author camille
 * @since 2024-01-15
 */
@RestController
@Api(tags = "消息")
@RequestMapping("/message/t-message")
public class TMessageController implements MessageApis {
    @Resource
    ITMessageService itMessageService;




    @ApiOperation("获取消息列表")
    @GetMapping("MessageQueryAll")
    @Override
    public JsonVO<PageDTO<MessageDTO>> queryMessageAll(MessageQuery messageQuery) {
        return JsonVO.success(itMessageService.listPage(messageQuery));
    }

    @ApiOperation(value = "删除消息")
    @DeleteMapping("remove-by-ids")
    @Override
    public JsonVO<Object> removeMessage(@RequestParam String[] ids) {
        if (ids == null || Arrays.stream(ids).anyMatch(id -> id == null || id.trim().isEmpty())) {
            throw new IllegalArgumentException("ids数组中元素不能为空或空字符串");
        }
        //删除消息
        itMessageService.removeMessage(ids);
        return JsonVO.success(null);
    }

    @ApiOperation(value = "获取系统公告")
    @GetMapping("query-by-id")
    @Override
    public JsonVO<MessageDTO> queryMessage(@NotBlank(message = "id不能为空")
                                               @RequestParam String id) {
        //查询消息
        TMessage message = itMessageService.getById(id);
        //判断是否查询成功
        if(message == null){
            JsonVO<MessageDTO> vo = JsonVO.fail(null);
            vo.setMessage("该消息不存在");
            return vo;
        }
        //类型转换
        MessageDTO messageDTO = new MessageDTO();
        BeanUtil.copyProperties(message, messageDTO);
        return JsonVO.success(messageDTO);
    }



}

