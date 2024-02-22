#pragma once

#ifndef _SELECTBASEPROJECTDAO_H_
#define _SELECTBASEPROJECTDAO_H_
#include "BaseDAO.h"
#include "../../../domain/do/baseproject/SelectBaseProjectDO.h"
#include "../../../domain/query/baseproject/SelectBaseProjectQuery.h"

/**
 * ʾ�������ݿ����ʵ��
 */
class SelectBaseProjectDAO : public BaseDAO
{
public:
	// ͳ����������
	uint64_t count(const SelectBaseProjectQuery::Wrapper& query);

	std::list<SelectBaseProjectDO> selectWithPage(const SelectBaseProjectQuery::Wrapper& query);
	// ͨ��id��ѯ����
	list<SelectBaseProjectDO> selectById(const string& id);
};
#endif // !_SELECTBASEPROJECTDAO_H_
