package com.zeroone.star.project.j4.portfolioitems;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.j4.dto.PortfolioItemDTO;
import com.zeroone.star.project.j4.dto.PortfolioItemListDTO;
import com.zeroone.star.project.j4.query.PortfolioItemListQuery;
import com.zeroone.star.project.vo.JsonVO;

/**
 * @Description: TODO
 * @Author: Laputa
 * @CreateTime: 2024-01-24  16:57
 * @Version: 1.0
 */
public interface PortfolioProjectApi {
    /**
     * @description: 获取组合项目的详情信息
     * @author: Laputa
     * @date: 2024-01-24  16:57
     * @param:
     * @return:
     **/
    JsonVO<PortfolioItemDTO> queryPortfolioItem(String id) throws Exception;

    /**
     * @description: 获取组合项目列表 (条件+分页）
     * @author: Laputa
     * @date:  2023-01-24  17:17
     * @param:
     * @return:
     **/
    JsonVO<PageDTO<PortfolioItemListDTO>> queryPortfolioItemList(PortfolioItemListQuery query) throws Exception;
}
