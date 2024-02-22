#pragma once
#ifndef _NAMELIST_VO_
#define _NAMELIST_VO_

#include "../../GlobalInclude.h"
#include "../../dto/contract/NameListDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ʾ����ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class NameListJsonVO : public JsonVO<NameListDTO::Wrapper> {
	DTO_INIT(NameListJsonVO, JsonVO<NameListDTO::Wrapper>);
};

/**
 * ʾ����ҳ��ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class NameListPageJsonVO : public JsonVO<NameListPageDTO::Wrapper> {
	DTO_INIT(NameListPageJsonVO, JsonVO<NameListPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_SAMPLE_VO_