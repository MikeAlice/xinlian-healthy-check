#pragma once
#ifndef _UPLOADMORE_DTO_
#define _UPLOADMORE_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ����֤�ϴ�������󣬻�ȡpersonId
 */
class UploadMoreDTO : public oatpp::DTO
{
	DTO_INIT(UploadMoreDTO, DTO);
	// ��Աid
	DTO_FIELD(String, personId);
	DTO_FIELD_INFO(personId) {
		info->description = ZH_WORDS_GETTER("uploadmore.field.personId");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif 