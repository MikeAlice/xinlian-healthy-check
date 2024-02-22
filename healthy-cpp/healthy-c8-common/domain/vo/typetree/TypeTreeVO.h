#pragma once
#ifndef _TypeTreeVO_
#define _TypeTreeVO_

#include "../../GlobalInclude.h"
#include "../../dto/typetree/TypeTreeDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ʾ����ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class TypeTreeJsonVO : public JsonVO<TypeTreeDTO::Wrapper> {
	DTO_INIT(TypeTreeJsonVO, JsonVO<TypeTreeDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_SAMPLE_VO_