#pragma once
#ifndef _PREVIEWREPORT_DAO_
#define _PREVIEWREPORT_DAO_
#include "BaseDAO.h"
#include "../../domain/do/previews/PreviewReportDO.h"
#include "../../domain/query/previews/PreviewReportQuery.h"

/**
 * 示例表数据库操作实现
 */
class PreviewReportDAO : public BaseDAO
{
public:
	// 通过姓名id查询数据
	list<PreviewReportDO> selectByName(const string& name);
};
#endif // !_PREVIEWREPORT_DAO_