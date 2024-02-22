#pragma once
#ifndef _DELETE_SAMPLE_SERVICE_
#define _DELETE_SAMPLE_SERVICE_
#include <list>
#include "domain/vo/sample/DeleteSampleVO.h"
//#include "domain/query/sample/DeleteSampleQuery.h"
#include "domain/dto/sample/DeleteSampleDTO.h"

/**
 * 示例服务实现，演示基础的示例服务实现
 */
class DeleteSampleService
{
public:
	// 通过ID删除数据
	bool removeData(const string& id);
};

#endif // !_SAMPLE_SERVICE_
