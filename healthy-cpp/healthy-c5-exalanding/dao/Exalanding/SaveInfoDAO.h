#pragma once
#ifndef _SAVE_INFO_DAO_
#define _SAVE_INFO_DAO_
#include "BaseDAO.h"
#include "../../domain/do/Exalanding/SaveInfoDO.h"
#include "../../domain/query/Exalanding/SaveInfoQuery.h"

/**
 * 示例表数据库操作实现
 */
class SaveInfoDAO : public BaseDAO
{
public:
	// 插入数据
	uint64_t insert(const SaveInfoDO& iObj);
	
};
#endif // !_SAVE_INFO_DAO_