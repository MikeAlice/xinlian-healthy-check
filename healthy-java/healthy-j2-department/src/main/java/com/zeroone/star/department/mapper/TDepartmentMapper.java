package com.zeroone.star.department.mapper;

import com.zeroone.star.department.entity.TDepartment;
import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import org.apache.ibatis.annotations.Mapper;

import java.util.List;

/**
 * <p>
 * 部门 Mapper 接口
 * </p>
 *
 * @author camille
 * @since 2024-01-15
 */
@Mapper
public interface TDepartmentMapper extends BaseMapper<TDepartment> {

    /**
     * 通过父id返回子部门列表
     * @param parentId 父id
     * @return 列表
     */
    List<TDepartment> selectById(int parentId);
}
