#pragma once
#ifndef _RPPROCHECK_DTO_
#define _RPPROCHECK_DTO_
#include "../../GlobalInclude.h"
#include "SaveResItemDTO.h"


#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ʾ���������
 */
class RPProCheckDTO : public oatpp::DTO
{
	DTO_INIT(RPProCheckDTO, DTO);


	// ��������
	// �����id
	API_DTO_FIELD_DEFAULT(String, personId, ZH_WORDS_GETTER("save.filed.personId"));
	// ����id
	API_DTO_FIELD_DEFAULT(String, officeId, ZH_WORDS_GETTER("save.filed.officeId"));
	// ������Ŀid
	API_DTO_FIELD_DEFAULT(String, groupItemId, ZH_WORDS_GETTER("save.filed.groupItemId"));	

};

#include OATPP_CODEGEN_END(DTO)
#endif // !_RPPROCHECK_DTO_