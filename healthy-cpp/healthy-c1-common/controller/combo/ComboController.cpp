#include "stdafx.h"
#include "ComboController.h"
#include "../ApiDeclarativeServicesHelper.h"

Uint64JsonVO::Wrapper ComboController::execAddPack(const AddPackDTO::Wrapper& dto)
{
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	// 参数校验
	// 非空校验

	// 定义一个Service
	AddPackService service;
	// 执行数据新增
	uint64_t id = service.saveData(dto);
	if (id > 0) {
		jvo->success(UInt64(id));
	}
	else
	{
		jvo->fail(UInt64(id));
	}
	//响应结果
	return jvo;
}

Uint64JsonVO::Wrapper ComboController::execDelPack(const DelPackDTO::Wrapper& dto)
{
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	// 参数校验
	// 非空校验

	// 定义一个Service
	DelPackService service;

	// 执行数据新增
	uint64_t id = service.removeData(dto);
	if (id > 0) {
		jvo->success(UInt64(id));
	}
	else
	{
		jvo->fail(UInt64(id));
	}

	//响应结果
	return jvo;
}

Uint64JsonVO::Wrapper ComboController::execUpdatePack(const UpdatePackDTO::Wrapper& dto)
{
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	// 参数校验
	// 非空校验

	// 定义一个Service
	UpdatePackService service;

	// 执行数据新增
	uint64_t id = service.modifyData(dto);
	if (id > 0) {
		jvo->success(UInt64(id));
	}
	else
	{
		jvo->fail(UInt64(id));
	}

	//响应结果
	return jvo;
}
