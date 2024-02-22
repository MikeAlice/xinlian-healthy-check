package com.zeroone.star.project.j4.templateM;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.j4.templateM.dto.ProjectDTO;
import com.zeroone.star.project.j4.templateM.dto.TemplateMListDTO;
import com.zeroone.star.project.j4.templateM.query.TemplateMQuery;
import com.zeroone.star.project.vo.JsonVO;

import java.util.List;

/**
 * <p>
 * 描述：模板管理接口定义
 * </p>
 *
 * @author Triple Gold
 * @version 1.0.0
 */
public interface TemplateMApis {
    /**
     * 组合项目名称列表查询接口
     * @return 查询结果
     */
    JsonVO<ProjectDTO> queryProjectList();

    /**
     * 模板列表查询接口
     * @param query 查询条件
     * @return 查询结果
     */
    JsonVO<PageDTO<TemplateMListDTO>> queryTemplateList(TemplateMQuery query);

    /**
     * 启用/禁用模板
     * @param id 模板编号
     * @return 修改结果
     */
    JsonVO<String> modifyTemplateStatus(String id);

    /**
     * 预览模板
     * @param id 模板编号
     * @return 模板文件名
     */
    JsonVO<String> previewTemplate(String id);
}
