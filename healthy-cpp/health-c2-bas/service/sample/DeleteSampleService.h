#pragma once
#ifndef _DELETE_SAMPLE_SERVICE_
#define _DELETE_SAMPLE_SERVICE_
#include <list>
#include "domain/vo/sample/DeleteSampleVO.h"
//#include "domain/query/sample/DeleteSampleQuery.h"
#include "domain/dto/sample/DeleteSampleDTO.h"

/**
 * ʾ������ʵ�֣���ʾ������ʾ������ʵ��
 */
class DeleteSampleService
{
public:
	// ͨ��IDɾ������
	bool removeData(const string& id);
};

#endif // !_SAMPLE_SERVICE_
