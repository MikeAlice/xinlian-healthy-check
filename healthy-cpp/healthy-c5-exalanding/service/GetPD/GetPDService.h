#pragma once
#pragma once
#ifndef _GETPD_SERVICE_
#define _GETPD_SERVICE_
#include <list>
#include "domain/vo/GetPD/GetPDVO.h"
#include "domain/query/GetPD/GetPDQuery.h"
#include "domain/dto/GetPD/GetPDDTO.h"

/**
 * 示例服务实现，演示基础的示例服务实现
 */
class GetPDService
{
public:
	// 分页查询所有数据
	GetPDPageDTO::Wrapper listAll(const GetPDQuery::Wrapper& query);
};

#endif // !_SAMPLE_SERVICE_