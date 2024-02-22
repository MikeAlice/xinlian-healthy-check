#pragma once
#ifndef _GROUP_PERSON_INFO_DAO_
#define _GROUP_PERSON_INFO_DAO_
#include "BaseDAO.h"
#include "../../domain/do/GroupPersonInfo/GroupPersonInfoDO.h"
#include "../../domain/query/GroupPersonInfo/GroupPersonInfoQuery.h"

class GroupPersonInfoDAO : public BaseDAO
{
public:
	// ��ѯ����
	list<GroupPersonInfoDO> queryInfo(const GroupPersonInfoQuery::Wrapper& query);
};
#endif // !_GROUP_PERSON_INFO_DAO_
