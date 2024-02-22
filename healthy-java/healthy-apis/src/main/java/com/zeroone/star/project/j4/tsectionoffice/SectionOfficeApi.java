package com.zeroone.star.project.j4.tsectionoffice;

import cn.hutool.db.Page;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.j4.dto.GetSecNameDTO;
import com.zeroone.star.project.j4.dto.GetSectionOfficetDTO;
import com.zeroone.star.project.j4.query.GetSectionOfficeQuery;
import com.zeroone.star.project.j4.query.SectionOfficeDetailQuery;
import com.zeroone.star.project.j4.vo.GetSecNameVO;
import com.zeroone.star.project.j4.vo.GetSectionOfficeVO;
import com.zeroone.star.project.vo.JsonVO;

import java.util.List;

public interface SectionOfficeApi {
    /**
     * 根据条件查询科室列表(分页+条件)
     *
     * @param getSectionOfficeQuery 封装请求体参数
     * @return 封装的统一响应模型
     */

    JsonVO<PageDTO<GetSectionOfficeVO>> queryAllSectionOffice(GetSectionOfficeQuery getSectionOfficeQuery);

    JsonVO<PageDTO<GetSecNameVO>> GetAllSecName(GetSecNameDTO getSecNameDTO);

    JsonVO<GetSectionOfficeVO> GetAllSectionOffice(SectionOfficeDetailQuery query);
}
