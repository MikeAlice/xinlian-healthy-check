#pragma once
#ifndef _DictNameListVO_
#define _DictNameListVO_

#include "../../GlobalInclude.h"
#include "../../dto/dictnamelist/DictNameListDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ʾ����ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class DictNameListJsonVO : public JsonVO<DictNameListDTO::Wrapper> {
	DTO_INIT(DictNameListJsonVO, JsonVO<DictNameListDTO::Wrapper>);
};
#include OATPP_CODEGEN_END(DTO)

#endif // !_SAMPLE_VO_