
#include "stdafx.h"
#include "ReferenceDelController.h"
#include "../../service/base/ReferenceDelService.h"
#include "../ApiDeclarativeServicesHelper.h"


Uint64JsonVO::Wrapper ReferenceDelController::execRemoveReference(const ReferenceDelDTO::Wrapper& dto)
{
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();

	//UInt64 ID = std::atoi(((string)(id)).c_str());
	// 参数校验
	if (!dto->id/*!ID || ID <= 0*/)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// 定义一个Service
	ReferenceDelService service;

	int id = service.removeData(dto);
	// 执行数据删除
	if (id>0) {
		jvo->success(id);
	}
	else
	{ 
		jvo->fail(id);
	}
	// 响应结果
	return jvo;
}


//Uint64JsonVO::Wrapper CriticalDeleteController::execDeleteCritical(const CriticalDeleteListDTO::Wrapper& dto)
//{
//	// 定义返回数据对象
//	auto jvo = Uint64JsonVO::createShared();
//	// 参数校验
//	if (!dto->id)
//	{
//		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
//		return jvo;
//	}
//	// 定义一个Service
//	CriticalListService service;
//	// 执行数据删除
//	int id = service.removeData(dto);
//	if (id > 0) {
//		jvo->success(id);
//	}
//	else
//	{
//		jvo->fail(id);
//	}
//	// 响应结果
//	return jvo;
//}