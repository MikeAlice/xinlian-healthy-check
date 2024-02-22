#pragma once

#ifndef _REMOVEORDERCONTROLLER_H_
#define _REMOVEORDERCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "domain/GlobalInclude.h"

// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * 删除订单    负责人：Adam
 */
/*
* 修改：唯一标识对应数据库id字段
* 删除时要删除多个表，不止t_group_order
* 删除操作为del_flag标记为1，不删除数据
*/
class RemoveOrderController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(RemoveOrderController);
	// 3 定义接口
public:

	// 3.1 定义删除接口描述
	ENDPOINT_INFO(removeOrder) {
		// 定义标题和返回类型以及授权支持
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("order.delete.summary"), StringJsonVO::Wrapper);
		// 定义其他路径参数说明
		API_DEF_ADD_PATH_PARAMS(String, "id", ZH_WORDS_GETTER("order.field.id"), "1", true);
	}
	// 3.2 定义删除接口处理
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/sales/order/{id}", removeOrder, PATH(String, id), execRemoveOrder(id, authObject->getPayload()));
private:
	// 删除数据
	StringJsonVO::Wrapper execRemoveOrder(const String& id, const PayloadDTO& payload);
};

// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen

#endif // !_REMOVEORDERCONTROLLER_H_