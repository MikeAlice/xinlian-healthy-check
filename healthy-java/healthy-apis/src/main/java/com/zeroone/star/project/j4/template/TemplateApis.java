package com.zeroone.star.project.j4.template;

import com.zeroone.star.project.j4.dto.TemplateDto;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.ResultStatus;

import java.util.List;

public interface TemplateApis {

    public JsonVO<ResultStatus> addTemplate(TemplateDto templateDto);

    public JsonVO<TemplateDto> queryTermDetail(String terplateId) throws Exception;

    public JsonVO<ResultStatus> deleteTemplate(List<String> terplateIds);

    public JsonVO<ResultStatus> updateTemplate(TemplateDto templateDto);


}
