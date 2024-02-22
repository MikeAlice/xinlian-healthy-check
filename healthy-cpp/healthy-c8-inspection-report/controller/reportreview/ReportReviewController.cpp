#include "ReportReviewController.h"
#include "stdafx.h"
#include "../../service/reportreview/ReportReviewService.h"
StringJsonVO::Wrapper ReportReviewController::execModifyReportReview(const List<ReportReviewDTO::Wrapper>& dtoArray)
{
	// ���巵�����ݶ���
	auto jvo = StringJsonVO::createShared();
	auto& dtos = *dtoArray.get();
	for (auto i = dtos.begin(); i != dtos.end(); i++)
	{
		ReportReviewDTO::Wrapper dto = *i;
		// ����У��
		if (!dto->testNum)
		{
			jvo->init(String(-1), RS_PARAMS_INVALID);
			return jvo;
		}
		// ����һ��Service
		ReportReviewService service;
		// ִ�������޸�
		if (service.updateData(dto)) {
			jvo->success(dto->testNum);
		}
		else
		{
			jvo->fail(dto->testNum);
		}
		// ��Ӧ���
	}
	return jvo;
}
