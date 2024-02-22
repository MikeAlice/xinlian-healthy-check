#include "stdafx.h"
#include "TermController.h"
#include "../../service/term/TermService.h"
#include "../ApiDeclarativeServicesHelper.h"




TermListPageJsonVO::Wrapper TermController::execQueryTerm(const TermQuery::Wrapper& query)
{
	// 定义一个Service
	TermService service;
	// 查询数据
	auto result = service.listAll(query);
	// 响应结果
	auto jvo = TermListPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}
