#pragma once
#ifndef _BASICINFORMATIONCONTROLLER_DAO_
#define _BASICINFORMATIONCONTROLLER_DAO_
#include "BaseDAO.h"
#include "../../domain/do/unknownmodulebasicinformation/BasicInformationDO.h"
#include "../../domain/query/unknownmodulebasicinformation/BasicInformationQuery.h"

class BasicInformationDAO : public BaseDAO
{
public:
	// ͳ����������
	uint64_t count(const BasicInformationQuery::Wrapper& query);
	// ��ҳ��ѯ����
	list<BasicInformationDO> selectWithPage(const BasicInformationQuery::Wrapper& query);
};
#endif // !_GROUP_PERSON_DAO_
