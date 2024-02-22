#pragma once
#ifndef _BASEINFO_SERVICE_
#define _BASEINFO_SERVICE_
#include <list>
#include "domain/vo/contract/BaseInfoVO.h"
#include "domain/query/contract/BaseInfoQuery.h"
#include "domain/dto/contract/BaseInfoDTO.h"

/**
 * ʾ������ʵ�֣���ʾ������ʾ������ʵ��
 */
class BaseInfoService
{
public:
	// ��ҳ��ѯ��������
	BaseInfoPageDTO::Wrapper listAll(const BaseInfoQuery::Wrapper& query);
	// ��������
	uint64_t saveData(const BaseInfoDTO::Wrapper& dto);

};

#endif // !_SAMPLE_SERVICE_
