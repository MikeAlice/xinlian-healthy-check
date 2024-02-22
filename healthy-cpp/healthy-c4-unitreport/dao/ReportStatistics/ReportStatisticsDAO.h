#pragma once
#ifndef _REPORTSTATISTICS_DAO_
#define _REPORTSTATISTICS_DAO_
#include "BaseDAO.h"
#include "../../domain/do/ReportStatistics/ReportStatisticsDO.h"
#include "../../domain/query/ReportStatistics/ReportStatisticsQuery.h"

/**
 * ʾ�������ݿ����ʵ��
 */
class ReportStatisticsDAO : public BaseDAO
{
public:
	// ͳ�������Ա��������
	uint64_t countPhysicalExaminationPersonnel(const ReportStatisticsQuery::Wrapper& query);
	// ͳ�Ƹ�����Ա��������
	uint64_t countReviewPersonnel(const ReportStatisticsQuery::Wrapper& query);
	// ͳ�Ƹ�������������
	uint64_t countReviewResults(const ReportStatisticsQuery::Wrapper& query);
	// ��ҳ��ѯ�����Ա���ܱ�����
	list<PhysicalExaminationPersonnelDO> selectWithPhysicalExaminationPersonnelPage(const ReportStatisticsQuery::Wrapper& query);
	// ��ҳ��ѯ������Ա���ܱ�����
	list<ReviewPersonnelDO> selectWithReviewPersonnelPage(const ReportStatisticsQuery::Wrapper& query);
	// ��ҳ��ѯ���������ܱ�����
	list<ReviewResultsDO> selectWithReviewResultsPage(const ReportStatisticsQuery::Wrapper& query);
};
#endif // !_SAMPLE_DAO_