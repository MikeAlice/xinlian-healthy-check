#pragma once
#ifndef _BASEINFO_DAO_
#define _BASEINFO_DAO_
#include "BaseDAO.h"
#include "../../domain/do/contract/BaseInfoDO.h"
#include "../../domain/query/contract/BaseInfoQuery.h"

/**
 * ʾ�������ݿ����ʵ��
 */
class BaseInfoDAO : public BaseDAO
{
public:
	// ͳ����������
	uint64_t count(const BaseInfoQuery::Wrapper& query);
	// ��ҳ��ѯ����
	list<BaseInfoDO> selectWithPage(const BaseInfoQuery::Wrapper& query);

};
#endif // !_SAMPLE_DAO_