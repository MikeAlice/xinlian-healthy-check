#pragma once
#ifndef _MEDEXAMPRINTREPORT_SERVICE_
#define _MEDEXAMPRINTREPORT_SERVICE_
#include <list>
#include "domain/vo/MedExamPrintReportVO.h"
#include "domain/query/MedExamPrintReportQuery.h"
#include "domain/dto/MedExamPrintReportDTO.h"

/**
 * �����ӡ�л�ȡ�����Աservice
 * �����ˣ�С��
 */
class MedExamPrintReportService
{
public:
	// ��ҳ��ѯ��������
	MedExamPrintReportPageDTO::Wrapper listAll(const MedExamPrintReportQuery::Wrapper& query);
};

#endif // !_MEDEXAMPRINTREPORT_SERVICE_

