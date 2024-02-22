#pragma once
#ifndef _PREVIEWREPORT_DAO_
#define _PREVIEWREPORT_DAO_
#include "BaseDAO.h"
#include "../../domain/do/previews/PreviewReportDO.h"
#include "../../domain/query/previews/PreviewReportQuery.h"

/**
 * ʾ�������ݿ����ʵ��
 */
class PreviewReportDAO : public BaseDAO
{
public:
	// ͨ������id��ѯ����
	list<PreviewReportDO> selectByName(const string& name);
};
#endif // !_PREVIEWREPORT_DAO_