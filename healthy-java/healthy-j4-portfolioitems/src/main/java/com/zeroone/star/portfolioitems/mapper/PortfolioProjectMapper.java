package com.zeroone.star.portfolioitems.mapper;

import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.portfolioitems.entity.TPortfolioProject;
import com.zeroone.star.project.j4.dto.TPortfolioProjectDTO;
import org.apache.ibatis.annotations.Select;
/**
 * @author rakkaus
 */
public interface PortfolioProjectMapper  extends BaseMapper<TPortfolioProject> {
    @Select("SELECT office_id FROM t_portfolio_project WHERE office_name = #{office_name}")
    String selectByOfficeName(String office_name);
}
