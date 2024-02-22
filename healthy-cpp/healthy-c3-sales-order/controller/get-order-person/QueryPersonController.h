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
	//定义控制器访问入口
	API_ACCESS_DECLARE(QueryPersonController);
public://定义接口
	//定义查询接口描述
	ENDPOINT_INFO(queryPerson) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("order.get-person.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(OrderPersonListPageJsonVO);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述
		// 分组id
		API_DEF_ADD_QUERY_PARAMS(String, "groupId", ZH_WORDS_GETTER("person.field.group_id"),"",true);
		// 订单id
		API_DEF_ADD_QUERY_PARAMS(String, "orderId", ZH_WORDS_GETTER("person.field.order_id"), "", false);
	}
	//定义分页查询单位列表接口
	ENDPOINT(API_M_GET, "/sales/order/get-person", queryPerson, QUERIES(QueryParams, params), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(uq, OrderPersonQuery, params);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryPerson(uq));
	}
private://定义接口执行函数
	OrderPersonListPageJsonVO::Wrapper execQueryPerson(const OrderPersonQuery::Wrapper& query);
};



#include OATPP_CODEGEN_BEGIN(ApiController)

#endif // !_QUERYPERSONCONTROLLER_H_

