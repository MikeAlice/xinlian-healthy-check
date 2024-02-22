#pragma once

#ifndef _QUERYITEMCONTROLLER_H_
#define _QUERYITEMCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "../../domain/query/get-order-item/OrderItemQuery.h"
#include "../../domain/dto/get-order-item/OrderItemDTO.h"
#include "../../domain/vo/get-order-item/OrderItemVO.h"

// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * ��ȡ���������Ŀ��Ϣ    �����ˣ�Adam
 */

class QueryItemController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// 2 ����������������
	API_ACCESS_DECLARE(QueryItemController);
	// 3 ����ӿ�
public:
	// 3.1 �����ѯ�ӿ�����
	ENDPOINT_INFO(queryItem) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("order.get-item.summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(OrderItemJsonVO);
		// ����������ѯ��������
		// ����id
		API_DEF_ADD_QUERY_PARAMS(String, "groupOrderId", ZH_WORDS_GETTER("item.field.group_order_id"), "56516616", true);
		// ����id
		API_DEF_ADD_QUERY_PARAMS(String, "groupId", ZH_WORDS_GETTER("item.field.group_id"), "516153166", true);
	}
	// 3.2 �����ѯ�ӿڴ���
	ENDPOINT(API_M_GET, "/sales/order/get-item", queryItem, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(userQuery, OrderItemQuery, queryParams);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQueryItem(userQuery, authObject->getPayload()));
	}
private:
	//��ѯ����
	OrderItemJsonVO::Wrapper execQueryItem(const OrderItemQuery::Wrapper& query, const PayloadDTO& payload);
};

// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // !_QUERYITEMCONTROLLER_H_
