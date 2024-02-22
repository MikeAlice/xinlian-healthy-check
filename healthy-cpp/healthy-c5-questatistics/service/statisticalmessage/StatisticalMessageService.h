#pragma once

#ifndef _STATISTICALMESSAGE_SERVICE_
#define _STATISTICALMESSAGE_SERVICE_
#include <list>
#include "domain/vo/statisticalmessage/StatisticalMessageVO.h"
#include "domain/query/statisticalmessage/StatisticalMessageQuery.h"
#include "domain/dto/statisticalmessage/StatisticalMessageDTO.h"

/**
 * ʾ������ʵ�֣���ʾ������ʾ������ʵ��
 */
class StatisticalMessageService
{
public:
	// ��ҳ��ѯ��������
	StatisticalMessagePageDTO::Wrapper listAll(const StatisticalMessageQuery::Wrapper& query);
	// ��������
	//uint64_t saveData(const JoinPersonListDTO::Wrapper& dto);
	// �޸�����
	//bool updateData(const JoinPersonListDTO::Wrapper& dto);
	// ͨ��IDɾ������
	//bool removeData(uint64_t id);
};

#endif // !_SAMPLE_SERVICE_

