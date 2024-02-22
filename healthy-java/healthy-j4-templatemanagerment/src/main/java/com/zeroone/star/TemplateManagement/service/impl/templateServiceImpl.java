package com.zeroone.star.TemplateManagement.service.impl;

import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.TemplateManagement.mapper.templatetMapper;
import com.zeroone.star.TemplateManagement.service.templateService;
import com.zeroone.star.project.j4.dto.TemplateDto;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

@Service
public class templateServiceImpl extends ServiceImpl<templatetMapper, TemplateDto> implements templateService {
    @Autowired
    private templatetMapper templatetMapper;
    @Override
    public TemplateDto getPortfolioItemById(String id) throws Exception {
        return templatetMapper.selectById(id);
    }
}
