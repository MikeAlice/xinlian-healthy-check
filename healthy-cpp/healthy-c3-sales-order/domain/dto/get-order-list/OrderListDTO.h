#pragma once

#ifndef _ORDERLISTDTO_H
#define _ORDERLISTDTO_H

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/*
* �����б������ݶ���ʵ��
*/
class OrderListDTO : public oatpp::DTO
{
	//�����ʼ��
	DTO_INIT(OrderListDTO, DTO);

	//����
	API_DTO_FIELD_DEFAULT(String, id, ZH_WORDS_GETTER("order.field.id"));
	//�������
	API_DTO_FIELD_DEFAULT(String, orderCode, ZH_WORDS_GETTER("order.field.order_code"));
	//�ż�����
	API_DTO_FIELD_DEFAULT(String, physicalType, ZH_WORDS_GETTER("order.field.physical_type"));
	//֧��״̬
	API_DTO_FIELD_DEFAULT(Int32, payStatus, ZH_WORDS_GETTER("order.field.pay_status"));
	//�ż쵥λid
	API_DTO_FIELD_DEFAULT(String, groupUnitId, ZH_WORDS_GETTER("order.field.group_unit_id"));
	//�ż쵥λ����
	API_DTO_FIELD_DEFAULT(String, groupUnitName, ZH_WORDS_GETTER("order.field.group_unit_name"));
	//ǩ������
	API_DTO_FIELD_DEFAULT(String, signingTime, ZH_WORDS_GETTER("order.field.signing_time"));
	//���״̬ -1 ����� 0 Ҫ��� 1������ 2��ͨ�� 3δͨ��
	API_DTO_FIELD_DEFAULT(Int32, auditState, ZH_WORDS_GETTER("order.field.audit_state"));

};

/*
	��λ�б��ҳ����ʵ��
*/
class OrderListPageDTO :public PageDTO< OrderListDTO::Wrapper>
{
	DTO_INIT(OrderListPageDTO, PageDTO< OrderListDTO::Wrapper>);

};
#include OATPP_CODEGEN_END(DTO)
#endif