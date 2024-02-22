#pragma once
#ifndef _PRINTMORE_VO_
#define _PRINTMORE_VO_

#include "../../GlobalInclude.h"
#include "../../dto/printmore/PrintMoreDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ʾ����ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class ResultJsonVO : public JsonVO<ResultDTO::Wrapper> {
	DTO_INIT(ResultJsonVO, JsonVO<ResultDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_PRINTMORE_VO_