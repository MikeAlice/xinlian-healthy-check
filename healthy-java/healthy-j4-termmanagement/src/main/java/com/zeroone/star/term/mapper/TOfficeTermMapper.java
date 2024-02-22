package com.zeroone.star.term.mapper;

import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.zeroone.star.project.j4.dto.TermDTO;
import com.zeroone.star.project.j4.dto.TermNameDto;
import com.zeroone.star.project.j4.query.TermNameQuery;
import com.zeroone.star.project.j4.query.TermQuery;
import com.zeroone.star.project.j4.vo.TermDetailVo;
import com.zeroone.star.project.j4.vo.TermNameVo;
import com.zeroone.star.term.entity.TOfficeTerm;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Param;
import org.apache.ibatis.annotations.Select;


/**
 * @author 刘静
 * 时间：2024.1.1
 * 功能：
 */
@Mapper
public interface TOfficeTermMapper extends BaseMapper<TOfficeTerm> {
    @Select("SELECT t_section_office.section_name, t_office_term.inspect_type, t_office_term.type, t_office_term.hazard_factors_text, t_office_term.status,t_office_term.work_state_text, t_office_term.content, t_office_term.create_time " +
            "FROM t_section_office " +
            "JOIN t_office_term ON t_office_term.office_id = t_section_office.id")
    Page<TermDTO> selectAll(Page<TermDTO> page, @Param("query") TermQuery query);

    @Select("select hazard_factors_text,inspect_type,type,content from t_office_term")
    Page<TermNameVo> getTermName(Page<TermNameDto> page, @Param("query") TermNameQuery query);

    @Select("SELECT tso.section_name, tot.inspect_type, tot.type, tot.hazard_factors_text, tot.status, tot.work_state_text, tot.content, tot.order_num " +
            "FROM t_office_term AS tot " +
            "JOIN t_section_office AS tso ON tot.office_id = tso.id " +
            "WHERE tot.id = #{id}")
    TermDetailVo selectId(@Param("id") String id);


}
