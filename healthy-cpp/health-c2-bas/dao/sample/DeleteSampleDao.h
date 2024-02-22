#pragma once
#ifndef _DELETE_SAMPLE_DAO_
#define _DELETE_SAMPLE_DAO_
#include "BaseDAO.h"
#include "../../domain/do/sample/DeleteSampleDO.h"
//#include "../../domain/query/sample/DeleteSampleQuery.h"

/**
 * 示例表数据库操作实现
 */
class DeleteSampleDAO : public BaseDAO
{
public:
	
	// 通过ID删除数据
	int deleteById(const string& id);
};
#endif // !_DELETESAMPLE_DAO_
