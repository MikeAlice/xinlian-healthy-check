#pragma once
#ifndef _MEDEXAMPRINTREPORT_DAO_
#define _MEDEXAMPRINTREPORT_DAO_
#include "BaseDAO.h"
#include "../../domain/do/medexamprintreport/MedExamPrintReportDO.h"
#include "../../domain/query/MedExamPrintReportQuery.h"

/**
 * ��ȡ�����Ա��Ϣ��ѯ
 * �����ˣ�С��
 */
class MedExamPrintReportDAO : public BaseDAO
{
public:
	// ͳ����������
	uint64_t count(const MedExamPrintReportQuery::Wrapper& query);
	// ��ҳ��ѯ����
	list<MedExamPrintReportDO> selectWithPage(const MedExamPrintReportQuery::Wrapper& query);
	// ͨ��������ѯ����
	list<MedExamPrintReportDO> selectByName(const string& name);
};
#endif // !_MEDEXAMPRINTREPORT_DAO_
