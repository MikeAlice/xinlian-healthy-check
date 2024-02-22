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
	//定义控制器访问入口
	API_ACCESS_DECLARE(QueryOrderListController); 
public:
	// 定义查询接口描述
	ENDPOINT_INFO(queryOrderList) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("order.get-list.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(OrderListPageJsonVO);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "physicalType", ZH_WORDS_GETTER("order.field.physical_type"),1, true);
		API_DEF_ADD_QUERY_PARAMS(Int32, "payStatus", ZH_WORDS_GETTER("order.field.pay_status"),0,true);
		API_DEF_ADD_QUERY_PARAMS(String, "startDate", ZH_WORDS_GETTER("order.field.start_date"), GetDate::getPreviousMonthDate(), false);
		API_DEF_ADD_QUERY_PARAMS(String, "endDate", ZH_WORDS_GETTER("order.field.end_date"), GetDate::getCurrentDate(), false);
		API_DEF_ADD_QUERY_PARAMS(String, "searchKey", ZH_WORDS_GETTER("order.field.search_key"), "" ,false);
	}


	//定义分页查询接口
	ENDPOINT(API_M_GET, "/sales/order/query-order", queryOrderList, QUERIES(QueryParams, params), API_HANDLER_AUTH_PARAME)
	{
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(oq, OrderListQuery, params);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryOrderList(oq));
	}
private:
	//定义接口执行函数
	OrderListPageJsonVO::Wrapper execQueryOrderList(const OrderListQuery::Wrapper& query);
};

#include OATPP_CODEGEN_END(ApiController)
#endif // !_QUERYORDERLISTCONTROLLER_H_
