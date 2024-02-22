#pragma once
#ifndef _NAMELIST_DAO_
#define _NAMELIST_DAO_
#include "BaseDAO.h"
#include "../../domain/do/contract/NameListDO.h"
#include "../../domain/query/contract/NameListQuery.h"

/**
 * ʾ�������ݿ����ʵ��
 */
class NameListDAO : public BaseDAO
{
public:
	// ͳ����������
	uint64_t count(const NameListQuery::Wrapper& query);
	// ��ҳ��ѯ����
	list<NameListDO> selectWithPage(const NameListQuery::Wrapper& query);

};
#endif // !_SAMPLE_DAO_