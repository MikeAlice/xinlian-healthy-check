package com.zeroone.star.sysmanager.mapper;

import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.sysmanager.entity.ProType;
import org.apache.ibatis.annotations.Mapper;

/**
 * <p>
 * 类型库（如：职业危害因素，经济类型、行业类别等等） Mapper 接口
 * </p>
 *
 * @author 坚强少年
 * @since 2024-01-16
 */
@Mapper
public interface ProTypeMapper extends BaseMapper<ProType> {

}
