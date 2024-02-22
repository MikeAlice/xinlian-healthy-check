#pragma once
#ifndef _PEOPLELIST_SERVICE_
#define _PEOPLELIST_SERVICE_
#include <list>
#include "domain/vo/Exalanding/PeopleListVO.h"
#include "domain/query/Exalanding/PeopleListQuery.h"
#include "domain/dto/Exalanding/PeopleListDTO.h"

/**
 * ʾ������ʵ�֣���ʾ������ʾ������ʵ��
 */
class PeopleListService
{
public:
	// ��ҳ��ѯ��������
	PeopleListPageDTO::Wrapper listAll(const PeopleListQuery::Wrapper& query);
	// ��������
	uint64_t saveData(const PeopleListDTO::Wrapper& dto);
	// �޸�����
	bool updateData(const PeopleListDTO::Wrapper& dto);
	// ͨ��IDɾ������
	bool removeData(uint64_t id);
};

#endif // !_SAMPLE_SERVICE_

