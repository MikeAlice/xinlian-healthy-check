#pragma once
#ifndef _ADD_DAO_
#define _ADD_DAO_
#include "BaseDAO.h"
#include "../../domain/do/add/addDO.h"
#include "../../domain/query/add/AddUnit.h"

/**
 * 示例表数据库操作实现
 */
class addDAO : public BaseDAO
{
public:
	// 插入数据
	uint64_t insert(const addDO& iObj);

};
#endif // !_SAMPLE_DAO_