package com.zeroone.star.portfolioitems.service.impl;

import com.alibaba.cloud.commons.lang.StringUtils;
import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.zeroone.star.portfolioitems.entity.TPortfolioProject;
import com.zeroone.star.portfolioitems.mapper.TPortfolioProjectMapper;
import com.zeroone.star.portfolioitems.service.ITPortfolioProjectService;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.j4.dto.PortfolioItemDTO;
import com.zeroone.star.project.j4.dto.PortfolioItemListDTO;
import com.zeroone.star.project.j4.query.PortfolioItemListQuery;
import com.zeroone.star.project.j4.query.Query;
import org.mapstruct.Mapper;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;

@Mapper(componentModel = "spring")
interface MsTPortfolioProjectStruct {
    PortfolioItemDTO pDoToTDto(TPortfolioProject tPortfolioProject);

    PortfolioItemListDTO pDosToTDtos(TPortfolioProject tPortfolioProject);
}

/**
 * <p>
 * 组合项目 服务实现类
 * </p>
 *
 * @author Laputa
 * @since 2024-01-24
 */
@Service
public class TPortfolioProjectServiceImpl extends ServiceImpl<TPortfolioProjectMapper, TPortfolioProject> implements ITPortfolioProjectService {
    @Resource
    private MsTPortfolioProjectStruct msTPortfolioProjectStruct;

    @Override
    public PortfolioItemDTO getPortfolioItemById(String id) throws Exception {
        TPortfolioProject tPortfolioProject = baseMapper.selectById(id);
        if (tPortfolioProject != null) {
            return msTPortfolioProjectStruct.pDoToTDto(tPortfolioProject);
        }
        return null;
    }

    @Override
    public PageDTO<PortfolioItemListDTO> listPortfolioItems(PortfolioItemListQuery query) throws Exception {
        Page<TPortfolioProject> tPortfolioProjectPage = new Page<>(query.getPageIndex(), query.getPageSize());
        QueryWrapper<TPortfolioProject> wrapper = new QueryWrapper<>();

        // 判断是否需要添加条件
        // 如果字段为空，不需要加条件
        if (StringUtils.isNotBlank(query.getName())) {
            wrapper.like("name", query.getName());
        }

        if (StringUtils.isNotBlank(query.getShortName())) {
            wrapper.like("short_name", query.getShortName());
        }
        Page<TPortfolioProject> result = baseMapper.selectPage(tPortfolioProjectPage, wrapper);
        return PageDTO.create(result, src -> msTPortfolioProjectStruct.pDosToTDtos(src));
    }
}
