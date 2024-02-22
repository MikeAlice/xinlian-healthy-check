#pragma once
#ifndef _DEPARTVO_H_
#define _DEPARTVO_H_

#include "../../GlobalInclude.h"
#include "../../dto/Dangerous/DepartListDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class DepartListJsonVO : public JsonVO<DepartListDTO::Wrapper> {
	DTO_INIT(DepartListJsonVO, JsonVO<DepartListDTO::Wrapper>);
};

class DepartListPageJsonVO : public JsonVO<DepartListPageDTO::Wrapper> {
	DTO_INIT(DepartListPageJsonVO,JsonVO<DepartListPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_UNITQUERY_H_