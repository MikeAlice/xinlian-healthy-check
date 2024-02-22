#pragma once

#ifndef _ORDERVIEWAPPROVAL_CONTROLLER_
#define _ORDERVIEWAPPROVAL_CONTROLLER_
#include"../../../lib-oatpp/include/domain/vo/BaseJsonVO.h"
#include "../../domain/dto/get-order-approval/OrderApprovalDTO.h"
#include "../../domain/vo/get-order-approval/OrderApprovalJsonVO.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

/**
 * 查看审批信息    负责人：无敌霸王龙
 */
class QueryOrderApprovalController :public oatpp::web::server::api::ApiController
{
	API_ACCESS_DECLARE(QueryOrderApprovalController);
public:
// 	ENDPOINT_INFO(queryOrderApproval) {
// 		// 定义接口标题
// 		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("order.approval.summary"));
// 		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
// 		API_DEF_ADD_AUTH();
// 		// 定义响应参数格式
// 		API_DEF_ADD_RSP_JSON_WRAPPER(OrderviewapprovalJsonVO);
// 		// 定义分页查询参数描述
// 		API_DEF_ADD_PAGE_PARAMS();
// 		// 定义其他查询参数描述
// 		  //查询类型
// 		API_DEF_ADD_QUERY_PARAMS(String, "type", ZH_WORDS_GETTER("order.field.type"),"type",true);
// 		  //单位名称
// 		API_DEF_ADD_QUERY_PARAMS(String, "name", ZH_WORDS_GETTER("order.field.name"),"peking",false);
// 		  //体检日期
// 		API_DEF_ADD_QUERY_PARAMS(String, "delivery_time", ZH_WORDS_GETTER("order.field.delivery_time"),"2020-9-9",true);
// 		  //审核状态
// 		API_DEF_ADD_QUERY_PARAMS(String, "status", ZH_WORDS_GETTER("order.field.status"),"finish",false);
// 		
// 	}
// 	//定义查询接口
// 	
// 	ENDPOINT(API_M_GET, "sales/order/get-approval", queryOrderApproval, QUERIES(QueryParams, params),API_HANDLER_AUTH_PARAME) {
// 		// 解析查询参数为Query领域模型
// 		API_HANDLER_QUERY_PARAM(userQuery, Orderviewapprovalquery, params);
// 		// 呼叫执行函数响应结果
// 		API_HANDLER_RESP_VO(execQueryOrderApproval(userQuery));
// 	}
	ENDPOINT_INFO(queryOrderApproval) {
		// 定义标题和返回类型以及授权支持
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("order.approval.summary"), OrderApprovalJsonVO::Wrapper);
		// 定义其他路径参数说明
		API_DEF_ADD_PATH_PARAMS(String, "orderId", ZH_WORDS_GETTER("flow.field.group_order_id"), "1", true);
	}
	API_HANDLER_ENDPOINT_AUTH(API_M_GET, "/sales/order/get-approval/{orderId}", queryOrderApproval, PATH(String, orderId), execQueryOrderApproval(orderId));
private:
	OrderApprovalJsonVO::Wrapper execQueryOrderApproval(const String& orderId);
};
#include OATPP_CODEGEN_END(ApiController)
#endif
