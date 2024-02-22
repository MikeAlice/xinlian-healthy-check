#pragma once

#ifndef _JOINPERSONLIST_SERVICE_
#define _JOINPERSONLIST_SERVICE_
#include <list>
#include "domain/vo/personlist/JoinPersonListVO.h"
#include "domain/query/personlist/JoinPersonListQuery.h"
#include "domain/dto/personlist/JoinPersonListDTO.h"

/**
 * ʾ������ʵ�֣���ʾ������ʾ������ʵ��
 */
class JoinPersonListService
{
public:
	// ��ҳ��ѯ��������
	PersonListPageDTO::Wrapper listAll(const JoinPersonListQuery::Wrapper& query);
	// ��������
	uint64_t saveData(const JoinPersonListDTO::Wrapper& dto);
	// �޸�����
	bool updateData(const JoinPersonListDTO::Wrapper& dto);
	// ͨ��IDɾ������
	bool removeData(uint64_t id);
};

#endif // !_SAMPLE_SERVICE_

