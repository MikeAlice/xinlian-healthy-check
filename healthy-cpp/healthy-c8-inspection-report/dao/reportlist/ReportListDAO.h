#pragma once
#ifndef _REPORTLIST_DAO_
#define _REPORTLIST_DAO_
#include "BaseDAO.h"
#include "../../domain/do/reportlist/ReportListDO.h"
#include "../../domain/query/reportlist/ReportListQuery.h"

/**
 * ʾ�������ݿ����ʵ��
 */
class ReportListDAO : public BaseDAO
{
public:
	// ͳ����������
	uint64_t count(const ReportListQuery::Wrapper& query);
	// ��ҳ��ѯ����
	list<ReportListDO> selectWithPage(const ReportListQuery::Wrapper& query);
};
#endif // !_REPORTLIST_DAO_
