#include "PrintMoreController.h"
#include "../../service/printmore/PrintMoreService.h"
#include "stdafx.h"
ResultJsonVO::Wrapper PrintMoreController::execDownloadPrintMore(const List<PrintMoreDTO::Wrapper>& dto)
{
	// 定义返回数据对象

	auto jvo = ResultJsonVO::createShared();
	PrintMoreService service;

	auto res = ResultDTO::createShared();
	// 参数校验
	bool succ = true;

	// 非空校验
	for (auto iter = dto->begin(); iter != dto->end(); iter++) {
		if ((*iter)->id)
		{
			String str = service.downloadPrintMore((*iter)->id);
			res->addData(str);
		}
		else {
			String str = "";
			res->addData(str);
		}
	}

	//响应结果
	if (succ) jvo->success(res);
	else jvo->fail(res);

	return jvo;
}