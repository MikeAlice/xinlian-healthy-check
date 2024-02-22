#pragma once
#ifndef _DETAILVO_H_
#define _DETAILVO_H_

#include "../../GlobalInclude.h"
#include "../../dto/personDetail/DetailDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ��λ�б���ʾJsonVOʵ��
 */
class DetailJsonVO : public JsonVO<DetailDTO::Wrapper>
{
	DTO_INIT(DetailJsonVO, JsonVO<DetailDTO::Wrapper>);
};


#include OATPP_CODEGEN_END(DTO)

#endif // !_DETAILVO_H_