#ifndef _GROUP_ORDER_LIST_QUERY_
#define _GROUP_ORDER_LIST_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 团检查询对象
 */
class GroupOrderListQuery : public PageQuery
{
	DTO_INIT(GroupOrderListQuery, PageQuery);
	// 性别
	DTO_FIELD(String, sex);
	DTO_FIELD_INFO(sex) {
		info->description = ZH_WORDS_GETTER("exalanding.field.sex");
	}
	// 单位名称
	DTO_FIELD(String, groupUnitName);
	DTO_FIELD_INFO(groupUnitName) {
		info->description = ZH_WORDS_GETTER("exalanding.field.groupUnitName");
	}
	// 分组名称
	DTO_FIELD(String, groupName);
	DTO_FIELD_INFO(groupName) {
		info->description = ZH_WORDS_GETTER("exalanding.field.groupName");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_GROUP_ORDER_LIST_QUERY_