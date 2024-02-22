#pragma once
#ifndef _COUNTCHECK_DAO_
#define _COUNTCHECK_DAO_
#include "BaseDAO.h"
#include "../../domain/query/check/CountCheckQuery.h"

/**
 * ʾ�������ݿ����ʵ��
 */
class CountCheckDAO : public BaseDAO
{
public:
	//ͳ�������ɵĺ�ͬ
	uint64_t count(const CountCheckQuery::Wrapper& query);

	//ͳ��δ�����ɵĺ�ͬ
	uint64_t count2(const CountCheckQuery::Wrapper& query);

};
#endif // !_COUNTCHECK_DAO_
