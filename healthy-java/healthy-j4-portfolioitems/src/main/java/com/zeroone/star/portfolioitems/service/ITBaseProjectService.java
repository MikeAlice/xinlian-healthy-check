package com.zeroone.star.portfolioitems.service;

import com.zeroone.star.portfolioitems.entity.TBaseProject;
import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.j4.query.BasePortfolioListQuery;
import com.zeroone.star.project.j4.vo.BasePortfolioListVO;

/**
 * <p>
 * 基础项目 服务类
 * </p>
 *
 * @author ;jiemo
 * @since 2024-01-29
 */
public interface ITBaseProjectService extends IService<TBaseProject> {
    /**
     * 分页获取基础项目名称
     * @param query 查询条件
     * @return  查询结果
     */
    PageDTO<BasePortfolioListVO> ListBaseProject(BasePortfolioListQuery query);
}
