#pragma once
#ifndef _SAMPLE_SERVICE_
#define _SAMPLE_SERVICE_
#include <list>
#include "../../domain/dto/sample/SampleDTO.h"

/**
 * ʾ������ʵ�֣���ʾ������ʾ������ʵ��
 */
class SampleService
{
public:
	// �޸�����
	bool updateData(const SampleDTO::Wrapper& dto);

};

#endif // !_SAMPLE_SERVICE_

