#pragma once

#ifndef _GROUPDETAILDTO_H_
#define _GROUPDETAILDTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class GroupDetailDTO : public oatpp::DTO
{
	DTO_INIT(GroupDetailDTO, DTO);
	//����
	API_DTO_FIELD_DEFAULT(String, id, ZH_WORDS_GETTER("group.field.id"));
	//����id
	API_DTO_FIELD_DEFAULT(String, groupOrderId, ZH_WORDS_GETTER("group.field.group_order_id"));
	//��������
	API_DTO_FIELD_DEFAULT(String, name, ZH_WORDS_GETTER("group.field.name"));
	//�ײ�id
	API_DTO_FIELD_DEFAULT(String, comboId, ZH_WORDS_GETTER("group.field.combo_id"));
	//�ŵ��ۿ�
	API_DTO_FIELD_DEFAULT(Float64, discount, ZH_WORDS_GETTER("group.field.discount"));
	//�����ۿ�
	API_DTO_FIELD_DEFAULT(Int32, addDiscount, ZH_WORDS_GETTER("group.field.add_discount"));
	//�Żݼ�
	API_DTO_FIELD_DEFAULT(String, discountPrice, ZH_WORDS_GETTER("group.field.discount_price"));
	//������
	API_DTO_FIELD_DEFAULT(Int32, personCount, ZH_WORDS_GETTER("group.field.person_count"));
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_GROUPDETAILDTO_H_
