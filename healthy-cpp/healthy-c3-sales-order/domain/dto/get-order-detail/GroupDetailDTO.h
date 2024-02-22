#pragma once

#ifndef _GROUPDETAILDTO_H_
#define _GROUPDETAILDTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class GroupDetailDTO : public oatpp::DTO
{
	DTO_INIT(GroupDetailDTO, DTO);
	//主键
	API_DTO_FIELD_DEFAULT(String, id, ZH_WORDS_GETTER("group.field.id"));
	//订单id
	API_DTO_FIELD_DEFAULT(String, groupOrderId, ZH_WORDS_GETTER("group.field.group_order_id"));
	//分组名称
	API_DTO_FIELD_DEFAULT(String, name, ZH_WORDS_GETTER("group.field.name"));
	//套餐id
	API_DTO_FIELD_DEFAULT(String, comboId, ZH_WORDS_GETTER("group.field.combo_id"));
	//团单折扣
	API_DTO_FIELD_DEFAULT(Float64, discount, ZH_WORDS_GETTER("group.field.discount"));
	//增项折扣
	API_DTO_FIELD_DEFAULT(Int32, addDiscount, ZH_WORDS_GETTER("group.field.add_discount"));
	//优惠价
	API_DTO_FIELD_DEFAULT(String, discountPrice, ZH_WORDS_GETTER("group.field.discount_price"));
	//组人数
	API_DTO_FIELD_DEFAULT(Int32, personCount, ZH_WORDS_GETTER("group.field.person_count"));
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_GROUPDETAILDTO_H_
