#pragma once
#ifndef _CHECKREPORTLIST_SERVICE_
#define _CHECKREPORTLIST_SERVICE_
#include <list>
#include "domain/vo/checks/CheckReportVO.h"
#include "domain/query/checks/CheckReportQuery.h"
#include "domain/dto/checks/CheckReportListDTO.h"

/**
 * ��ȡ��λ�б����ʵ��
 */
class CheckReportListService
{
public:
	// ��ҳ��ѯ��������
	CheckReportListPageDTO::Wrapper listAll(const CheckReportQuery::Wrapper& query);
};

#endif // !_CHECKREPORTLIST_SERVICE_