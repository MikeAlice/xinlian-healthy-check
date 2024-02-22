#pragma once
 
#ifndef _GROUPITEMIGNO_DTO_
#define _GROUPITEMIGNO_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)


class GroupItemIgnoDTO : public oatpp::DTO
{
	DTO_INIT(GroupItemIgnoDTO, DTO);

	// 体检人员id		person_id
	DTO_FIELD(String, personId);
	DTO_FIELD_INFO(personId) {
		info->description = ZH_WORDS_GETTER("groupItemIgno.field.personId"); 
	}
	// 要忽略的项目id	order_group_item_project_id
	DTO_FIELD(String, orderGroupItemProjectId);
	DTO_FIELD_INFO(orderGroupItemProjectId) {
		info->description = ZH_WORDS_GETTER("groupItemIgno.field.orderGroupItemProjectId"); 
	}
	// 修改人id			update_id
	DTO_FIELD(String, updateId);
	DTO_FIELD_INFO(updateId) {
		info->description = ZH_WORDS_GETTER("groupItemIgno.field.updateId"); 
	}
};


#include OATPP_CODEGEN_END(DTO)


#endif // !_SAMPLE_DTO_