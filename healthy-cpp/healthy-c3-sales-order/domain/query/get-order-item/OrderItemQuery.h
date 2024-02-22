#pragma once

#ifndef _ORDER_ITEM_QUERY_DTO_
#define _ORDER_ITEM_QUERY_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ��ȡ���������Ŀ��Ϣ    �����ˣ�Adam
 */
class OrderItemQuery : public oatpp::DTO
{
	DTO_INIT(OrderItemQuery, DTO);
	// ����id
	API_DTO_FIELD_DEFAULT(String, groupOrderId, ZH_WORDS_GETTER("item.field.group_order_id"));
	//����id
	API_DTO_FIELD_DEFAULT(String, groupId, ZH_WORDS_GETTER("item.field.group_id"));
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_ORDER_ITEM_QUERY_DTO_