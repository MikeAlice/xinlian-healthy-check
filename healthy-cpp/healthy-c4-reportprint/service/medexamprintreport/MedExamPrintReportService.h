#pragma once
#ifndef _MEDEXAMPRINTREPORT_SERVICE_
#define _MEDEXAMPRINTREPORT_SERVICE_
#include <list>
#include "domain/vo/MedExamPrintReportVO.h"
#include "domain/query/MedExamPrintReportQuery.h"
#include "domain/dto/MedExamPrintReportDTO.h"

/**
 * 报告打印中获取体检人员service
 * 负责人：小智
 */
class MedExamPrintReportService
{
public:
	// 分页查询所有数据
	MedExamPrintReportPageDTO::Wrapper listAll(const MedExamPrintReportQuery::Wrapper& query);
};

#endif // !_MEDEXAMPRINTREPORT_SERVICE_

