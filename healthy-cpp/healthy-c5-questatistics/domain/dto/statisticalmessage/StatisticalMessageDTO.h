#pragma once

#ifndef _STATISTICALMESSAGEDTO_H_
#define _STATISTICALMESSAGEDTO_H_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
*��λ�б������ʵ��
*/

class StatisticalMessageDTO : public oatpp::DTO
{
	DTO_INIT(StatisticalMessageDTO, DTO);
	//Ψһ���
	API_DTO_FIELD_DEFAULT(String, id, ZH_WORDS_GETTER("list.field.id"));
	//���״̬
	API_DTO_FIELD_DEFAULT(UInt32, isPass, ZH_WORDS_GETTER("statistica.rate.isPass"));
};

/**
*��λ�б��ҳ����ʵ��
*/

class StatisticalMessagePageDTO :public PageDTO < StatisticalMessageDTO::Wrapper > {
	DTO_INIT(StatisticalMessagePageDTO, PageDTO < StatisticalMessageDTO::Wrapper >);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_JoinPersonListDTO_H_