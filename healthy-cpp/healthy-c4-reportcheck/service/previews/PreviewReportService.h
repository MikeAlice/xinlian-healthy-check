#pragma once
#ifndef _PREVIEWREPORT_SERVICE_
#define _PREVIEWREPORT_SERVICE_
#include <list>
#include "domain/vo/previews/PreviewReportVO.h"
#include "domain/query/previews/PreviewReportQuery.h"
#include "domain/dto/previews/PreviewReportDTO.h"

/**
 * ������˷���ʵ��
 */
class PreviewReportService
{
public:
	// ͨ������id��ѯ����
	PreviewReportDTO::Wrapper listId(const PreviewReportQuery::Wrapper& query);
};

#endif // !_PREVIEWREPORT_SERVICE_