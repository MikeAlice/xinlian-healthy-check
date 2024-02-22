#pragma once


#ifndef _ReportList_VO_
#define _ReportList_VO_

#include "../../GlobalInclude.h"
#include "../../dto/reportlist/ReportListDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * �Ӽ챨���б�JsonVO��������Ӧ���ͻ��˵�Json����
 */
class ReportListJsonVO : public JsonVO<ReportListDTO::Wrapper> {
	DTO_INIT(ReportListJsonVO, JsonVO<ReportListDTO::Wrapper>);
};

/**
 * �Ӽ챨���б��ҳ��ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class ReportListPageJsonVO : public JsonVO<ReportListPageDTO::Wrapper> {
	DTO_INIT(ReportListPageJsonVO, JsonVO<ReportListPageDTO::Wrapper>);
};


#include OATPP_CODEGEN_END(DTO)
#endif