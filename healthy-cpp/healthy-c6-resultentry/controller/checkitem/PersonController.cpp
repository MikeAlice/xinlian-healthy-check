#include "stdafx.h"
#include "PersonController.h"
#include "../../service/checkitem/PersonService.h"
#include "../ApiDeclarativeServicesHelper.h"


PersonPageJsonVO::Wrapper PersonController::execQueryPerson(const PersonQuery::Wrapper& query)
{
	PersonService service;
	auto result = service.listAll(query);
	auto jvo = PersonPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}
