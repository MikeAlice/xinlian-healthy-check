#ifndef _GROUP_ORDER_LIST_SERVICE_
#define _GROUP_ORDER_LIST_SERVICE_
#include <list>
#include"domain/vo/Exalanding/GroupOrderVO.h"
#include"domain/query/Exalanding/GroupOrderListQuery.h"
#include"domain/dto/Exalanding/GroupOrderListDTO.h"
/**
 * �ŵ�����ʵ��
 */
class GroupOrderListService
{
public:
	// ��ҳ��ѯ��������
	GroupOrderListPageDTO::Wrapper listAll(const GroupOrderListQuery::Wrapper& query);
};

#endif // !_GROUP_ORDER_LIST_SERVICE_

