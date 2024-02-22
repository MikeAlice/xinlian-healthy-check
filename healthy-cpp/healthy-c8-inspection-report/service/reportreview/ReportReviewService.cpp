#include "stdafx.h"
#include "ReportReviewService.h"
#include "../../dao/reportreview/ReportReviewDAO.h"

bool ReportReviewService::updateData(const ReportReviewDTO::Wrapper& dto)
{
	// 组装DO数据
	ReportReviewDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, TestNum, testNum);
	// 执行数据修改
	ReportReviewDAO dao;
	return dao.update(data) == 1;
}