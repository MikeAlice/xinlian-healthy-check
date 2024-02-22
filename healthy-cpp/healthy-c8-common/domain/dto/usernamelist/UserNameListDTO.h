#pragma once
#ifndef _UserNameListDTO_
#define _UserNameListDTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ʾ���������
 */
class UserNameListDTO : public oatpp::DTO
{
	DTO_INIT(UserNameListDTO, DTO);
	// ���
	DTO_FIELD(String, user_name);
	DTO_FIELD_INFO(user_name) {
		info->description = ZH_WORDS_GETTER("usernamelist.field.user_name");
	}
};
#include OATPP_CODEGEN_END(DTO)
#endif 