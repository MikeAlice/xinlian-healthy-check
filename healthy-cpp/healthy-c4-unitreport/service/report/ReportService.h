#ifndef _SAMPLE_SERVICE_
#define _SAMPLE_SERVICE_
#include <list>
#include "domain/vo/report/ReportVO.h"
#include "domain/query/report/ReportQuery.h"
#include "domain/dto/report/ReportDTO.h"

/**
 * 示例服务实现，演示基础的示例服务实现
 */
class ReportService
{
public:
	//通过ID查询数据
	ReportDTO::Wrapper ReportService::listAll(const IDQuery::Wrapper& query);
};

#endif // !_SAMPLE_SERVICE_






