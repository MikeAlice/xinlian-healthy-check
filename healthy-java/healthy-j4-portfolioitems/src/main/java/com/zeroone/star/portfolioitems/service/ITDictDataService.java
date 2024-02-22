package com.zeroone.star.portfolioitems.service;

import com.zeroone.star.portfolioitems.entity.TDictData;
import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.j4.vo.ProjectNameListVO;

import java.util.List;

/**
 * <p>
 * 字典数据 服务类
 * </p>
 *
 * @author ;jiemo
 * @since 2024-01-29
 */
public interface ITDictDataService extends IService<TDictData> {

    /**
     * 获取项目名称
     * @return 查询结果
     */
    List<ProjectNameListVO> ListProjectName();
}
