#ifndef _GROUP_ORDER_LIST_DAO_
#define _GROUP_ORDER_LIST_DAO_
#include "BaseDAO.h"
#include "domain/do/Exalanding/GroupOrderListDO.h"
#include "domain/query/Exalanding/GroupOrderListQuery.h"
#include"dao/Exalanding/GroupOrderListMapper.h"

/**
 * 团单数据库操作实现
 */
class GroupOrderListDAO : public BaseDAO
{
public:
	// 统计数据条数
	uint64_t count(const GroupOrderListQuery::Wrapper& query);
	// 分页查询数据
	list<GroupOrderListDO> selectWithPage(const GroupOrderListQuery::Wrapper& query);
};
#endif // !_GROUP_ORDER_LIST_DAO_