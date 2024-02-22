#pragma once
#ifndef _REPORTLIST_SERVICE_
#define _REPORTLIST_SERVICE_
#include <list>
#include "domain/vo/reportlist/ReportListVO.h"
#include "domain/query/reportlist/ReportListQuery.h"
#include "domain/dto/reportlist/ReportListDTO.h"

/**
 * ʾ������ʵ�֣���ʾ������ʾ������ʵ��
 */
class ReportListService
{
public:
	// ��ҳ��ѯ��������
	ReportListPageDTO::Wrapper listAll(const ReportListQuery::Wrapper& query);
};

#endif // !_REPORTLIST_SERVICE_

