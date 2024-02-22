#pragma once
#ifndef _UNITPHYSICALEXAMINATIONORDERS_DAO_
#define _UNITPHYSICALEXAMINATIONORDERS_DAO_
#include "BaseDAO.h"
#include "../../domain/do/unitreportlist/UnitPhysicalExaminationOrdersDO.h"
#include "../../domain/query/unitreportlist/UnitPhysicalExaminationOrdersQuery.h"

/**
 * 示例表数据库操作实现
 */
class UnitPhysicalExaminationOrdersDAO : public BaseDAO
{
public:
	// 统计数据条数
	uint64_t count(const UnitPhysicalExaminationOrdersQuery::Wrapper& query);
	// 分页查询数据
	list<UnitPhysicalExaminationOrdersDO> selectWithPage(const UnitPhysicalExaminationOrdersQuery::Wrapper& query);
};
#endif // !_SAMPLE_DAO_