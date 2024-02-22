#pragma once
#ifndef _UPLOADMORE_DTO_
#define _UPLOADMORE_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 健康证上传传输对象，获取personId
 */
class UploadMoreDTO : public oatpp::DTO
{
	DTO_INIT(UploadMoreDTO, DTO);
	// 人员id
	DTO_FIELD(String, personId);
	DTO_FIELD_INFO(personId) {
		info->description = ZH_WORDS_GETTER("uploadmore.field.personId");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif 