#ifndef _REPORTQUERY_H_
#define _REPORTQUERY_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)
/*
 * ΨһID��ѯ
 */
class IDQuery : public oatpp::DTO
{
	DTO_INIT(IDQuery, DTO);
	//Ψһ���
	API_DTO_FIELD_DEFAULT(String, id, ZH_WORDS_GETTER("unit.id"));
};

#include OATPP_CODEGEN_END(DTO)
#endif 

