#pragma once
#ifndef _DEPART_LIST_SERVICE_
#define _DEPART_LIST_SERVICE_
#include <list>
#include "domain/vo/Dangerous/DepartVO.h"
#include "domain/query/Dangerous/DepartQuery.h"
#include "domain/dto/Dangerous/DepartListDTO.h"

/**
 * ʾ������ʵ�֣���ʾ������ʾ������ʵ��
 */
class DepartListService
{
public:
	// ��ҳ��ѯ��������
	DepartListPageDTO::Wrapper listAll(const DepartQuery::Wrapper& query);
};

#endif // !_SAMPLE_SERVICE_