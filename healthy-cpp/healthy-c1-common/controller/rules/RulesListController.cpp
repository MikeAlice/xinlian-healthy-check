#include "stdafx.h"
#include "RulesListController.h"
#include "oatpp/core/utils/ConversionUtils.hpp"
#include <iostream>
#include <sstream>
#include "service/rules/RulesListService.h"

/**
 * 注意：这里的部分代码本应该放到service层中，为了方便演示就写在一起了
 */

RulesListPageJsonVO::Wrapper RulesListController::executeQueryAll(const RulesListQuery::Wrapper& query)
{
	// 定义一个Service
	RulesListService service;
	// 查询数据
	auto result = service.listAll(query);
	// 响应结果
	auto jvo = RulesListPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

Uint64JsonVO::Wrapper RulesListController::executeModifyRules(const RulesListDTO::Wrapper& dto)
{
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	// 参数校验

	// 定义一个Service
	RulesListService service;
	// 执行数据修改
	// 执行数据新增
	bool id = service.updateData(dto);
	if (id) {
		jvo->success(UInt64(id));
	}
	else
	{
		jvo->fail(UInt64(id));
	}
	// 响应结果
	return jvo;
}
