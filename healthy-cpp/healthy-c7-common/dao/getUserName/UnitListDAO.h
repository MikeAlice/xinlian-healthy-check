#pragma once
#pragma once
#ifndef _UnitList_DAO_
#define _UnitList_DAO_
#include "BaseDAO.h"
#include "../../domain/do/getUserName/UnitListDO.h"
#include "../../domain/query/getUserName/UnitQuery.h"

/**
 * ʾ�������ݿ����ʵ��
 */
class UnitListDAO : public BaseDAO
{
public:
	// ͳ����������
	uint64_t count(const UnitQuery::Wrapper& query);
	// ��ҳ��ѯ����
	list<UnitListDO> selectWithPage(const UnitQuery::Wrapper& query);
	// ͨ��������ѯ����
	list<UnitListDO> selectByName(const string& name);
	// ��������
	//uint64_t insert(const UnitListDO& iObj);
	// �޸�����
	//int update(const UnitListDO& uObj);
	// ͨ��IDɾ������
	//int deleteById(uint64_t id);
};
#endif // !_SAMPLE_DAO_
