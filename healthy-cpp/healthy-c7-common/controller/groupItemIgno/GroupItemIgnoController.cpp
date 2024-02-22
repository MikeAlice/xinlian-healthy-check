 
#include "stdafx.h"
#include "GroupItemIgnoController.h"
#include "../../service/groupItemIgno/GroupItemIgnoService.h"
#include "../ApiDeclarativeServicesHelper.h"
 
// StringJsonVO
StringJsonVO::Wrapper GroupItemIgnoController::execUpdateDepartItemResult(const GroupItemIgnoDTO::Wrapper& dto)
{
	//// 定义返回数据对象
	auto jvo = StringJsonVO::createShared();
	if (dto->personId == "0000")
		jvo->fail("personId 0000 is failtest");
	else
		jvo->success(dto->orderGroupItemProjectId);
	// 响应结果
	return jvo;
}
  
 