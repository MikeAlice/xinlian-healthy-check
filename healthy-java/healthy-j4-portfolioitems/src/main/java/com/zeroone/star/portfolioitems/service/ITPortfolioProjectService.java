package com.zeroone.star.portfolioitems.service;

import com.zeroone.star.portfolioitems.entity.TPortfolioProject;
import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.j4.dto.PortfolioItemDTO;
import com.zeroone.star.project.j4.dto.PortfolioItemListDTO;
import com.zeroone.star.project.j4.query.PortfolioItemListQuery;

/**
 * <p>
 * 组合项目 服务类
 * </p>
 *
 * @author Laputa
 * @since 2024-01-24
 */
public interface ITPortfolioProjectService extends IService<TPortfolioProject> {
    PortfolioItemDTO getPortfolioItemById(String id) throws Exception;

    PageDTO<PortfolioItemListDTO> listPortfolioItems(PortfolioItemListQuery query) throws Exception;
}
