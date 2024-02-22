#pragma once
#ifndef _UNIT_PEOPLE_SERVICE_
#define _UNIT_PEOPLE_SERVICE_
#include <list>
#include "domain/vo/unitpeople/UnitpeopleVO.h"
#include "domain/query/unitpeople/UnitPeopleQuery.h"
#include "domain/dto/unitpeople/UnitPeopleDTO.h"

/**
 * ʾ������ʵ�֣���ʾ������ʾ������ʵ��
 */
class UnitPeopleService
{
public:
	// ��ҳ��ѯ��������
	UnitPeoplePageDTO::Wrapper listAll(const UnitPeopleQuery::Wrapper& query);
	// ��������
	uint64_t saveData(const UnitPeopleDTO::Wrapper& dto);
	// �޸�����
	bool updateData(const UnitPeopleDTO::Wrapper& dto);
	// ͨ��IDɾ������
	bool removeData(uint64_t id);
};

#endif // !_UNIT_PEOPLE_SERVICE_