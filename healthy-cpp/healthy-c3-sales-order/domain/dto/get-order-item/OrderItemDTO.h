#pragma once

#ifndef _ORDER_ITEM_DTO_
#define _ORDER_ITEM_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 获取订单体检项目信息    负责人：Adam
 */
class OrderItemDTO : public oatpp::DTO
{
	DTO_INIT(OrderItemDTO, DTO);
	//主键
	API_DTO_FIELD_DEFAULT(String, id, ZH_WORDS_GETTER("item.field.id"));
	//分组id
	API_DTO_FIELD_DEFAULT(String, groupId, ZH_WORDS_GETTER("item.field.group_id"));
	//订单id
	API_DTO_FIELD_DEFAULT(String, groupOrderId, ZH_WORDS_GETTER("item.field.group_order_id"));
	//名称
	API_DTO_FIELD_DEFAULT(String, name, ZH_WORDS_GETTER("item.field.name"));
	//销售价（元）
	API_DTO_FIELD_DEFAULT(Float64, salePrice, ZH_WORDS_GETTER("item.field.sale_price"));
	//折扣
	API_DTO_FIELD_DEFAULT(Int32, discount, ZH_WORDS_GETTER("item.field.discount"));
	//折扣价(元)
	API_DTO_FIELD_DEFAULT(Float64, discountPrice, ZH_WORDS_GETTER("item.field.discount_price"));
	//项目类型（1套餐项目 2非套餐项目）
	API_DTO_FIELD_DEFAULT(Int32, projectType, ZH_WORDS_GETTER("item.field.project_type"));
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_ORDER_ITEM_DTO_