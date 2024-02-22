#pragma once
#ifndef _GetPD_VO_
#define _GetPD_VO_

#include "../../GlobalInclude.h"
#include "../../dto/GetPD/GetPDDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ʾ����ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class GetPDJsonVO : public JsonVO<GetPDDTO::Wrapper> {
	DTO_INIT(GetPDJsonVO, JsonVO<GetPDDTO::Wrapper>);
};

/**
 * ʾ����ҳ��ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class GetPDPageJsonVO : public JsonVO<GetPDPageDTO::Wrapper> {
	DTO_INIT(GetPDPageJsonVO, JsonVO<GetPDPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_GetPD_VO_