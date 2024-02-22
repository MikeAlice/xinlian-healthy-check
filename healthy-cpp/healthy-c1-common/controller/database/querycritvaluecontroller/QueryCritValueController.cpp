#include "QueryCritValueController.h"
#include "../../../domain/vo/database/CritValueVO.h"
#include "../../../domain/query/database/CritValuePageQuery.h"
#include "../../../service/database/querycritvalue/QueryCritValueService.h"


CritValuePageJsonVO::Wrapper QueryCritValueController::execQueryCritValue(const CritValuePageQuery::Wrapper& query)
{
	// ����һ��Service
	QueryCritValueService service;
	// ��ѯ����
	auto result = service.listAll(query);
	// ��Ӧ���
	auto jvo = CritValuePageJsonVO::createShared();
	jvo->success(result);
	return jvo;
	return {};
}
