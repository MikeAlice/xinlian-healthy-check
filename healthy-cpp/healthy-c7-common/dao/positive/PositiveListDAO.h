#pragma once
#ifndef _POSITIVE_LIST_DAO_
#define _POSITIVE_LIST_DAO_
#include "BaseDAO.h"
#include "../../domain/do/positive/PositiveListDO.h"
#include "../../domain/query/positive/positiveQuery.h"

/**
 * ʾ�������ݿ����ʵ��
 */
class PositiveListDAO : public BaseDAO
{
public:
	// ͳ����������
	uint64_t count(const PositiveQuery::Wrapper& query);
	// ��ҳ��ѯ����
	list<PositiveListDO> selectWithPage(const PositiveQuery::Wrapper& query);
	// ͨ��������ѯ����
	list<PositiveListDO> selectByName(const string& name);
	// ��������
	uint64_t insert(const PositiveListDO& iObj);
	// �޸�����
	int update(const PositiveListDO& uObj);
	// ͨ��IDɾ������
	int deleteById(uint64_t id);
};
#endif // !_POSITIVE_LIST_DAO_
