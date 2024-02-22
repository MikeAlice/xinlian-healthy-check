#ifndef _GROUP_ORDER_LIST_MAPPER_
#define _GROUP_ORDER_LIST_MAPPER_

#include "Mapper.h"
#include"domain/do/Exalanding/GroupOrderListDO.h"

/**
 * �ŵ��ֶ�ƥ��ӳ��
 */
class GroupOrderListMapper : public Mapper<GroupOrderListDO>
{
public:
	GroupOrderListDO mapper(ResultSet* resultSet) const override
	{
		GroupOrderListDO data;
		data.setSex(resultSet->getString(1));
		data.setGroupUnitName(resultSet->getString(2));
		data.setGroupName(resultSet->getString(3));
		return data;
	}
};

#endif // !_GROUP_ORDER_LIST_MAPPER_