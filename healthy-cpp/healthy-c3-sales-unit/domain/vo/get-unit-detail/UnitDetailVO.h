#pragma once

#ifndef _UNITDETAILVO_H_
#define _UNITDETAILVO_H_

#include "../../GlobalInclude.h"
#include "../../dto/update-unit/UnitDetailDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ºÏ≤‚–≈œ¢VO
 */
class UnitDetailJsonVO : public JsonVO<UnitDetailDTO::Wrapper>
{
	DTO_INIT(UnitDetailJsonVO, JsonVO<UnitDetailDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_UNITDETAILVO_H_
