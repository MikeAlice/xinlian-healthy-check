#pragma once

#ifndef _CRITICAL_LIST_SERVICE_
#define _CRITICAL_LIST_SERVICE_
#include <list>
#include "domain/vo/critical/CriticalModifyVO.h"
#include "domain/vo/critical/CriticalDeleteVO.h"
#include "domain/query/critical/CriticalQuery.h"
#include "domain/dto/critical/CriticalDeleteDTO.h"
#include "domain/dto/critical/CriticalModifyDTO.h"

/**
 * 示例服务实现，演示基础的示例服务实现
 */
class CriticalListService
{
public:
	// 修改数据
	bool updateData(const CriticalListDTO::Wrapper& dto);
	// 通过ID删除数据
	bool removeData(const CriticalDeleteListDTO::Wrapper& dto);
};

#endif 