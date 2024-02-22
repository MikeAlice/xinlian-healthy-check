#pragma once
#ifndef _VIEW_EXCEPTION_DAO_
#define _VIEW_EXCEPTION_DAO_
#include "BaseDAO.h"
#include "../../domain/do/viewexception/ViewExceptionDO.h"
#include "../../domain/query/viewexception/ViewExceptionQuery.h"

/**
 * ʾ�������ݿ����ʵ��
 */
class ViewExceptionDAO : public BaseDAO
{
public:
	// ͳ����������
	uint64_t count(const ViewExceptionQuery::Wrapper& query);
	// ��ѯ����
	list<ViewExceptionDO> selectByID(const ViewExceptionQuery::Wrapper& query);
};
#endif // !_VIEW_EXCEPTION_DAO_
