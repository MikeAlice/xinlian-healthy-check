#pragma once

#ifndef _CONFIRMORDERCONTROLLER_H_
#define _CONFIRMORDERCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "domain/GlobalInclude.h"

// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * 订单确认    负责人：jimyy
 */
class ConfirmOrderController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(ConfirmOrderController);
public: // 3 定义接口
// 	// 3.1 定义接口描述
// 	// 3.2 定义接口处理
	ENDPOINT_INFO(confirmOrder) {
		// 定义标题和返回类型以及授权支持
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("order.confirm.summary"), StringJsonVO::Wrapper);
		// 定义其他路径参数说明
		API_DEF_ADD_PATH_PARAMS(String, "id", ZH_WORDS_GETTER("order.field.id"), "1", true);
	}
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/sales/order/confirm/{id}", confirmOrder, PATH(String, id), execConfirmOrder(id, authObject->getPayload()));

private: // 定义接口执行函数
	StringJsonVO::Wrapper execConfirmOrder(const String& id, const PayloadDTO& payload);

};

#include OATPP_CODEGEN_END(ApiController) //<- End Codegen

#endif // !_CONFIRMORDERCONTROLLER_H_
