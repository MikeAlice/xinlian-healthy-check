#pragma once
#ifndef _PREVIEWREPORT_SERVICE_
#define _PREVIEWREPORT_SERVICE_
#include <list>
#include "domain/vo/previews/PreviewReportVO.h"
#include "domain/query/previews/PreviewReportQuery.h"
#include "domain/dto/previews/PreviewReportDTO.h"

/**
 * 报告审核服务实现
 */
class PreviewReportService
{
public:
	// 通过姓名id查询数据
	PreviewReportDTO::Wrapper listId(const PreviewReportQuery::Wrapper& query);
};

#endif // !_PREVIEWREPORT_SERVICE_