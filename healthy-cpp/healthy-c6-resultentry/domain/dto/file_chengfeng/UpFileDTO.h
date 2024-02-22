#pragma once
#ifndef _UP_FILE_DTO_
#define _UP_FILE_DTO_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * �ļ��������ݶ���
 */
class UpFileDTO : public oatpp::DTO
{
	DTO_INIT(UpFileDTO, DTO);
	// �����Աid
	DTO_FIELD(String, person_id);
	DTO_FIELD_INFO(person_id) {
		info->description = ZH_WORDS_GETTER("file_chengfeng.field.person_id");
	}
	// ��Ҫ�ϴ��ļ��ĵ�ַ
	DTO_FIELD(String, file_addr);
	DTO_FIELD_INFO(file_addr) {
		info->description = ZH_WORDS_GETTER("file_chengfeng.field.file_addr");
	}

public:
	UpFileDTO() {}
	
};


#include OATPP_CODEGEN_END(DTO)

#endif // !_UP_FILE_DTO_