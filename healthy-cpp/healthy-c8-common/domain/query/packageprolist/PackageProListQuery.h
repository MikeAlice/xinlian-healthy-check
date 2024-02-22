#pragma once
#ifndef _PackageProList_Query_
#define _PackageProList_Query_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例分页查询对象
 */
class PackageProListQuery : public PageQuery
{
	DTO_INIT(PackageProListQuery, PageQuery);
	// 组合项目名称
	DTO_FIELD(String, keyword);
	DTO_FIELD_INFO(keyword) {
		info->description = ZH_WORDS_GETTER("packageprolist.field.keyword");
	}
	// 所属科室
	DTO_FIELD(String, section);
	DTO_FIELD_INFO(section) {
		info->description = ZH_WORDS_GETTER("packageprolist.field.section");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_SAMPLE_QUERY_