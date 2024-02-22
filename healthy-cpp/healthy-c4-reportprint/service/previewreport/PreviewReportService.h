#pragma once
#ifndef _MEDEXAMPRINTREPORT_SERVICE_
#define _MEDEXAMPRINTREPORT_SERVICE_
#include <list>
#include "domain/vo/PreviewReportVO.h"
#include "domain/query/PreviewReportQuery.h"
#include "domain/dto/PreviewReportDTO.h"

/**
 * �����ӡ�б���Ԥ��service
 * �����ˣ�С��
 */
class PreviewReportService
{
public:
	// ��ѯ��������
	PreviewReportDTO::Wrapper listId(const PreviewReportQuery::Wrapper& query);
};

#endif // !_MEDEXAMPRINTREPORT_SERVICE_

