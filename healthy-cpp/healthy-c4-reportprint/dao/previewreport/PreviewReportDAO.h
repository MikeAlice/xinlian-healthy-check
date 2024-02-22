#pragma once
#ifndef _PREVIEWREPORT_DAO_
#define _PREVIEWREPORT_DAO_
#include "BaseDAO.h"
#include "../../domain/do/previewreport/PreviewReportDO.h"
#include "../../domain/query/PreviewReportQuery.h"

/**
 * 报告预览数据库操作实现
 * 负责人：小智
 */
class PreviewReportDAO : public BaseDAO
{
public:
	// 通过姓名查询数据
	list<PreviewReportDO> selectByName(const string& nameID);
};
#endif // !_PREVIEWREPORT_DAO_
