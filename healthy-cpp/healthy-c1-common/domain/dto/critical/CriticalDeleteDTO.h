#pragma once
#pragma once

#ifndef _CRITICALDELETEDTO_H_
#define _CRITICALDELETEDTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ��λ�б����ݶ���ʵ��
 */
class CriticalDeleteListDTO : public oatpp::DTO
{
	// �����ʼ��
	DTO_INIT(CriticalDeleteListDTO, DTO);
	API_DTO_FIELD_DEFAULT(String, id, ZH_WORDS_GETTER("critical.field.id"));


};

#include OATPP_CODEGEN_END(DTO)
#endif // !_USERQUERY_H_