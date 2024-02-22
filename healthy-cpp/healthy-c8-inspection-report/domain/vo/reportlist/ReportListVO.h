#pragma once


#ifndef _ReportList_VO_
#define _ReportList_VO_

#include "../../GlobalInclude.h"
#include "../../dto/reportlist/ReportListDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 从检报告列表JsonVO，用于响应给客户端的Json对象
 */
class ReportListJsonVO : public JsonVO<ReportListDTO::Wrapper> {
	DTO_INIT(ReportListJsonVO, JsonVO<ReportListDTO::Wrapper>);
};

/**
 * 从检报告列表分页显示JsonVO，用于响应给客户端的Json对象
 */
class ReportListPageJsonVO : public JsonVO<ReportListPageDTO::Wrapper> {
	DTO_INIT(ReportListPageJsonVO, JsonVO<ReportListPageDTO::Wrapper>);
};


#include OATPP_CODEGEN_END(DTO)
#endif