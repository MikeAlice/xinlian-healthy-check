#pragma once
#ifndef _NAMELIST_SERVICE_
#define _NAMELIST_SERVICE_
#include <list>
#include "domain/vo/contract/NameListVO.h"
#include "domain/query/contract/NameListQuery.h"
#include "domain/dto/contract/NameListDTO.h"

/**
 * ʾ������ʵ�֣���ʾ������ʾ������ʵ��
 */
class NameListService
{
public:
	// ��ҳ��ѯ��������
	NameListPageDTO::Wrapper listAll(const NameListQuery::Wrapper& query);
	// ��������
	uint64_t saveData(const NameListDTO::Wrapper& dto);

};

#endif // !_SAMPLE_SERVICE_
