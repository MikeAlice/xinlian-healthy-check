#pragma once
#ifndef _REVIEW_DAO_
#define _REVIEW_DAO_
#include "BaseDAO.h"
#include "../../domain/do/review/ReviewDO.h"
#include "../../domain/query/review/ReviewQuery.h"

/**
 * 复查记录表数据库操作实现
 */
class ReviewDAO : public BaseDAO
{
public:
	// 统计数据条数
	uint64_t count(const ReviewQuery::Wrapper& query);
	// 分页查询数据
	list<ReviewDO> selectWithPage(const ReviewQuery::Wrapper& query);
	// pdf使用 通过姓名查询数据
	list<ReviewDO> selectByName(const string& name);
	// 修改数据
	int update(const ReviewDO& uObj);
	// 通过ID删除数据
	int deleteById(string id);
};
#endif // !_REVIEW_DAO_