#ifndef _GROUP_ORDER_DTO_
#define _GROUP_ORDER_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * �ż촫�����
 */
class GroupOrderListDTO : public oatpp::DTO
{
	DTO_INIT(GroupOrderListDTO, DTO);
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

/**
 * ʾ����ҳ�������
 */
class GroupOrderListPageDTO : public PageDTO<GroupOrderListDTO::Wrapper>
{
	DTO_INIT(GroupOrderListPageDTO, PageDTO<GroupOrderListDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_GROUP_ORDER_DTO_