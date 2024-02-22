#ifndef _GROUP_ORDER_DTO_
#define _GROUP_ORDER_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 团检传输对象
 */
class GroupOrderListDTO : public oatpp::DTO
{
	DTO_INIT(GroupOrderListDTO, DTO);
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

/**
 * 示例分页传输对象
 */
class GroupOrderListPageDTO : public PageDTO<GroupOrderListDTO::Wrapper>
{
	DTO_INIT(GroupOrderListPageDTO, PageDTO<GroupOrderListDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_GROUP_ORDER_DTO_