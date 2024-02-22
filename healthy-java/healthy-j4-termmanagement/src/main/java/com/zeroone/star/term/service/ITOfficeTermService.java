package com.zeroone.star.term.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.j4.dto.TermDTO;
import com.zeroone.star.project.j4.dto.TermDetailDto;
import com.zeroone.star.project.j4.query.SwitchTermQuery;
import com.zeroone.star.project.j4.query.TermNameQuery;
import com.zeroone.star.project.j4.query.TermQuery;
import com.zeroone.star.project.j4.vo.TermDetailVo;
import com.zeroone.star.project.j4.vo.TermNameVo;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.ResultStatus;
import com.zeroone.star.term.entity.TOfficeTerm;

public interface ITOfficeTermService extends IService<TOfficeTerm> {

    /**
     * 分页查询所有数据
     *
     * @param query 分页条件
     * @return 查询结果
     */
    PageDTO<TermDTO> queryTermList(TermQuery query);
    PageDTO<TermNameVo> queryTermnameList(TermNameQuery nameQuery);
    TermDetailVo queryTermDetail(String id);

    JsonVO<Boolean> addTerm(TermDetailDto termDetailDto) throws Exception;

    /**
     * @Author: ayuan
     * @param: [termDTO]
     * @return: com.zeroone.star.project.vo.JsonVO<com.zeroone.star.project.vo.ResultStatus>
     * @Description: 更新术语
     **/
    JsonVO<ResultStatus> updateOfficeTerm(TermDTO termDTO);

    Boolean switchTerm(SwitchTermQuery query) throws Exception;
}
