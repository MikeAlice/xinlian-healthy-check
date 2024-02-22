package com.zeroone.star.sectionoffice.service;


import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.j4.dto.GetSecNameDTO;
import com.zeroone.star.project.j4.dto.GetSectionOfficetDTO;
import com.zeroone.star.project.j4.query.GetSectionOfficeQuery;
import com.zeroone.star.project.j4.query.SectionOfficeDetailQuery;
import com.zeroone.star.project.j4.vo.GetSecNameVO;
import com.zeroone.star.project.j4.vo.GetSectionOfficeVO;
import com.zeroone.star.sectionoffice.entity.SectionOfficeEntity;

import java.util.List;


/**
 * (SectionOffice)表服务接口
 *
 * @author makejava
 * @since 2024-01-17 21:52:31
 */

public interface SectionOfficeService extends IService<SectionOfficeEntity> {


    /**
     * 分页查询符合条件数据
     * @param getSectionOfficeQuery
     * @return
     */
    PageDTO<GetSectionOfficeVO> listAllSectionOffice(GetSectionOfficeQuery getSectionOfficeQuery);

    /**
     * 获取名称列表
     * @param getSecNameDTO
     * @return
     */
    PageDTO<GetSecNameVO> listAllName(GetSecNameDTO getSecNameDTO);


    /**
     *     获取科室详情
     */
    GetSectionOfficeVO getAllSectionOffice(SectionOfficeDetailQuery query);
}
