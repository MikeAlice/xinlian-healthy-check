#pragma once
#ifndef _DictNameListDTO_
#define _DictNameListDTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)


class DictNameListDTO : public DTO
{
	DTO_INIT(DictNameListDTO, DTO);
	API_DTO_FIELD_DEFAULT(String, dict_name, ZH_WORDS_GETTER("dictnamelist.field.dict_name"));
};
#include OATPP_CODEGEN_END(DTO)
#endif 