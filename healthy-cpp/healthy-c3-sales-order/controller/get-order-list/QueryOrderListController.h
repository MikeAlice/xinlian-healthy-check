#pragma once

#ifndef _QUERYORDERLISTCONTROLLER_H_
#define _QUERYORDERLISTCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "../../domain/query/get-order-list/OrderListQuery.h"
#include "../../domain/dto/get-order-list/OrderListDTO.h"
#include "../../domain/vo/get-order-list/OrderListVO.h"
#include "GetDate.h"

#include OATPP_CODEGEN_BEGIN(ApiController)


class QueryOrderListController : public oatpp::web::server::api::ApiController
{
	//����������������
	API_ACCESS_DECLARE(QueryOrderListController); 
public:
	// �����ѯ�ӿ�����
	ENDPOINT_INFO(queryOrderList) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("order.get-list.summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(OrderListPageJsonVO);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(String, "physicalType", ZH_WORDS_GETTER("order.field.physical_type"),1, true);
		API_DEF_ADD_QUERY_PARAMS(Int32, "payStatus", ZH_WORDS_GETTER("order.field.pay_status"),0,true);
		API_DEF_ADD_QUERY_PARAMS(String, "startDate", ZH_WORDS_GETTER("order.field.start_date"), GetDate::getPreviousMonthDate(), false);
		API_DEF_ADD_QUERY_PARAMS(String, "endDate", ZH_WORDS_GETTER("order.field.end_date"), GetDate::getCurrentDate(), false);
		API_DEF_ADD_QUERY_PARAMS(String, "searchKey", ZH_WORDS_GETTER("order.field.search_key"), "" ,false);
	}


	//�����ҳ��ѯ�ӿ�
	ENDPOINT(API_M_GET, "/sales/order/query-order", queryOrderList, QUERIES(QueryParams, params), API_HANDLER_AUTH_PARAME)
	{
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(oq, OrderListQuery, params);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQueryOrderList(oq));
	}
private:
	//����ӿ�ִ�к���
	OrderListPageJsonVO::Wrapper execQueryOrderList(const OrderListQuery::Wrapper& query);
};

#include OATPP_CODEGEN_END(ApiController)
#endif // !_QUERYORDERLISTCONTROLLER_H_
