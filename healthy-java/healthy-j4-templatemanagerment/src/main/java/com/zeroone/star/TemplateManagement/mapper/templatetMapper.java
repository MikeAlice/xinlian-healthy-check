package com.zeroone.star.TemplateManagement.mapper;

import com.baomidou.mybatisplus.annotation.TableName;
import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.project.j4.dto.TemplateDto;
import org.apache.ibatis.annotations.Mapper;

@TableName("t_template")
@Mapper
public interface templatetMapper extends BaseMapper<TemplateDto> {

}
