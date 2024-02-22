#pragma once
#ifndef _UNITPHYSICALEXAMINATIONORDERS_SERVICE_
#define _UNITPHYSICALEXAMINATIONORDERS_SERVICE_
#include <list>
#include "domain/vo/unitreportlist/UnitListVO.h"
#include "domain/query/unitreportlist/UnitPhysicalExaminationOrdersQuery.h"
#include "domain/dto/unitreportlist/UnitListDTO.h"

/**
 * 示例服务实现，演示基础的示例服务实现
 */
class UnitPhysicalExaminationOrdersService
{
public:
	// 分页查询所有数据
	UnitListPageDTO::Wrapper listAll(const UnitPhysicalExaminationOrdersQuery::Wrapper& query);
};

#endif // !_SAMPLE_SERVICE_