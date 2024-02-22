#include "stdafx.h"
#include "RemoveOrderController.h"

/**
 * 删除订单    负责人：Adam
 */
StringJsonVO::Wrapper RemoveOrderController::execRemoveOrder(const String& orderCode, const PayloadDTO& payload)
{
	// 定义返回数据对象
	auto jvo = StringJsonVO::createShared();
	// 响应结果
	return jvo;
}
