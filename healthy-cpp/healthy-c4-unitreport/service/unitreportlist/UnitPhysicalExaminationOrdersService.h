#pragma once
#ifndef _UNITPHYSICALEXAMINATIONORDERS_SERVICE_
#define _UNITPHYSICALEXAMINATIONORDERS_SERVICE_
#include <list>
#include "domain/vo/unitreportlist/UnitListVO.h"
#include "domain/query/unitreportlist/UnitPhysicalExaminationOrdersQuery.h"
#include "domain/dto/unitreportlist/UnitListDTO.h"

/**
 * ʾ������ʵ�֣���ʾ������ʾ������ʵ��
 */
class UnitPhysicalExaminationOrdersService
{
public:
	// ��ҳ��ѯ��������
	UnitListPageDTO::Wrapper listAll(const UnitPhysicalExaminationOrdersQuery::Wrapper& query);
};

#endif // !_SAMPLE_SERVICE_