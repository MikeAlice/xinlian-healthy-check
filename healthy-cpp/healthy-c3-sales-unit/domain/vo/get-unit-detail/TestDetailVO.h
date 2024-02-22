#pragma once

#ifndef _TESTDETAILVO_H_
#define _TESTDETAILVO_H_

#include "../../GlobalInclude.h"
#include "../../dto/update-unit/TestDetailDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ºÏ≤‚–≈œ¢VO
 */
class TestDetailJsonVO : public JsonVO<TestDetailDTO::Wrapper>
{
	DTO_INIT(TestDetailJsonVO, JsonVO<TestDetailDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_TESTDETAILVO_H_
