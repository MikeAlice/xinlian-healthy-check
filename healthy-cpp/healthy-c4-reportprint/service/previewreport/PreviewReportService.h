#pragma once
#ifndef _MEDEXAMPRINTREPORT_SERVICE_
#define _MEDEXAMPRINTREPORT_SERVICE_
#include <list>
#include "domain/vo/PreviewReportVO.h"
#include "domain/query/PreviewReportQuery.h"
#include "domain/dto/PreviewReportDTO.h"

/**
 * 报告打印中报告预览service
 * 负责人：小智
 */
class PreviewReportService
{
public:
	// 查询所有数据
	PreviewReportDTO::Wrapper listId(const PreviewReportQuery::Wrapper& query);
};

#endif // !_MEDEXAMPRINTREPORT_SERVICE_

