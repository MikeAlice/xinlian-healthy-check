package com.zeroone.star.project.j4.termanagement;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.j4.dto.TermDTO;
import com.zeroone.star.project.j4.dto.TermDetailDto;
import com.zeroone.star.project.j4.query.TermNameQuery;
import com.zeroone.star.project.j4.query.TermQuery;
import com.zeroone.star.project.j4.vo.TermDetailVo;
import com.zeroone.star.project.j4.vo.TermNameVo;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.ResultStatus;
import org.springframework.validation.annotation.Validated;

/**
 * @BelongsProject: healthy-java
 * @BelongsPackage: com.zeroone.star.project.j4.tofficeterm
 * @Author: ayuan & 刘静
 * @CreateTime: 2024-01-28
 * @Description:
 */
public interface TermApis {
    /**
     * @Author: ayuan
     * @param: [termDTO]
     * @return: com.zeroone.star.project.vo.JsonVO<com.zeroone.star.project.vo.ResultStatus>
     * @Description: 更新术语
     **/
    JsonVO<ResultStatus> modifyOfficeTerm(@Validated TermDTO termDTO);
    /**
     * 术语列表查询接口
     *
     * @param condition 查询条件
     * @return 查询结果
     */
    /**
     * 术语列表查询接口
     * @param condition 查询条件
     * @return 查询结果
     */
    JsonVO<PageDTO<TermDTO>> queryTermListAll(TermQuery condition) ;

    JsonVO<PageDTO<TermNameVo>> queryTermnameList(TermNameQuery condition1) ;

    JsonVO<TermDetailVo> queryTermDetail(String id);

    JsonVO<Boolean> addTerm(TermDetailDto termDetailDto) throws Exception;
}
