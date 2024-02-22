package com.zeroone.star.message.mapper;

import com.zeroone.star.message.entity.TMessage;
import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Select;

import java.util.ArrayList;
import java.util.List;

/**
 * <p>
 * 消息 Mapper 接口
 * </p>
 *
 * @author camille
 * @since 2024-01-15
 */
@Mapper
public interface TMessageMapper extends BaseMapper<TMessage> {

}
