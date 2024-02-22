#pragma once
#ifndef _OBTAINSAMPLELIST_SERVICE_
#define _OBTAINSAMPLELIST_SERVICE_
#include <list>
#include "domain/vo/sample/ObtainSampleListVO.h"
#include "domain/query/sample/ObtainSampleListQuery.h"
#include "domain/dto/sample/ObtainSampleListDTO.h"
//ObtainSampleListService
/**
 * 服务实现，基础的服务实现
 */
class ObtainSampleListService
{
public:
	// 分页查询所有数据
	ObtainSampleListPageDTO::Wrapper listAll(const ObtainSampleListQuery::Wrapper& query);
	// 保存数据
	uint64_t saveData(const ObtainSampleListDTO::Wrapper& dto);
	// 修改数据
	bool updateData(const ObtainSampleListDTO::Wrapper& dto);
	// 通过ID删除数据
	bool removeData(uint64_t id);
};

#endif // !_OBTAINSAMPLELIST_SERVICE_

