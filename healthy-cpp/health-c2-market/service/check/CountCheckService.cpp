#include "stdafx.h"
#include "CountCheckService.h"

CountCheckDTO::Wrapper CountCheckService::countAll(const CountCheckQuery::Wrapper& query)
{
	// �������ض���
	auto count_all = CountCheckDTO::createShared();
	// ��ѯ����������
	CountCheckDAO dao;

	uint64_t count = dao.count(query);
    uint64_t count2 = dao.count2(query);

	if (count < 0&& count2 < 0)
	{
		return count_all;
	}

	// ��ҳ��ѯ����
	count_all->already= count;
	count_all->yet= count2;
	return count_all;
}

