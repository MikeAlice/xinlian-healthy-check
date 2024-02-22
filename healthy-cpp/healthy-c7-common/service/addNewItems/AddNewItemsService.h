#pragma once
#ifndef _ADDNEWITEMS_SERVICE_
#define _ADDNEWITEMS_SERVICE_
#include <list>
#include "domain/vo/addNewItems/AddNewItemsVO.h"
#include "domain/query/addNewItems/AddNewItemsQuery.h"
#include "domain/dto/addNewItems/AddNewItemsDTO.h"

/**
 * 基础的新增复查记录服务实现
 */
class AddNewItemsService
{
public:
	// 保存数据  增加
	uint64_t saveData(const AddNewItemsDTO::Wrapper& dto);
};

#endif // !_ADDNEWITEMS_SERVICE_