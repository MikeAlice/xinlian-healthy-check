#pragma once
#ifndef _SectionNameListVO_
#define _SectionNameListVO_

#include "../../GlobalInclude.h"
#include "../../dto/sectionnamelist/SectionNameListDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ʾ����ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class SectionNameListJsonVO : public JsonVO<SectionNameListDTO::Wrapper> {
	DTO_INIT(SectionNameListJsonVO, JsonVO<SectionNameListDTO::Wrapper>);
};


#include OATPP_CODEGEN_END(DTO)

#endif // !_SAMPLE_VO_