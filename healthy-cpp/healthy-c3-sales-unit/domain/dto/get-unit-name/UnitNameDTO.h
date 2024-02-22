#pragma once

#ifndef _UNITNAMEDTO_H_
#define _UNITNAMEDTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ��ȡ��λ�����б���������������б��    �����ˣ�Tutu��ͿͿ
 */

class UnitNameDTO : public oatpp::DTO
{
	DTO_INIT(UnitNameDTO, DTO);
	//��λID
	API_DTO_FIELD_DEFAULT(String, id, ZH_WORDS_GETTER("unit.field.id"));
	//��λ����
	API_DTO_FIELD_DEFAULT(String, name, ZH_WORDS_GETTER("unit.field.name"));
};

class UnitNamePageDTO : public PageDTO<UnitNameDTO::Wrapper> {
	DTO_INIT(UnitNamePageDTO, PageDTO<UnitNameDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_UNITNAMEDTO_H_
