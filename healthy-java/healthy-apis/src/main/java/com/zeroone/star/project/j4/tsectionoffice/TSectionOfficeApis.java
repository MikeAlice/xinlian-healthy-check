package com.zeroone.star.project.j4.tsectionoffice;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.j4.dto.GetSecNameDTO;
import com.zeroone.star.project.j4.dto.GetSectionOfficetDTO;
import com.zeroone.star.project.j4.dto.TSectionOfficeDTO;
import com.zeroone.star.project.j4.query.GetSectionOfficeQuery;
import com.zeroone.star.project.j4.vo.GetSecNameVO;
import com.zeroone.star.project.j4.vo.GetSectionOfficeVO;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.ResultStatus;
import org.springframework.validation.annotation.Validated;

import javax.validation.Valid;
import javax.validation.constraints.NotNull;
import java.util.List;

public interface TSectionOfficeApis {

    JsonVO<ResultStatus> addSectionOffice(@Validated TSectionOfficeDTO TSectionOfficeDTO);


    JsonVO<ResultStatus> modifySectionOffice(@Validated TSectionOfficeDTO TSectionOfficeDTO);


    JsonVO<ResultStatus> removeSectionOffice(@NotNull(message = "List不能为空") List<String> ids);

}
