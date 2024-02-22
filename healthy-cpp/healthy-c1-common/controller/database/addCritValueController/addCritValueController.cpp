
#include "addCritValueController.h"
#include "../../../domain/dto/database/CritValueDTO.h"
#include "../../../service/database/addcritvalue/AddCritValueService.h"




Uint64JsonVO::Wrapper AddCritValueController::execCriticalValue(const CritValueDTO::Wrapper & dto)
{
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	// 参数校验
	// 非空校验
	if (!dto->level || !dto->type || !dto->intervalValue)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// 有效值校验
	/*if (dto->age < 0 || dto->name->empty() || dto->sex->empty())
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}*/

	// 定义一个Service
	AddCritValueService service;
	// 执行数据新增
	uint64_t id = service.saveData(dto);
	if (id) {
		jvo->success(UInt64(id));
	}
	else
	{
		jvo->fail(UInt64(id));
	}
	//响应结果
	return jvo;
}
