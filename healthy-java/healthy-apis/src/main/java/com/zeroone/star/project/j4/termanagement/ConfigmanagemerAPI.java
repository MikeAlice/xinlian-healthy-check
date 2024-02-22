package com.zeroone.star.project.j4.termanagement;

import com.zeroone.star.project.j4.vo.SectionNameListVO;
import com.zeroone.star.project.vo.JsonVO;

import java.util.List;

/**
 * @author: jiemo
 * @date: 2024/1/31 14:45
 * @description: 配置管理API
 */
public interface ConfigmanagemerAPI {
    /**
     * 科室名称接口
     * @return 科室名称
     */
    JsonVO<List<SectionNameListVO>> querySectionName();

}
