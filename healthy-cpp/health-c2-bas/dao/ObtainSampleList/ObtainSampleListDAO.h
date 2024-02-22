#pragma once
#ifndef _OBTAINSAMPLELIST_DAO_
#define _OBTAINSAMPLELIST_DAO_
#include "BaseDAO.h"
#include "../../domain/do/sample/ObtainSampleListDO.h"
#include "../../domain/query/sample/ObtainSampleListQuery.h"
//ObtainSampleList
/**
 * 数据库操作实现
 */
class ObtainSampleListDAO : public BaseDAO
{
public:
	// 统计数据条数
	uint64_t count(const ObtainSampleListQuery::Wrapper& query);
	// 分页查询数据
	list<ObtainSampleListDO> selectWithPage(const ObtainSampleListQuery::Wrapper& query);
	// 通过姓名查询数据
	list<ObtainSampleListDO> selectByName(const string& name);
	// 插入数据
	uint64_t insert(const ObtainSampleListDO& iObj);
	// 修改数据
	int update(const ObtainSampleListDO& uObj);
	// 通过ID删除数据
	int deleteById(uint64_t id);
};
#endif // !_OBTAINSAMPLELIST_DAO_
