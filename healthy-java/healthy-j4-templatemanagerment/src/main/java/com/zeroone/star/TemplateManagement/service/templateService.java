package com.zeroone.star.TemplateManagement.service;

import com.baomidou.mybatisplus.extension.service.IService;

import com.zeroone.star.project.j4.dto.TemplateDto;



public interface templateService extends IService<TemplateDto> {
    TemplateDto getPortfolioItemById(String id) throws Exception;

}
