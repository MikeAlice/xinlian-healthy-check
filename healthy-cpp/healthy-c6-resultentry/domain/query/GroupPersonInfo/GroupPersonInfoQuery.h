#pragma once
#ifndef _GROUP_PERSON_INFO_QUERY_
#define _GROUP_PERSON_INFO_QUERY_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)
/**
 * ��Ա�����ѯʵ��
 */
class GroupPersonInfoQuery : public oatpp::DTO
{
	DTO_INIT(GroupPersonInfoQuery, DTO);

	// �����
	API_DTO_FIELD_DEFAULT(String, test_num, ZH_WORDS_GETTER("group_person.data.test_num"));
};
#include OATPP_CODEGEN_END(DTO)
#endif // !_GROUP_PERSON_INFO_QUERY_