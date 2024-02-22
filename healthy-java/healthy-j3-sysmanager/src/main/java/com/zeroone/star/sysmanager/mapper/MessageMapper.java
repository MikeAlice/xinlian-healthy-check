package com.zeroone.star.sysmanager.mapper;


import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.sysmanager.entity.Message;
import org.apache.ibatis.annotations.Mapper;


/**
 * <p>
 * 消息 Mapper 接口
 * </p>
 *
 * @author 坚强少年
 * @since 2024-01-16
 */
@Mapper
public interface MessageMapper extends BaseMapper<Message> {
}
