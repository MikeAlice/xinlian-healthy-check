package com.zeroone.star.portfolioitems.service.impl;

import cn.hutool.core.bean.BeanUtil;
import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.zeroone.star.portfolioitems.entity.TSectionOffice;
import com.zeroone.star.portfolioitems.mapper.TSectionOfficeMapper;
import com.zeroone.star.portfolioitems.service.ITSectionOfficeService;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.j4.vo.SectionNameListVO;
import org.springframework.stereotype.Service;

import java.util.ArrayList;
import java.util.List;

/**
 * <p>
 * 科室 服务实现类
 * </p>
 *
 * @author ;jiemo
 * @since 2024-01-29
 */
@Service
public class TSectionOfficeServiceImpl extends ServiceImpl<TSectionOfficeMapper, TSectionOffice> implements ITSectionOfficeService {

    @Override
    public List<SectionNameListVO> listSectionName() {
        QueryWrapper<TSectionOffice> queryWrapper = new QueryWrapper<>();
        queryWrapper.eq("del_flag",0);
        List<TSectionOffice> baseList = baseMapper.selectList(queryWrapper);
        List<SectionNameListVO> res = new ArrayList<>();
        baseList.forEach(item->{
            SectionNameListVO vo = new SectionNameListVO();
            BeanUtil.copyProperties(item,vo);
            res.add(vo);
        });
        return res;
    }
}
