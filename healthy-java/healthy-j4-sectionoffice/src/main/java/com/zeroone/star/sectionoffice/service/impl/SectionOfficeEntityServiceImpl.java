package com.zeroone.star.sectionoffice.service.impl;

import cn.hutool.core.bean.BeanUtil;
import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.j4.dto.GetSecNameDTO;
import com.zeroone.star.project.j4.query.GetSectionOfficeQuery;
import com.zeroone.star.project.j4.query.SectionOfficeDetailQuery;
import com.zeroone.star.project.j4.vo.GetSecNameVO;
import com.zeroone.star.project.j4.vo.GetSectionOfficeVO;
import com.zeroone.star.sectionoffice.entity.SectionOfficeEntity;
import com.zeroone.star.sectionoffice.mapper.GetSectionOfficeMapper;
import com.zeroone.star.sectionoffice.service.SectionOfficeService;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;
import java.util.ArrayList;
import java.util.List;

@Service
public class SectionOfficeEntityServiceImpl extends ServiceImpl<GetSectionOfficeMapper, SectionOfficeEntity> implements SectionOfficeService {
    @Resource
    private GetSectionOfficeMapper getSectionOfficeMapper;

    /**
     * 获取科室管理列表（分页+条件）
     * @param query
     * @return GetSectionOfficeVO
     */
    @Override
    public PageDTO<GetSectionOfficeVO> listAllSectionOffice(GetSectionOfficeQuery query){

        QueryWrapper<SectionOfficeEntity> queryWrapper = new QueryWrapper<>();
        queryWrapper.eq("del_flag",0);

        if (query.getSectionCode() != null) {
            queryWrapper.like("section_code",query.getSectionCode());
        }
        if (query.getSectionName() != null) {
            queryWrapper.like("section_name",query.getSectionName());
        }
        if (query.getSectionAlphbet() != null) {
            queryWrapper.like("section_alphbet",query.getSectionAlphbet());
        }
        if (query.getCheckType() != null) {
            queryWrapper.like("check_type",query.getCheckType());
        }

        Page<SectionOfficeEntity> page = new Page<>(query.getPageIndex(),query.getPageSize());
        Page result = baseMapper.selectPage(page, queryWrapper);
        List records = result.getRecords();
        List list = new ArrayList<>();
        records.forEach(item->{
            GetSectionOfficeVO vo = new GetSectionOfficeVO();
            BeanUtil.copyProperties(item,vo);
            list.add(vo);
        });

        return PageDTO.create(result);


    }

    /**
     * 获取科室管理名称列表
     * @param getSecNameDTO
     * @return GetSecNameVO
     */
    @Override
    public PageDTO<GetSecNameVO> listAllName(GetSecNameDTO getSecNameDTO) {

        QueryWrapper<SectionOfficeEntity> queryWrapper = new QueryWrapper<>();
        queryWrapper.eq("del_flag",0);
        if (getSecNameDTO.getSectionName() != null) {
            queryWrapper.like("section_name",getSecNameDTO.getSectionName());
        }
        if (getSecNameDTO.getSectionCode() != null) {
            queryWrapper.eq("section_code",getSecNameDTO.getSectionCode());
        }
        if (getSecNameDTO.getId() != null) {
            queryWrapper.eq("id",getSecNameDTO.getId());
        }
        if (getSecNameDTO.getSectionAlphbet() != null) {
            queryWrapper.like("section_alphbet",getSecNameDTO.getSectionAlphbet());
        }


        Page<SectionOfficeEntity> page = new Page<>(getSecNameDTO.getPageIndex(),getSecNameDTO.getPageSize());
        Page result = baseMapper.selectPage(page, queryWrapper);
        List records = result.getRecords();
        List list = new ArrayList<>();
        records.forEach(item->{
            GetSecNameVO vo = new GetSecNameVO();
            BeanUtil.copyProperties(item,vo);
            list.add(vo);
        });
        //携带分页的情况下
        if(getSecNameDTO.getPageIndex() != 0 && getSecNameDTO.getPageSize() != 0) {
            result.setRecords(list);
        }else{
            //不带分页 查询全部
            QueryWrapper<SectionOfficeEntity> queryWrapper1 = new QueryWrapper<>();
            queryWrapper1.eq("del_flag",0);
            result.setRecords(baseMapper.selectList(queryWrapper1));
        }
        return PageDTO.create(result);
    }

    /**
     * 获取详情
     * @param query
     * @return
     */

    @Override
    public GetSectionOfficeVO getAllSectionOffice(SectionOfficeDetailQuery query) {
        QueryWrapper<SectionOfficeEntity> queryWrapper = new QueryWrapper<>();
        queryWrapper.eq("del_flag",0);
        if(query.getSectionCode() != null){
            queryWrapper.eq("section_code",query.getSectionCode());
        }
        if(query.getId() != null){
            queryWrapper.eq("id",String.valueOf(query.getId()));
        }
        SectionOfficeEntity sectionOfficeEntity = baseMapper.selectOne(queryWrapper);
        GetSectionOfficeVO result  = new GetSectionOfficeVO();
        BeanUtil.copyProperties(sectionOfficeEntity,result);
        return result;
    }


}
