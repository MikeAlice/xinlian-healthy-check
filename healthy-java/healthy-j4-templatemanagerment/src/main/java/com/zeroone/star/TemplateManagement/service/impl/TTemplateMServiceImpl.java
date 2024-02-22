package com.zeroone.star.TemplateManagement.service.impl;

import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.core.conditions.update.UpdateWrapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.TemplateManagement.entity.TTemplate;
import com.zeroone.star.TemplateManagement.mapper.TemplateMMapper;
import com.zeroone.star.TemplateManagement.service.ITemplateMService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.j4.templateM.dto.ProjectDTO;
import com.zeroone.star.project.j4.templateM.dto.TemplateMListDTO;
import com.zeroone.star.project.j4.templateM.query.TemplateMQuery;
import org.mapstruct.Mapper;
import org.mapstruct.Mapping;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;
import java.util.ArrayList;
import java.util.List;
import java.util.Objects;

/**
 * <p>
 * 描述：Template 对应MapStruct映射接口
 * </p>
 *
 * @author Triple Gold
 * @version 1.0.0
 */
@Mapper(componentModel = "spring")
interface MsTemplateMapper {
    /**
     * 将TemplateDO 转换成 TemplateDTO
     * @param template 待转换的DO
     * @return 转换结果DTO
     */
    // 解决自动生成代码中，LocalDateTime转Date出现8小时时差的问题
    @Mapping(target = "createTime",
            expression = "java(java.util.Date.from(template.getCreateTime().atZone(java.time.ZoneId.systemDefault()).toInstant()))"
    )
    TemplateMListDTO templateToTemplateMListDTO(TTemplate template);
}

/**
 * <p>
 * 模板 服务实现类
 * </p>
 *
 * @author Triple Gold
 * @since 2024-01-21
 */
@Service
public class TTemplateMServiceImpl extends ServiceImpl<TemplateMMapper, TTemplate> implements ITemplateMService {

    @Resource
    MsTemplateMapper msTemplateMapper;
    @Resource
    TemplateMMapper templateMMapper;

    public ProjectDTO listProjectList() {
        ProjectDTO projectDTO = new ProjectDTO();
        // 构建DTO
        projectDTO.setReportTypeList(listReportTypeList());
        projectDTO.setTypeList(listTypeList());
        projectDTO.setNameList(listNameList());
        projectDTO.setStatusList(listStatusList());
        return projectDTO;
    }
    public List<String> listReportTypeList() {
        // 构建查询条件
        QueryWrapper<TTemplate> wrapper = new QueryWrapper<>();
        wrapper.select("DISTINCT report_type");
        // 执行查询
        List<TTemplate> templateList = baseMapper.selectList(wrapper);
        List<String> reportTypeList = new ArrayList<>();
        for (TTemplate template : templateList) {
            reportTypeList.add(template.getReportType());
        }
        return reportTypeList;
    }

    public List<String> listTypeList() {
        // 构建查询条件
        QueryWrapper<TTemplate> wrapper = new QueryWrapper<>();
        wrapper.select("DISTINCT type");
        // 执行查询
        List<TTemplate> templateList = baseMapper.selectList(wrapper);
        List<String> typeList = new ArrayList<>();
        for (TTemplate template : templateList) {
            typeList.add(template.getType());
        }
        return typeList;
    }

    public List<String> listNameList() {
        // 执行查询
        return templateMMapper.selectName();
    }

    public List<String> listStatusList() {
        // 数据库中只有启用状态，这里直接写死
        List<String> statusList = new ArrayList<>();
        statusList.add("启用");   // 对应数据库中1
        statusList.add("禁用");   // 对应数据库中0
        return statusList;
    }

    @Override
    public PageDTO<TemplateMListDTO> listTemplateList(TemplateMQuery query) {
        // 构建分页条件对象
        Page<TTemplate> page = new Page<>(query.getPageIndex(), query.getPageSize());
        // 构建查询条件，根据是否为空选择加入查询条件
        QueryWrapper<TTemplate> wrapper = getWrapper(query);
        // 执行查询
        Page<TTemplate> result = templateMMapper.selectTemplateList(page, wrapper);
        // System.out.println("result: " + result.getRecords().get(0).getCreateTime());
        return PageDTO.create(result, src -> msTemplateMapper.templateToTemplateMListDTO(src));
    }
    private static QueryWrapper<TTemplate> getWrapper(TemplateMQuery query) {
        QueryWrapper<TTemplate> wrapper = new QueryWrapper<>();
        if (query.getReportType() != null) {
            wrapper.eq("report_type", query.getReportType());
        }
        if (query.getType() != null) {
            wrapper.like("type", query.getType());  // 模糊查询type字段
        }
        if (query.getName() != null) {
            wrapper.like("p.name", query.getName());
        }
        if (query.getStatus() != null) {
            wrapper.eq("status", query.getStatus());
        }
        if (query.getStartTime() != null && query.getEndTime() != null) {
            wrapper.between("t.create_time", query.getStartTime(), query.getEndTime());;
        }
        return wrapper;
    }
    @Override
    public String updateTemplateStatus(String id) {
        // 获取文件名
        TTemplate template = baseMapper.selectById(id);
        // 模板判空
        if (template == null) {
            return "模板不存在";
        }
        String contentName = template.getStatus();
        UpdateWrapper updateWrapper = new UpdateWrapper();
        updateWrapper.eq("id", id);
        if (Objects.equals(contentName, "1")) {
            updateWrapper.set("status", "0");
        }
        else if (Objects.equals(contentName, "0")) {
            updateWrapper.set("status", "1");
        }
        baseMapper.update(template, updateWrapper);
        return "模板状态更新成功";
    }

    @Override
    public String getTemplate(String id) {
        TTemplate template = baseMapper.selectById(id);
        // 模板判空
        if (template == null) {
            return "模板不存在";
        }
        return template.getContent();
    }
}
