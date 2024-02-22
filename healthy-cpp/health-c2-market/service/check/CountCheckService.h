#pragma once
#ifndef _COUNTCHECK_SERVICE_
#define _COUNTCHECK_SERVICE_
#include "../../domain/query/check/CountCheckQuery.h"
#include "../../domain/dto/check/CountCheckDTO.h"
#include "../../dao/check/CountCheckDAO.h"


/**
 * ʾ������ʵ�֣���ʾ������ʾ������ʵ��
 */
class CountCheckService
{
public:
	// ͳ�������ɺ�δ������ɵĺ�ͬ����
	CountCheckDTO::Wrapper countAll(const CountCheckQuery::Wrapper& query);

};

#endif // !_SAMPLE_SERVICE_