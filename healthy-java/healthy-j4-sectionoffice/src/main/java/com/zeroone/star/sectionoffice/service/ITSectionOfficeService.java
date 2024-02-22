package com.zeroone.star.sectionoffice.service;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.j4.dto.GetSecNameDTO;
import com.zeroone.star.project.j4.dto.GetSectionOfficetDTO;
import com.zeroone.star.project.j4.dto.TSectionOfficeDTO;
import com.zeroone.star.project.j4.query.GetSectionOfficeQuery;
import com.zeroone.star.project.j4.vo.GetSecNameVO;
import com.zeroone.star.project.j4.vo.GetSectionOfficeVO;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.ResultStatus;
import com.zeroone.star.sectionoffice.entity.TSectionOffice;
import com.baomidou.mybatisplus.extension.service.IService;

import java.util.List;

/**
 * <p>
 *  服务类
 * </p>
 *
 * @author AYuan
 * @since 2024-01-16
 */
public interface ITSectionOfficeService extends IService<TSectionOffice> {

    /**
     * @Author: ayuan
     * @param: [tSectionOfficeDTO]
     * @return: void
     * @Description: 插入科室
     **/
    JsonVO<ResultStatus> saveSectionOffice(TSectionOfficeDTO tSectionOfficeDTO);

    /**
     * @Author: ayuan
     * @param: [tSectionOfficeDTO]
     * @return: void
     * @Description: 修改科室
     **/
    JsonVO<ResultStatus> updateSectionOffice(TSectionOfficeDTO tSectionOfficeDTO);

    /**
     * @Author: ayuan
     * @param: [ids]
     * @return: void
     * @Description: 删除科室
     **/
    JsonVO<ResultStatus> removeSectionOffice(List<String> ids);


}
