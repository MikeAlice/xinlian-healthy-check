#include "SampleController.h"
#include "stdafx.h"
#include "../../domain/dto/sample/SampleDTO.h"
#include "../../service/sample/SampleService.h"

StringJsonVO::Wrapper SampleController::execModifySample(const SampleDTO::Wrapper& dto)
{
	// 定义返回数据对象
	auto jvo = StringJsonVO::createShared();
	// 参数校验
	if (dto->id == "")
	{
		jvo->init(String(""), RS_PARAMS_INVALID);
		return jvo;
	}
	// 定义一个Service
	SampleService service;
	// 执行数据修改
	if (service.updateData(dto)) {
		jvo->success(dto->id);
	}
	else
	{
		jvo->fail(dto->id);
	}
	// 响应结果
	return jvo;
}