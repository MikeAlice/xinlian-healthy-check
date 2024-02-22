#pragma once
#ifndef _INTERRO_QUERY_
#define _INTERRO_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"
#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 症状问询查询对象
 */
class InterroQuery : public PageQuery
{
	DTO_INIT(InterroQuery,PageQuery);
	// 体检人编号
	DTO_FIELD(String, id);
	DTO_FIELD_INFO(id) {
		info->description = ZH_WORDS_GETTER("interro1.field.id");
	}
	// 体检项目编号
	DTO_FIELD(String, project);
	DTO_FIELD_INFO(project) {
		info->description = ZH_WORDS_GETTER("interro1.field.project");
	}
};
#include OATPP_CODEGEN_END(DTO)
#endif // !_INTERRO_QUERY_