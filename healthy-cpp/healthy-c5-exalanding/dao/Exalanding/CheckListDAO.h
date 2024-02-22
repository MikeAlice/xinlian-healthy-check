#ifndef _CHECKLIST_DAO_
#define _CHECKLIST_DAO_
#include "BaseDAO.h"
#include "../../domain/do/Exalanding/CheckListDO.h"
#include "../../domain/query/Exalanding/CheckListQuery.h"

/**
 * 示例表数据库操作实现
 */
class CheckListDAO : public BaseDAO
{
public:
	// 统计数据条数
	uint64_t count(const CheckListQuery::Wrapper& query);
	// 分页查询数据
	list<CheckListDO> selectWithPage(const CheckListQuery::Wrapper& query);
	// 通过姓名查询数据
	list<CheckListDO> selectByName(const string& name);
	// 插入数据
	uint64_t insert(const CheckListDO& iObj);
	// 修改数据
	int update(const CheckListDO& uObj);
	// 通过ID删除数据
	int deleteById(uint64_t id);
};
#endif // !_PEOPLELIST_DAO_