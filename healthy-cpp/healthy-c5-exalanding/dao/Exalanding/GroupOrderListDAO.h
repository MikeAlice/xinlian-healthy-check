#ifndef _GROUP_ORDER_LIST_DAO_
#define _GROUP_ORDER_LIST_DAO_
#include "BaseDAO.h"
#include "domain/do/Exalanding/GroupOrderListDO.h"
#include "domain/query/Exalanding/GroupOrderListQuery.h"
#include"dao/Exalanding/GroupOrderListMapper.h"

/**
 * �ŵ����ݿ����ʵ��
 */
class GroupOrderListDAO : public BaseDAO
{
public:
	// ͳ����������
	uint64_t count(const GroupOrderListQuery::Wrapper& query);
	// ��ҳ��ѯ����
	list<GroupOrderListDO> selectWithPage(const GroupOrderListQuery::Wrapper& query);
};
#endif // !_GROUP_ORDER_LIST_DAO_