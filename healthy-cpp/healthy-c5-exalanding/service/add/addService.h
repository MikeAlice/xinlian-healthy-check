#pragma once
#ifndef _SAMPLE_SERVICE_
#define _SAMPLE_SERVICE_
#include <list>
#include "domain/vo/add/AddVo.h"
#include "domain/query/add/AddUnit.h"
#include "domain/dto/add/AddUnitDTO.h"

/**
 * ʾ������ʵ�֣���ʾ������ʾ������ʵ��
 */
class addService
{
public:

	// ��������
	uint64_t saveData(const AddUnitDTO::Wrapper& dto);

};

#endif // !_SAMPLE_SERVICE_