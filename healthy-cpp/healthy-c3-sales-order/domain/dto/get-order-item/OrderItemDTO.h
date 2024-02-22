#pragma once

#ifndef _ORDER_ITEM_DTO_
#define _ORDER_ITEM_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ��ȡ���������Ŀ��Ϣ    �����ˣ�Adam
 */
class OrderItemDTO : public oatpp::DTO
{
	DTO_INIT(OrderItemDTO, DTO);
	//����
	API_DTO_FIELD_DEFAULT(String, id, ZH_WORDS_GETTER("item.field.id"));
	//����id
	API_DTO_FIELD_DEFAULT(String, groupId, ZH_WORDS_GETTER("item.field.group_id"));
	//����id
	API_DTO_FIELD_DEFAULT(String, groupOrderId, ZH_WORDS_GETTER("item.field.group_order_id"));
	//����
	API_DTO_FIELD_DEFAULT(String, name, ZH_WORDS_GETTER("item.field.name"));
	//���ۼۣ�Ԫ��
	API_DTO_FIELD_DEFAULT(Float64, salePrice, ZH_WORDS_GETTER("item.field.sale_price"));
	//�ۿ�
	API_DTO_FIELD_DEFAULT(Int32, discount, ZH_WORDS_GETTER("item.field.discount"));
	//�ۿۼ�(Ԫ)
	API_DTO_FIELD_DEFAULT(Float64, discountPrice, ZH_WORDS_GETTER("item.field.discount_price"));
	//��Ŀ���ͣ�1�ײ���Ŀ 2���ײ���Ŀ��
	API_DTO_FIELD_DEFAULT(Int32, projectType, ZH_WORDS_GETTER("item.field.project_type"));
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_ORDER_ITEM_DTO_