#pragma once


#ifndef _REFERENCEDELSERVICE_H_
#define _REFERENCEDELSERVICE_H_
#include <list>
#include "domain/vo/base/ReferenceDelVO.h"
//#include "domain/query/sample/SampleQuery.h"
#include "domain/dto/base/ReferenceDelDTO.h"
#include "../../domain/dto/base/ReferenceModDTO.h"

/**
 * 删除服务实现
 */
class ReferenceDelService
{
public:
	
	// 保存数据
	//uint64_t saveData(const ReferenceDelDTO::Wrapper& dto);
	
	// 通过ID删除数据
	bool removeData(const ReferenceDelDTO::Wrapper& dto);
};

#endif // !_REFERENCEDELSERVICE_H_