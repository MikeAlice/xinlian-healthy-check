#pragma once
#ifndef _REPORTSTATISTICS_DAO_
#define _REPORTSTATISTICS_DAO_
#include "BaseDAO.h"
#include "../../domain/do/ReportStatistics/ReportStatisticsDO.h"
#include "../../domain/query/ReportStatistics/ReportStatisticsQuery.h"

/**
 * 示例表数据库操作实现
 */
class ReportStatisticsDAO : public BaseDAO
{
public:
	// 统计体检人员数据条数
	uint64_t countPhysicalExaminationPersonnel(const ReportStatisticsQuery::Wrapper& query);
	// 统计复查人员数据条数
	uint64_t countReviewPersonnel(const ReportStatisticsQuery::Wrapper& query);
	// 统计复查结果数据条数
	uint64_t countReviewResults(const ReportStatisticsQuery::Wrapper& query);
	// 分页查询体检人员汇总表数据
	list<PhysicalExaminationPersonnelDO> selectWithPhysicalExaminationPersonnelPage(const ReportStatisticsQuery::Wrapper& query);
	// 分页查询复查人员汇总表数据
	list<ReviewPersonnelDO> selectWithReviewPersonnelPage(const ReportStatisticsQuery::Wrapper& query);
	// 分页查询复查结果汇总表数据
	list<ReviewResultsDO> selectWithReviewResultsPage(const ReportStatisticsQuery::Wrapper& query);
};
#endif // !_SAMPLE_DAO_