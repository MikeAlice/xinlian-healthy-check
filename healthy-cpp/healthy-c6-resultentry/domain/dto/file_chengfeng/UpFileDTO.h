#pragma once
#ifndef _UP_FILE_DTO_
#define _UP_FILE_DTO_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 文件传输数据对象
 */
class UpFileDTO : public oatpp::DTO
{
	DTO_INIT(UpFileDTO, DTO);
	// 体检人员id
	DTO_FIELD(String, person_id);
	DTO_FIELD_INFO(person_id) {
		info->description = ZH_WORDS_GETTER("file_chengfeng.field.person_id");
	}
	// 需要上传文件的地址
	DTO_FIELD(String, file_addr);
	DTO_FIELD_INFO(file_addr) {
		info->description = ZH_WORDS_GETTER("file_chengfeng.field.file_addr");
	}

public:
	UpFileDTO() {}
	
};


#include OATPP_CODEGEN_END(DTO)

#endif // !_UP_FILE_DTO_