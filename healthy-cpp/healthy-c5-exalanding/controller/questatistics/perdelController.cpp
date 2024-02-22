#include "stdafx.h"
#include "perdelController.h"
#include "../../service/questatistics/perdelService.h"
#include "../ApiDeclarativeServicesHelper.h"
#include "../../dao/questatistics/perdelDAO.h"

Uint64JsonVO::Wrapper perdelController::execRemovePerson(const string& id)
{
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	UInt64 ID = std::stoi(id);
	// 参数校验
	if (ID <= 0)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// 定义一个Service
	perdelService service;
	// 数据删除
	bool result = service.removeData(id);
	if (result)
	{
		jvo->success(UInt64(std::stoi(id)));
	}
	else
	{
		jvo->fail(UInt64(std::stoi(id)));
	}
	return jvo;
}