#ifndef _REPORTREVIEW_SERVICE_
#define _REPORTREVIEW_SERVICE_
#include "domain/dto/reportreview/ReportReviewDTO.h"


/**
 * ��˴Ӽ챨�����ʵ��
 */
class ReportReviewService
{
public:
	// �޸�����
	bool updateData(const ReportReviewDTO::Wrapper& dto);
};

#endif