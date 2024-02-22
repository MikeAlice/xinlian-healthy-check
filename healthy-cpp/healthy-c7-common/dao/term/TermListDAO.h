#pragma once
#ifndef _TERM_DAO_
#define _TERM_DAO_
#include "BaseDAO.h"
#include "../../domain/do/term/TermListDO.h"
#include "../../domain/query/term/TermQuery.h"

/**
 * 示例表数据库操作实现
 */
class TermListDAO : public BaseDAO
{
public:
	// 统计数据条数
	uint64_t count(const TermQuery::Wrapper& query);
	// 分页查询数据
	list<TermListDO> selectWithPage(const TermQuery::Wrapper& query);
	// 通过科室ID查询数据
	list<TermListDO> selectByOfficeId(const string& officeId);
	// 插入数据
	uint64_t insert(const TermListDO& iObj);
	// 修改数据
	int update(const TermListDO& uObj);
	// 通过ID删除数据
	int deleteById(uint64_t id);
};
#endif // !_TERM_DAO_