#ifndef _SAMPLE_SERVICE_
#define _SAMPLE_SERVICE_
#include <list>
#include "domain/vo/report/ReportVO.h"
#include "domain/query/report/ReportQuery.h"
#include "domain/dto/report/ReportDTO.h"

/**
 * ʾ������ʵ�֣���ʾ������ʾ������ʵ��
 */
class ReportService
{
public:
	//ͨ��ID��ѯ����
	ReportDTO::Wrapper ReportService::listAll(const IDQuery::Wrapper& query);
};

#endif // !_SAMPLE_SERVICE_






