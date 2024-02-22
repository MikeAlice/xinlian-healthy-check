#pragma once

#ifndef _REMOVEUNITDTO_H_
#define _REMOVEUNITDTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

//根据id导出付款记录
class RemoveUnitDTO : public oatpp::DTO
{
	DTO_INIT(RemoveUnitDTO, DTO);
	API_DTO_FIELD_DEFAULT(String, id, ZH_WORDS_GETTER("unit.field.id"));
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_REMOVEUNITDTO_H_
