#pragma once

#ifndef _ORDERLISTQUERY_H_
#define _ORDERLISTQUERY_H_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ��ȡ���������б�����+��ҳ��    �����ˣ�Chloe
 */

class OrderListQuery : public PageQuery
{
	//�����ʼ��
	DTO_INIT(OrderListQuery, PageQuery);
	//�������
	API_DTO_FIELD_DEFAULT(String, physicalType, ZH_WORDS_GETTER("order.field.physical_type"));
	//����״̬
	API_DTO_FIELD_DEFAULT(Int32, payStatus, ZH_WORDS_GETTER("order.field.pay_status"));
	//��ʼ����
	API_DTO_FIELD_DEFAULT(String, startDate, ZH_WORDS_GETTER("order.field.start_date"));
	//��������
	API_DTO_FIELD_DEFAULT(String, endDate, ZH_WORDS_GETTER("order.field.end_date"));
	//�ؼ���
	API_DTO_FIELD_DEFAULT(String, searchKey, ZH_WORDS_GETTER("order.field.search_key"));
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_ORDERLISTQUERY_H_


