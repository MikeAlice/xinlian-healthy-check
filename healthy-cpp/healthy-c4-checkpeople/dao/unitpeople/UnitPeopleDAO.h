#pragma once
#ifndef _UNIT_PEOPLE_DAO_
#define _UNIT_PEOPLE_DAO_
#include "BaseDAO.h"
#include "../../domain/do/unitpeople/UnitPeopleDO.h"
#include "../../domain/query/unitpeople/UnitPeopleQuery.h"

/**
 * ʾ�������ݿ����ʵ��
 */
class UnitPeopleDAO : public BaseDAO
{
public:
	// ͳ����������
	uint64_t count(const UnitPeopleQuery::Wrapper& query);
	// ��ҳ��ѯ����
	list<UnitPeopleDO> selectWithPage(const UnitPeopleQuery::Wrapper& query);
	// ͨ��֤���Ų�ѯ����
	list<UnitPeopleDO> selectByidCard(const string& id_card);
	// ��������
	uint64_t insert(const UnitPeopleDO& iObj);
	// �޸�����
	int update(const UnitPeopleDO& uObj);
	// ͨ��IDɾ������
	int deleteById(uint64_t id);
};
#endif // !_UNIT_PEOPLE_DAO_
