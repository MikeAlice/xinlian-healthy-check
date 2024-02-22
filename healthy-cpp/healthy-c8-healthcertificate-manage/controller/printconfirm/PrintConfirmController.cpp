#include "PrintConfirmController.h"
#include "stdafx.h"
#include "../../service/printconfirm/PrintConfirmService.h"
StringJsonVO::Wrapper PrintConfirmController::execModifyPrintConfirm(const List<String>& dto)
{
	// 定义返回数据对象
	auto jvo = StringJsonVO::createShared();

	auto& id = *dto.get();

	for (auto i = id.begin(); i != id.end(); i++)
	{
		String orderid = *i;
		// 参数校验
		if (!orderid)
		{
			jvo->init(String("wrong"), RS_PARAMS_INVALID);
			return jvo;
		}
		// 定义一个Service
		PrintConfirmService service;

		// 执行数据修改
		if (service.updateData(orderid)) {
			jvo->success(orderid);
		}
		else
		{
			jvo->fail(orderid);

		}
	}
	// 响应结果
	return jvo;
}
