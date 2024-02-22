#pragma once
#ifndef _POSITIVE_LIST_SERVICE_
#define _POSITIVE_LIST_SERVICE_
#include <list>
#include "domain/vo/positive/positiveVO.h"
#include "domain/query/positive/positiveQuery.h"
#include "domain/dto/positive/positiveListDTO.h"

/**
 * ʾ������ʵ�֣���ʾ������ʾ������ʵ��
 */
class PositiveListService
{
public:
	// ��ҳ��ѯ��������
	PositiveListPageDTO::Wrapper listAll(const PositiveQuery::Wrapper& query);
	// ��������
	uint64_t saveData(const PositiveListDTO::Wrapper& dto);
	// �޸�����
	bool updateData(const PositiveListDTO::Wrapper& dto);
	// ͨ��IDɾ������
	bool removeData(uint64_t id);
};

#endif // !_SAMPLE_SERVICE_
