#pragma once
#ifndef _VIEW_EXCEPTION_SERVICE_
#define _VIEW_EXCEPTION_SERVICE_
#include <list>
#include "domain/vo/viewexception/ViewExceptionVO.h"
#include "domain/query/viewexception/ViewExceptionQuery.h"
#include "domain/dto/viewexception/ViewExceptionDTO.h"

/**
 * 示例服务实现，演示基础的示例服务实现
 */
class ViewExceptionService
{
public:
	// 查询数据
	ViewExceptionDTO::Wrapper getData(const ViewExceptionQuery::Wrapper& query);
};

#endif // !_VIEW_EXCEPTION_SERVICE_

