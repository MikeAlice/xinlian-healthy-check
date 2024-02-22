#include "stdafx.h"
#include "TermController.h"
#include "../../service/term/TermService.h"
#include "../ApiDeclarativeServicesHelper.h"




TermListPageJsonVO::Wrapper TermController::execQueryTerm(const TermQuery::Wrapper& query)
{
	// ����һ��Service
	TermService service;
	// ��ѯ����
	auto result = service.listAll(query);
	// ��Ӧ���
	auto jvo = TermListPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}
