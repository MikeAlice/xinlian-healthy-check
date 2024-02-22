#pragma once

#ifndef _ORDEROUTPUT_VO_
#define _ORDEROUTPUT_VO_

#include"../../GlobalInclude.h"
#include "../../dto/export-person/ExportPersonDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)
class ExportPersonJsonVO :public JsonVO<ExportPersonDTO::Wrapper>
{
	DTO_INIT(ExportPersonJsonVO, JsonVO<ExportPersonDTO::Wrapper>);
};


#include OATPP_CODEGEN_END(DTO)

#endif 