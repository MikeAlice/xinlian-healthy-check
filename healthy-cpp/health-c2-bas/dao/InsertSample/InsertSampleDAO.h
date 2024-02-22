
#pragma once
#ifndef _INSERTSAMPLE_DAO_
#define _INSERTSAMPLE_DAO_
#include "BaseDAO.h"
#include "../../domain/do/sample/InsertSampleDO.h"
#include "../../domain/query/sample/InsertSampleQuery.h"

 //数据库操作实现

class InsertSampleDAO : public BaseDAO
{
public:
	// 统计数据条数
	uint64_t count(const InsertSampleQuery::Wrapper& query);
	// 分页查询数据
	list<InsertSampleDO> selectWithPage(const InsertSampleQuery::Wrapper& query);
	// 通过姓名查询数据
	list<InsertSampleDO> selectByName(const string& name);
	// 插入数据
	uint64_t insert(const InsertSampleDO& iObj);
	// 修改数据
	int update(const InsertSampleDO& uObj);
	// 通过ID删除数据
	int deleteById(uint64_t id);
};
#endif // !_INSERTSAMPLE_DAO_

