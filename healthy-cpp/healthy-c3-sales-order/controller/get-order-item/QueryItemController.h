#pragma once

#ifndef _QUERYITEMCONTROLLER_H_
#define _QUERYITEMCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "../../domain/query/get-order-item/OrderItemQuery.h"
#include "../../domain/dto/get-order-item/OrderItemDTO.h"
#include "../../domain/vo/get-order-item/OrderItemVO.h"

// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * 获取订单体检项目信息    负责人：Adam
 */

class QueryItemController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(QueryItemController);
	// 3 定义接口
public:
	// 3.1 定义查询接口描述
	ENDPOINT_INFO(queryItem) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("order.get-item.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(OrderItemJsonVO);
		// 定义其他查询参数描述
		// 订单id
		API_DEF_ADD_QUERY_PARAMS(String, "groupOrderId", ZH_WORDS_GETTER("item.field.group_order_id"), "56516616", true);
		// 分组id
		API_DEF_ADD_QUERY_PARAMS(String, "groupId", ZH_WORDS_GETTER("item.field.group_id"), "516153166", true);
	}
	// 3.2 定义查询接口处理
	ENDPOINT(API_M_GET, "/sales/order/get-item", queryItem, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(userQuery, OrderItemQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryItem(userQuery, authObject->getPayload()));
	}
private:
	//查询数据
	OrderItemJsonVO::Wrapper execQueryItem(const OrderItemQuery::Wrapper& query, const PayloadDTO& payload);
};

// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // !_QUERYITEMCONTROLLER_H_
