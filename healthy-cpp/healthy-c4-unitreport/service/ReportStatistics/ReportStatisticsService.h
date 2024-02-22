#pragma once
#ifndef _REPORTSTATISTICS_SERVICE_
#define _REPORTSTATISTICS_SERVICE_
#include <list>
#include "domain/vo/ReportStatistics/ReportStatisticsVO.h"
#include "domain/query/ReportStatistics/ReportStatisticsQuery.h"
#include "domain/dto/ReportStatistics/ReportStatisticsDTO.h"

/**
 * 示例服务实现，演示基础的示例服务实现
 */
class PhysicalExaminationPersonnelService
{
public:
	// 分页查询所有数据
	PhysicalExaminationPersonnelPageDTO::Wrapper listAll(const ReportStatisticsQuery::Wrapper& query);
};

class ReviewPersonnelService
{
public:
	// 分页查询所有数据
	ReviewPersonnelPageDTO::Wrapper listAll(const ReportStatisticsQuery::Wrapper& query);
};

class ReviewResultsService
{
public:
	// 分页查询所有数据
	ReviewResultsPageDTO::Wrapper listAll(const ReportStatisticsQuery::Wrapper& query);
};

#endif // !_SAMPLE_SERVICE_