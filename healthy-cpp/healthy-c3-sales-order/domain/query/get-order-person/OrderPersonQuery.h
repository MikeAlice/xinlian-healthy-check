#pragma once
#ifndef _ORDERQUERY_H_
#define _ORDERQUERY_H_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/*
* ��λ��ҳ��ѯʵ��
*/

class OrderPersonQuery : public PageQuery
{
	//�����ʼ��
	DTO_INIT(OrderPersonQuery, PageQuery);
	// ����id
	API_DTO_FIELD_DEFAULT(String, groupId, ZH_WORDS_GETTER("group.field.id"));
	// ����id
	API_DTO_FIELD_DEFAULT(String, orderId, ZH_WORDS_GETTER("order.field.id"));
};


#include OATPP_CODEGEN_BEGIN(DTO)

#endif // !_ORDERQUERY_H_
