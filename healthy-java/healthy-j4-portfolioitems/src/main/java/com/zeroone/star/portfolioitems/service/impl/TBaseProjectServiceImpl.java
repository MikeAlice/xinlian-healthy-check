package com.zeroone.star.portfolioitems.service.impl;

import cn.hutool.core.bean.BeanUtil;
import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.zeroone.star.portfolioitems.entity.TBaseProject;
import com.zeroone.star.portfolioitems.mapper.TBaseProjectMapper;
import com.zeroone.star.portfolioitems.service.ITBaseProjectService;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.j4.query.BasePortfolioListQuery;
import com.zeroone.star.project.j4.vo.BasePortfolioListVO;
import org.springframework.stereotype.Service;

import java.util.ArrayList;
import java.util.List;

/**
 * <p>
 * 基础项目 服务实现类
 * </p>
 *
 * @author ;jiemo
 * @since 2024-01-29
 */
@Service
public class TBaseProjectServiceImpl extends ServiceImpl<TBaseProjectMapper, TBaseProject> implements ITBaseProjectService {

    @Override
    public PageDTO<BasePortfolioListVO> ListBaseProject(BasePortfolioListQuery query) {
        Page<TBaseProject> page = new Page<>(query.getPageIndex(),query.getPageSize());
        QueryWrapper<TBaseProject> queryWrapper = new QueryWrapper<>();
        queryWrapper.eq("del_flag", 0);
        if (query.getName() != null) {
            queryWrapper.like("name",query.getName());
        }
        if (query.getOfficeId() != null) {
            queryWrapper.like("office_id",query.getOfficeId());
        }
        Page result = baseMapper.selectPage(page, queryWrapper);

        List records = result.getRecords();
        List list = new ArrayList<>();
        records.forEach(item->{
            BasePortfolioListVO vo = new BasePortfolioListVO();
            BeanUtil.copyProperties(item,vo);
            list.add(vo);
        });
        result.setRecords(list);
        return PageDTO.create(result);
    }
}
