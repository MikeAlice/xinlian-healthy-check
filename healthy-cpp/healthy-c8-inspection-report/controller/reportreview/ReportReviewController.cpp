#include "ReportReviewController.h"
#include "stdafx.h"
#include "../../service/reportreview/ReportReviewService.h"
StringJsonVO::Wrapper ReportReviewController::execModifyReportReview(const List<ReportReviewDTO::Wrapper>& dtoArray)
{
	// 定义返回数据对象
	auto jvo = StringJsonVO::createShared();
	auto& dtos = *dtoArray.get();
	for (auto i = dtos.begin(); i != dtos.end(); i++)
	{
		ReportReviewDTO::Wrapper dto = *i;
		// 参数校验
		if (!dto->testNum)
		{
			jvo->init(String(-1), RS_PARAMS_INVALID);
			return jvo;
		}
		// 定义一个Service
		ReportReviewService service;
		// 执行数据修改
		if (service.updateData(dto)) {
			jvo->success(dto->testNum);
		}
		else
		{
			jvo->fail(dto->testNum);
		}
		// 响应结果
	}
	return jvo;
}
