#ifndef _RESULTLISTVO_H_
#define _RESULTLISTVO_H_

#include "../../GlobalInclude.h"
#include "../../dto/positive/resultListDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ���Խ���б���ʾJsonVOʵ��
 */

class resultListJsonVO : public JsonVO<resultListDTO::Wrapper>
{
	DTO_INIT(resultListJsonVO, JsonVO<resultListDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_RESULTLISTVO_H_