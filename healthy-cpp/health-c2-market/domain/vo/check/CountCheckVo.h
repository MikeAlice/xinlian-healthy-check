#pragma once
#ifndef _COUNTCHECK_VO
#define _COUNTCHECK_VO

#include "../../GlobalInclude.h"
#include "../../dto/check/CountCheckDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ʾ����ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class CountCheckJsonVO : public JsonVO<CountCheckDTO::Wrapper> {
	DTO_INIT(CountCheckJsonVO, JsonVO<CountCheckDTO::Wrapper>);
};


#include OATPP_CODEGEN_END(DTO)

#endif // !_SAMPLE_VO_