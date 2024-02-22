#pragma once
#ifndef _REFERENCEMODSERVICE_H_
#define _REFERENCEMODSERVICE_H_
#include <list>
#include "domain/vo/base/ReferenceModVO.h"
//#include "domain/query/sample/SampleQuery.h"
#include "domain/dto/base/ReferenceModDTO.h"

/**
 * 修改服务实现
 */
class ReferenceModService
{
public:
	
	// 保存数据
	uint64_t saveData(const ReferenceModDTO::Wrapper& dto);
	// 修改数据
	bool updateData(const ReferenceModDTO::Wrapper& dto);
	
};

#endif // !_REFERENCEMODSERVICE_H_