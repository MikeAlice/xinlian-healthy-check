#pragma once

#ifndef _QUERYPERSONCONTROLLER_H_
#define _QUERYPERSONCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "../../domain/query/get-order-person/OrderPersonQuery.h"
#include "../../domain/dto/get-order-person/OrderPersonDTO.h"
#include "../../domain/vo/get-order-person/OrderPersonVO.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

class QueryPersonController : public oatpp::web::server::api::ApiController
{
	//����������������
	API_ACCESS_DECLARE(QueryPersonController);
public://����ӿ�
	//�����ѯ�ӿ�����
	ENDPOINT_INFO(queryPerson) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("order.get-person.summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(OrderPersonListPageJsonVO);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������
		// ����id
		API_DEF_ADD_QUERY_PARAMS(String, "groupId", ZH_WORDS_GETTER("person.field.group_id"),"",true);
		// ����id
		API_DEF_ADD_QUERY_PARAMS(String, "orderId", ZH_WORDS_GETTER("person.field.order_id"), "", false);
	}
	//�����ҳ��ѯ��λ�б�ӿ�
	ENDPOINT(API_M_GET, "/sales/order/get-person", queryPerson, QUERIES(QueryParams, params), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(uq, OrderPersonQuery, params);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQueryPerson(uq));
	}
private://����ӿ�ִ�к���
	OrderPersonListPageJsonVO::Wrapper execQueryPerson(const OrderPersonQuery::Wrapper& query);
};



#include OATPP_CODEGEN_BEGIN(ApiController)

#endif // !_QUERYPERSONCONTROLLER_H_

