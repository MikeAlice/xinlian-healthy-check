#include "stdafx.h"
#include "AddRefValueController.h"
#include "service/referencevalue/addrefvalue/AddRefValueService.h"

Uint64JsonVO::Wrapper AddRefValueController::execAddRefValue(const AddRefValueDTO::Wrapper& dto)
{
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	// 参数校验
	// 非空校验
	if (!dto->id || !dto->base_project_id || !dto->department_id)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// 有效值校验
	/*if ()
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}*/

	// 定义一个Service
	AddRefValueService service;
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
