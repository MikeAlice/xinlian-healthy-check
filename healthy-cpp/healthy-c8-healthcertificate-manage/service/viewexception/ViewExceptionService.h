#pragma once
#ifndef _VIEW_EXCEPTION_SERVICE_
#define _VIEW_EXCEPTION_SERVICE_
#include <list>
#include "domain/vo/viewexception/ViewExceptionVO.h"
#include "domain/query/viewexception/ViewExceptionQuery.h"
#include "domain/dto/viewexception/ViewExceptionDTO.h"

/**
 * ʾ������ʵ�֣���ʾ������ʾ������ʵ��
 */
class ViewExceptionService
{
public:
	// ��ѯ����
	ViewExceptionDTO::Wrapper getData(const ViewExceptionQuery::Wrapper& query);
};

#endif // !_VIEW_EXCEPTION_SERVICE_

