#pragma once
#ifndef _RPPROCHECK_DTO_
#define _RPPROCHECK_DTO_
#include "../../GlobalInclude.h"
#include "SaveResItemDTO.h"


#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例传输对象
 */
class RPProCheckDTO : public oatpp::DTO
{
	DTO_INIT(RPProCheckDTO, DTO);


	// 公共部分
	// 体检人id
	API_DTO_FIELD_DEFAULT(String, personId, ZH_WORDS_GETTER("save.filed.personId"));
	// 科室id
	API_DTO_FIELD_DEFAULT(String, officeId, ZH_WORDS_GETTER("save.filed.officeId"));
	// 分组项目id
	API_DTO_FIELD_DEFAULT(String, groupItemId, ZH_WORDS_GETTER("save.filed.groupItemId"));	

};

#include OATPP_CODEGEN_END(DTO)
#endif // !_RPPROCHECK_DTO_