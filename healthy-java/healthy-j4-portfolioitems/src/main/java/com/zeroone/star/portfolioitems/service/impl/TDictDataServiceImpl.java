package com.zeroone.star.portfolioitems.service.impl;

import com.zeroone.star.portfolioitems.entity.TDictData;
import com.zeroone.star.portfolioitems.mapper.TDictDataMapper;
import com.zeroone.star.portfolioitems.service.ITDictDataService;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.j4.vo.ProjectNameListVO;
import org.springframework.stereotype.Service;

import java.util.List;

/**
 * <p>
 * 字典数据 服务实现类
 * </p>
 *
 * @author ;jiemo
 * @since 2024-01-29
 */
@Service
public class TDictDataServiceImpl extends ServiceImpl<TDictDataMapper, TDictData> implements ITDictDataService {

    @Override
    public List<ProjectNameListVO> ListProjectName() {
        return baseMapper.listPorjectName();
    }
}
