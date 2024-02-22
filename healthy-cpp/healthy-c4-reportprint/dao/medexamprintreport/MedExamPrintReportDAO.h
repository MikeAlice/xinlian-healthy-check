#pragma once
#ifndef _MEDEXAMPRINTREPORT_DAO_
#define _MEDEXAMPRINTREPORT_DAO_
#include "BaseDAO.h"
#include "../../domain/do/medexamprintreport/MedExamPrintReportDO.h"
#include "../../domain/query/MedExamPrintReportQuery.h"

/**
 * 获取体检人员信息查询
 * 负责人：小智
 */
class MedExamPrintReportDAO : public BaseDAO
{
public:
	// 统计数据条数
	uint64_t count(const MedExamPrintReportQuery::Wrapper& query);
	// 分页查询数据
	list<MedExamPrintReportDO> selectWithPage(const MedExamPrintReportQuery::Wrapper& query);
	// 通过姓名查询数据
	list<MedExamPrintReportDO> selectByName(const string& name);
};
#endif // !_MEDEXAMPRINTREPORT_DAO_
