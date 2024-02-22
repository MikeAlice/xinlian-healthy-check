#pragma once
#ifndef _TermNameListVO_
#define _TermNameListVO_

#include "../../GlobalInclude.h"
#include "../../dto/termnamelist/TermNameListDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ʾ����ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class TermNameListVO : public JsonVO<TermNameListDTO::Wrapper> {
	DTO_INIT(TermNameListVO, JsonVO<TermNameListDTO::Wrapper>);
};

/**
 * ʾ����ҳ��ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class TermNameListPageJsonVO : public JsonVO<TermNameListPageDTO::Wrapper> {
	DTO_INIT(TermNameListPageJsonVO, JsonVO<TermNameListPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_SAMPLE_VO_