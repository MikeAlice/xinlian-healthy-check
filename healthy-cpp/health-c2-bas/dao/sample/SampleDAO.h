#pragma once
#ifndef _SAMPLE_DAO_
#define _SAMPLE_DAO_
#include "BaseDAO.h"
#include "../../domain/do/sample/SampleDO.h"

/**
 * 示例表数据库操作实现
 */
class SampleDAO : public BaseDAO
{
public:
	// 修改数据
	int update(const SampleDO& uObj);
};
#endif // !_SAMPLE_DAO_
