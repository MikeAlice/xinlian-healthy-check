#pragma once
#ifndef _PRINTMORE_DTO_
#define _PRINTMORE_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ʾ���������
 */
class PrintMoreDTO : public oatpp::DTO
{
	DTO_INIT(PrintMoreDTO, DTO);

	// ����֤id
	DTO_FIELD(UInt64, id);
	DTO_FIELD_INFO(id) {
		info->description = ZH_WORDS_GETTER("printmore.field.id");
	}
};

class ResultDTO : public oatpp::DTO
{
	DTO_INIT(ResultDTO, DTO);

	// �������Ӽ���
	DTO_FIELD(List<String>, urls) = {};
	DTO_FIELD_INFO(urls) {
		info->description = ZH_WORDS_GETTER("printmore.field.urls");
	}
	void addData(String one) {
		this->urls->push_back(one);
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_PRINTMORE_DTO_

