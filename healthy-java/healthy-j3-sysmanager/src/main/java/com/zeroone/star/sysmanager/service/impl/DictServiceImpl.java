package com.zeroone.star.sysmanager.service.impl;

import com.baomidou.mybatisplus.core.conditions.query.LambdaQueryWrapper;
import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j3.dictory.DictDTO;
import com.zeroone.star.project.query.j3.Dict.DictQuery;
import com.zeroone.star.sysmanager.mapper.DictMapper;
import com.zeroone.star.sysmanager.service.DictService;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import org.apache.catalina.LifecycleState;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.List;

/**
 * <p>
 * 字典 服务实现类
 * </p>
 *
 * @author Anemon
 * @since 2024-01-16
 */
@Service
public class DictServiceImpl extends ServiceImpl<DictMapper, com.zeroone.star.project.dto.j3.dictory.DictDTO> implements DictService {

    @Autowired
    private DictMapper dictMapper;
    @Override
    public List<DictDTO> findAllOrderBySortOrder() {
        LambdaQueryWrapper<DictDTO> wrapper = new LambdaQueryWrapper<>();
        wrapper.orderByAsc(DictDTO::getSortOrder);

        return dictMapper.selectList(wrapper);
    }

    @Override
    public DictDTO findByType(String type) {
        LambdaQueryWrapper<DictDTO> wrapper = new LambdaQueryWrapper<>();
        wrapper.eq(DictDTO::getType, type);
        DictDTO dictDTO = baseMapper.selectOne(wrapper);
        return dictDTO;
    }
}
