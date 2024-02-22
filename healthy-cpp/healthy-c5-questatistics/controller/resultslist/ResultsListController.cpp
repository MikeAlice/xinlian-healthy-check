
#include "stdafx.h"
#include "ResultsListController.h"
#include "../../service/resultslist/ResultsListService.h"
#include "../ApiDeclarativeServicesHelper.h"

ResultsListPageJsonVO::Wrapper ResultsListController::execQueryResultsList(const ResultsListQuery::Wrapper& query, const PayloadDTO& payload)
{
	// 定义一个Service
	ResultsListService service;
	// 查询数据
	auto result = service.listAll(query);
	// 响应结果
	auto jvo = ResultsListPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
	//return ResultsListPageJsonVO::Wrapper();
}
