#pragma once

#ifndef _ORDERDETAILDTO_H_
#define _ORDERDETAILDTO_H_

#include "../../GlobalInclude.h"
#include "GroupDetailDTO.h"
#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ��ѯ��������
 */
class OrderDetailDTO : public oatpp::DTO
{
	DTO_INIT(OrderDetailDTO, DTO);

	//����
	API_DTO_FIELD_DEFAULT(String, id, ZH_WORDS_GETTER("order.field.id"));
	//�������
	API_DTO_FIELD_DEFAULT(String, orderCode, ZH_WORDS_GETTER("order.field.order_code"));
	//�ż쵥λid
	API_DTO_FIELD_DEFAULT(String, groupUnitId, ZH_WORDS_GETTER("order.field.group_unit_id"));
	//�ż쵥λ����
	API_DTO_FIELD_DEFAULT(String, groupUnitName, ZH_WORDS_GETTER("order.field.group_unit_name"));
	//���۸�����
	API_DTO_FIELD_DEFAULT(String, salesDirector, ZH_WORDS_GETTER("order.field.sales_director"));
	//���۸���������
	API_DTO_FIELD_DEFAULT(String, salesDirectorName, ZH_WORDS_GETTER("order.field.sales_director_name"));
	//ǩ������
	API_DTO_FIELD_DEFAULT(String, signingTime, ZH_WORDS_GETTER("order.field.signing_time"));
	//�������
	API_DTO_FIELD_DEFAULT(String, deliveryTime, ZH_WORDS_GETTER("order.field.delivery_time"));
	//�Ƿ��������(0-��1-��)
	API_DTO_FIELD_DEFAULT(Int32, sporadicPhysical, ZH_WORDS_GETTER("order.field.sporadic_physical"));
	//���״̬ -1 ����� 0 Ҫ��� 1������ 2��ͨ�� 3δͨ��
	API_DTO_FIELD_DEFAULT(Int32, auditState, ZH_WORDS_GETTER("order.field.audit_state"));
	//����
	API_DTO_FIELD_DEFAULT(List<GroupDetailDTO::Wrapper>, group, ZH_WORDS_GETTER("order.field.group"));
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_ORDERDETAILDTO_H_

