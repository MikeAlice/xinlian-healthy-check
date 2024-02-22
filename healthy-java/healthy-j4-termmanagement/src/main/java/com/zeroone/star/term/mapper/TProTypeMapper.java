package com.zeroone.star.term.mapper;

import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.term.entity.TProType;
import org.apache.ibatis.annotations.Mapper;

/**
 * <p>
 * 类型库（如：职业危害因素，经济类型、行业类别等等） Mapper 接口
 * </p>
 *
 * @author Laputa
 * @since 2024-01-30
 */
@Mapper
public interface TProTypeMapper extends BaseMapper<TProType> {

}
