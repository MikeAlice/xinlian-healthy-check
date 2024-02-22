package com.zeroone.star.TemplateManagement.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.TemplateManagement.entity.TTemplate;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.j4.templateM.dto.ProjectDTO;
import com.zeroone.star.project.j4.templateM.dto.TemplateMListDTO;
import com.zeroone.star.project.j4.templateM.query.TemplateMQuery;

import java.util.List;

/**
 * <p>
 * 描述：模板服务类
 * </p>
 *
 * @author Triple Gold
 * @version 1.0.0
 */
public interface ITemplateMService extends IService<TTemplate> {
    /**
     * 查询组合项目名称列表
     * @return 查询结果
     */
    ProjectDTO listProjectList();

    /**
     * 查询模板列表
     * @param query 查询条件
     * @return 查询结果
     */
    PageDTO<TemplateMListDTO> listTemplateList(TemplateMQuery query);

    /**
     * 修改模板状态
     *
     * @param id 模板编号
     * @return 修改结果
     */
    String updateTemplateStatus(String id);

    /**
     * 查询模板文件存放地址
     * @param id 模板编号
     * @return 模板文件名
     */
    String getTemplate(String id);
}
