#include "stdafx.h"
#include "AddController.h"
#include "../../service/add/addService.h"

AddPageJsonVO::Wrapper AddController::execQueryAdd(const AddUnit::Wrapper& query)
{
	return {};
}

Uint64JsonVO::Wrapper AddController::execAddUnit(const AddUnitDTO::Wrapper& dto)
{
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	// 参数校验
	// 非空校验

	// 定义一个Service
	addService service;
	// 执行数据新增
	uint64_t id = service.saveData(dto);

		jvo->success(UInt64(id));
	
	//响应结果
	return jvo;
}
