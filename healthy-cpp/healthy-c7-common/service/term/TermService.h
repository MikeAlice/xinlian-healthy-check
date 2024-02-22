#pragma once
#ifndef _TERM_SERVICE_
#define _TERM_SERVICE_
#include <list>
#include "domain/vo/term/TermVO.h"
#include "domain/query/term/TermQuery.h"
#include "domain/dto/term/TermListDTO.h"

/**
 * 示例服务实现，演示基础的示例服务实现
 */
class TermService
{
public:
	// 分页查询所有数据
	TermListPageDTO::Wrapper listAll(const TermQuery::Wrapper& query);
	// 保存数据
	uint64_t saveData(const TermListDTO::Wrapper& dto);
	// 修改数据
	bool updateData(const TermListDTO::Wrapper& dto);
	// 通过ID删除数据
	bool removeData(uint64_t id);
};

#endif // !_TERM_SERVICE_