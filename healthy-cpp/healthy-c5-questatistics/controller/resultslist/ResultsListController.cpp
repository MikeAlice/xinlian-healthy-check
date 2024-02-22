
#include "stdafx.h"
#include "ResultsListController.h"
#include "../../service/resultslist/ResultsListService.h"
#include "../ApiDeclarativeServicesHelper.h"

ResultsListPageJsonVO::Wrapper ResultsListController::execQueryResultsList(const ResultsListQuery::Wrapper& query, const PayloadDTO& payload)
{
	// ����һ��Service
	ResultsListService service;
	// ��ѯ����
	auto result = service.listAll(query);
	// ��Ӧ���
	auto jvo = ResultsListPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
	//return ResultsListPageJsonVO::Wrapper();
}
