
#pragma once
#ifndef _CHECKLIST_SERVICE_
#define _CHECKLIST_SERVICE_
#include <list>
#include "domain/vo/Exalanding/CheckListVO.h"
#include "domain/query/Exalanding/CheckListQuery.h"
#include "domain/dto/Exalanding/CheckListDTO.h"

/**
 * 示例服务实现，演示基础的示例服务实现
 */
class CheckListService
{
public:
	// 分页查询所有数据
	CheckListPageDTO::Wrapper listAll(const CheckListQuery::Wrapper& query);
	// 保存数据
	uint64_t saveData(const CheckListDTO::Wrapper& dto);
	// 修改数据
	bool updateData(const CheckListDTO::Wrapper& dto);
	// 通过ID删除数据
	bool removeData(uint64_t id);
};

#endif // !_CHECKLIST_SERVICE_


