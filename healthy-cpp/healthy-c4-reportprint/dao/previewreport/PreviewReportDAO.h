#pragma once
#ifndef _PREVIEWREPORT_DAO_
#define _PREVIEWREPORT_DAO_
#include "BaseDAO.h"
#include "../../domain/do/previewreport/PreviewReportDO.h"
#include "../../domain/query/PreviewReportQuery.h"

/**
 * ����Ԥ�����ݿ����ʵ��
 * �����ˣ�С��
 */
class PreviewReportDAO : public BaseDAO
{
public:
	// ͨ��������ѯ����
	list<PreviewReportDO> selectByName(const string& nameID);
};
#endif // !_PREVIEWREPORT_DAO_
