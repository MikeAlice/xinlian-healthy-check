#include "stdafx.h"
#include "BaseProjectController.h"
#include "../../service/checkitem/BaseProejctService.h"
#include "../ApiDeclarativeServicesHelper.h"

BaseProjectPageJsonVO::Wrapper BaseProjectController::execQueryBaseProject(const BaseProjectQuery::Wrapper& query)
{

	BaseProjectService service;
	auto result = service.listAll(query);
	auto jvo = BaseProjectPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}
