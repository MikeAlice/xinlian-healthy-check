#pragma once
#ifndef _DEPART_LIST_DAO_
#define _DEPART_LIST_DAO_
#include "BaseDAO.h"
#include "../../domain/do/Dangerous/DepartListDO.h"
#include "../../domain/query/Dangerous/DepartQuery.h"

/**
 * ʾ�������ݿ����ʵ��
 */
class DepartListDAO : public BaseDAO
{
public:
	// ͳ����������
	uint64_t count(const DepartQuery::Wrapper& query);
	// ��ҳ��ѯ����
	list<DepartListDO> selectWithPage(const DepartQuery::Wrapper& query);
	// ͨ���˵�id��ѯ����
	list<DepartListDO> selectByPersonId(const string& personId);
	// ��������
	//uint64_t insert(const UnitListDO& iObj);
	// �޸�����
	//int update(const UnitListDO& uObj);
	// ͨ��IDɾ������
	//int deleteById(uint64_t id);
};
#endif // !_SAMPLE_DAO_