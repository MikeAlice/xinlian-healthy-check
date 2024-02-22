#pragma once
#ifndef _SAVE_INFO_SERVICE_
#define _SAVE_INFO_SERVICE_
#include <list>
#include "domain/vo/Exalanding/SaveInfoVO.h"
#include "domain/query/Exalanding/SaveInfoQuery.h"
#include "domain/dto/Exalanding/SaveInfoDTO.h"

/**
 * ʾ������ʵ�֣���ʾ������ʾ������ʵ��
 */
class SampleService
{
public:
	// ��������
	uint64_t saveData(const SaveInfoDTO::Wrapper& dto);
	
};

#endif // !_SAVE_INFO_SERVICE_