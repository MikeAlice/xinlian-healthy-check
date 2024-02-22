#pragma once
#ifndef _UnitList_SERVICE_
#define _UnitList_SERVICE_
#include <list>
#include "domain/vo/getUserName/UnitVO.h"
#include "domain/query/getUserName/UnitQuery.h"
#include "domain/dto/getUserName/UnitListDTO.h"

/**
 * ʾ������ʵ�֣���ʾ������ʾ������ʵ��
 */
class UnitListService
{
public:
	// ��ҳ��ѯ��������
	UnitListPageDTO::Wrapper listAll(const UnitQuery::Wrapper& query);
	// ��������
	uint64_t saveData(const UnitListDTO::Wrapper& dto);
	// �޸�����
	bool updateData(const UnitListDTO::Wrapper& dto);
	// ͨ��IDɾ������
	bool removeData(uint64_t id);
};

#endif // !_SAMPLE_SERVICE_

