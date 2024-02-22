 
#include "stdafx.h"
#include "GroupItemIgnoController.h"
#include "../../service/groupItemIgno/GroupItemIgnoService.h"
#include "../ApiDeclarativeServicesHelper.h"
 
// StringJsonVO
StringJsonVO::Wrapper GroupItemIgnoController::execUpdateDepartItemResult(const GroupItemIgnoDTO::Wrapper& dto)
{
	//// ���巵�����ݶ���
	auto jvo = StringJsonVO::createShared();
	if (dto->personId == "0000")
		jvo->fail("personId 0000 is failtest");
	else
		jvo->success(dto->orderGroupItemProjectId);
	// ��Ӧ���
	return jvo;
}
  
 