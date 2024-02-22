#pragma once
#ifndef _CHECKREPORTLIST_DAO_
#define _CHECKREPORTLIST_DAO_
#include "BaseDAO.h"
#include "../../domain/do/checks/CheckReportListDO.h"
#include "../../domain/query/checks/CheckReportQuery.h"

/**
 * ������˻�ȡ�б����ݿ����ʵ��
 * ������ Z
 */
class CheckReportListDAO : public BaseDAO
{
public:
	// ͳ����������
	uint64_t count(const CheckReportQuery::Wrapper& query);
	// ��ҳ��ѯ����
	list<CheckReportListDO> selectWithPage(const CheckReportQuery::Wrapper& query);
};
#endif // !_CHECKREPORTLIST_DAO_
