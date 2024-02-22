#pragma once

#ifndef _VIEW_EXCEPTION_DTO_
#define _VIEW_EXCEPTION_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class ViewExceptionDTO : public oatpp::DTO
{
	DTO_INIT(ViewExceptionDTO, DTO);

	DTO_FIELD(String, exception_message);
	DTO_FIELD_INFO(exception_message) {
		info->description = ZH_WORDS_GETTER("view-exception.field.exception_message");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif