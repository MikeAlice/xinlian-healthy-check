#pragma once
#ifndef _REPORTSTATISTICS_SERVICE_
#define _REPORTSTATISTICS_SERVICE_
#include <list>
#include "domain/vo/ReportStatistics/ReportStatisticsVO.h"
#include "domain/query/ReportStatistics/ReportStatisticsQuery.h"
#include "domain/dto/ReportStatistics/ReportStatisticsDTO.h"

/**
 * ʾ������ʵ�֣���ʾ������ʾ������ʵ��
 */
class PhysicalExaminationPersonnelService
{
public:
	// ��ҳ��ѯ��������
	PhysicalExaminationPersonnelPageDTO::Wrapper listAll(const ReportStatisticsQuery::Wrapper& query);
};

class ReviewPersonnelService
{
public:
	// ��ҳ��ѯ��������
	ReviewPersonnelPageDTO::Wrapper listAll(const ReportStatisticsQuery::Wrapper& query);
};

class ReviewResultsService
{
public:
	// ��ҳ��ѯ��������
	ReviewResultsPageDTO::Wrapper listAll(const ReportStatisticsQuery::Wrapper& query);
};

#endif // !_SAMPLE_SERVICE_