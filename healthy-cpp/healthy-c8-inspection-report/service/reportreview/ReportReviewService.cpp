#include "stdafx.h"
#include "ReportReviewService.h"
#include "../../dao/reportreview/ReportReviewDAO.h"

bool ReportReviewService::updateData(const ReportReviewDTO::Wrapper& dto)
{
	// ��װDO����
	ReportReviewDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, TestNum, testNum);
	// ִ�������޸�
	ReportReviewDAO dao;
	return dao.update(data) == 1;
}