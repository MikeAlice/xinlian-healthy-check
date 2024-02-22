#ifndef _REPORTREVIEW_SERVICE_
#define _REPORTREVIEW_SERVICE_
#include "domain/dto/reportreview/ReportReviewDTO.h"


/**
 * 审核从检报告服务实现
 */
class ReportReviewService
{
public:
	// 修改数据
	bool updateData(const ReportReviewDTO::Wrapper& dto);
};

#endif