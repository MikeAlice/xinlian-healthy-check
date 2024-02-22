
#include "stdafx.h"
#include "ReferenceModController.h"
#include "../../service/base/ReferenceModService.h"
#include "../ApiDeclarativeServicesHelper.h"


Uint64JsonVO::Wrapper ReferenceModController::execModifyReference(const ReferenceModDTO::Wrapper& modDto)
{
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	//test
	UInt64 ID = std::atoi(((string)(modDto->id)).c_str());
	
	// 参数校验
	if (!ID || ID <= 0)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	//定义一个Service
	ReferenceModService service;
	// 执行数据修改
	if (service.updateData(modDto)) {
		jvo->success(ID);
	}
	else
	{
		jvo->fail(ID);
	}
	// 响应结果
	return jvo;
}