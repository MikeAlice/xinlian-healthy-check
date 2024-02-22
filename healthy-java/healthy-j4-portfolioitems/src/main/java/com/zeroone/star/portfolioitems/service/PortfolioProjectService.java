package com.zeroone.star.portfolioitems.service;

import com.zeroone.star.project.j4.dto.TPortfolioProjectDTO;
import com.zeroone.star.project.vo.JsonVO;

import java.util.List;
/**
 * @author rakkaus
 */
public interface PortfolioProjectService {
    JsonVO save(TPortfolioProjectDTO TPortfolioProjectDTO);

    JsonVO delete(List<String> ids);

    JsonVO updateById(TPortfolioProjectDTO tPortfolioProjectDTO);
}
