#pragma once
#ifndef _PackageProList_Query_
#define _PackageProList_Query_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ʾ����ҳ��ѯ����
 */
class PackageProListQuery : public PageQuery
{
	DTO_INIT(PackageProListQuery, PageQuery);
	// �����Ŀ����
	DTO_FIELD(String, keyword);
	DTO_FIELD_INFO(keyword) {
		info->description = ZH_WORDS_GETTER("packageprolist.field.keyword");
	}
	// ��������
	DTO_FIELD(String, section);
	DTO_FIELD_INFO(section) {
		info->description = ZH_WORDS_GETTER("packageprolist.field.section");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_SAMPLE_QUERY_