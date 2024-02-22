#pragma once
#ifndef _COUNTCHECK_SERVICE_
#define _COUNTCHECK_SERVICE_
#include "../../domain/query/check/CountCheckQuery.h"
#include "../../domain/dto/check/CountCheckDTO.h"
#include "../../dao/check/CountCheckDAO.h"


/**
 * 示例服务实现，演示基础的示例服务实现
 */
class CountCheckService
{
public:
	// 统计审核完成和未审批完成的合同数量
	CountCheckDTO::Wrapper countAll(const CountCheckQuery::Wrapper& query);

};

#endif // !_SAMPLE_SERVICE_