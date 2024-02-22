#pragma once
#ifndef _GETPD_QUERY_
#define _GETPD_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例分页查询对象
 */
class GetPDQuery : public PageQuery
{
	DTO_INIT(GetPDQuery, PageQuery);
	// 姓名
	DTO_FIELD(String, name);
	DTO_FIELD_INFO(name) {
		info->description = ZH_WORDS_GETTER("GetPD.field.name");
	}
	// 身份证号
	DTO_FIELD(UInt32,id_card);
	DTO_FIELD_INFO(id_card) {
		info->description = ZH_WORDS_GETTER("GetPD.field.id_card");
	}
	// 编号
	DTO_FIELD(UInt32, id);
	DTO_FIELD_INFO(id) {
		info->description = ZH_WORDS_GETTER("GetPD.field.id");
	}
	// 单位名称
	DTO_FIELD(String, work_name);
	DTO_FIELD_INFO(work_name) {
		info->description = ZH_WORDS_GETTER("GetPD.field.work_name");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_GetPD_QUERY_