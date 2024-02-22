#pragma once
#ifndef _ADDNEWITEMS_DAO_
#define _ADDNEWITEMS_DAO_
#include "BaseDAO.h"
#include "../../domain/do/addNewItems/AddNewItemsDO.h"
#include "../../domain/query/addNewItems/AddNewItemsQuery.h"

/**
 * 新增复查记录表数据库操作实现
 */
class AddNewItemsDAO : public BaseDAO
{
public:
	// 插入数据
	uint64_t insert(const AddNewItemsDO& iObj);
};
#endif // !_ADDNEWITEMS_DAO_