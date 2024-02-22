#pragma once
#ifndef _GETPD_DAO_
#define _GETPD_DAO_
#include "BaseDAO.h"
#include "../../domain/do/GetPD/GetPDDO.h"
#include "../../domain/query/GetPD/GetPDQuery.h"

/**
 * ʾ�������ݿ����ʵ��
 */
class GetPDDAO : public BaseDAO
{
public:
	// ͳ����������
	uint64_t count(const GetPDQuery::Wrapper& query);
	// ��ҳ��ѯ����
	list<GetPDDO> selectWithPage(const GetPDQuery::Wrapper& query);
};
#endif // !_GETPD_DAO_