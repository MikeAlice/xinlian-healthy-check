#ifndef _GROUP_ORDER_LIST_QUERY_
#define _GROUP_ORDER_LIST_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * �ż��ѯ����
 */
class GroupOrderListQuery : public PageQuery
{
	DTO_INIT(GroupOrderListQuery, PageQuery);
	// �Ա�
	DTO_FIELD(String, sex);
	DTO_FIELD_INFO(sex) {
		info->description = ZH_WORDS_GETTER("exalanding.field.sex");
	}
	// ��λ����
	DTO_FIELD(String, groupUnitName);
	DTO_FIELD_INFO(groupUnitName) {
		info->description = ZH_WORDS_GETTER("exalanding.field.groupUnitName");
	}
	// ��������
	DTO_FIELD(String, groupName);
	DTO_FIELD_INFO(groupName) {
		info->description = ZH_WORDS_GETTER("exalanding.field.groupName");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_GROUP_ORDER_LIST_QUERY_