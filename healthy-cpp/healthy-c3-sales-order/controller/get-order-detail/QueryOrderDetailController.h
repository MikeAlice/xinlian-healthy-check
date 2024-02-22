#pragma once

#ifndef _QUERYORDERDETAILCONTROLLER_H_
#define _QUERYORDERDETAILCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "domain/GlobalInclude.h"
#include "../../domain/vo/get-order-detail/OrderDetailVO.h"

#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen
/**
 * 获取订单详情    负责人：星星果
 */
/** 
* 修改：查询某条订单的详情，参数只要订单id就可以了
* 把参数id放在path里或者Query里都行
*/
class QueryOrderDetailController : public oatpp::web::server::api::ApiController
{
	// 添加访问定义
	API_ACCESS_DECLARE(QueryOrderDetailController);
public:
	ENDPOINT_INFO(queryOrderDetail) {
		// 定义标题和返回类型以及授权支持
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("order.get-detail.summary"), OrderDetailJsonVO::Wrapper);
		// 定义其他路径参数说明
		API_DEF_ADD_PATH_PARAMS(String, "id", ZH_WORDS_GETTER("order.field.id"), "1", true);
	}
	API_HANDLER_ENDPOINT_AUTH(API_M_GET, "/sales/order/get-detail/{id}", queryOrderDetail, PATH(String, id), execQueryOrderDetail(id));
	 
private:
	// 查询所有
	OrderDetailJsonVO::Wrapper execQueryOrderDetail(const String& id);
	
};

#include OATPP_CODEGEN_END(ApiController) //<- End Codegen

#endif // !_QUERYORDERDETAILCONTROLLER_H_

