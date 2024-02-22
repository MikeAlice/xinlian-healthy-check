#pragma once
#ifndef _GetPD_DTO_
#define _GetPD_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例传输对象
 */
class GetPDDTO : public oatpp::DTO
{
	DTO_INIT(GetPDDTO, DTO);
	// 姓名
	DTO_FIELD(String, name);
	DTO_FIELD_INFO(name) {
		info->description = ZH_WORDS_GETTER("GetPD.field.name");
	}
	// 身份证号
	DTO_FIELD(UInt32, id_card);
	DTO_FIELD_INFO(id_card) {
		info->description = ZH_WORDS_GETTER("GetPD.field.id_card");
	}
	// 年龄
	DTO_FIELD(UInt32, age);
	DTO_FIELD_INFO(age) {
		info->description = ZH_WORDS_GETTER("GetPD.field.age");
	}
	// 联系电话
	DTO_FIELD(UInt32, phone);
	DTO_FIELD_INFO(phone) {
		info->description = ZH_WORDS_GETTER("GetPD.field.phone");
	}
	//性别
		DTO_FIELD(String, sex);
		DTO_FIELD_INFO(sex) {
			info->description = ZH_WORDS_GETTER("GetPD.field.sex");
		}
	//职业
		DTO_FIELD(String, work_name);
		DTO_FIELD_INFO(work_name) {
			info->description = ZH_WORDS_GETTER("GetPD.field.work_name");
		}
};

/**
 * 示例分页传输对象
 */
class GetPDPageDTO : public PageDTO<GetPDDTO::Wrapper>
{
	DTO_INIT(GetPDPageDTO, PageDTO<GetPDDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_GetPD_DTO_