#include "stdafx.h"
#include "GroupPersonController.h"
#include "../ApiDeclarativeServicesHelper.h"
#include "../../service/Exalanding/GroupPersonService.h"

Uint64JsonVO::Wrapper GroupPersonController::execAddGroupPerson(const GroupPersonDTO::Wrapper& dto) {
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	// 参数校验
	// 非空校验
	if (!dto->testNum || !dto->personName)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// 有效值校验
	if (dto->age < 0 || dto->personName->empty() || dto->sex->empty())
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}

	// 定义一个Service
	GroupPersonService service;
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