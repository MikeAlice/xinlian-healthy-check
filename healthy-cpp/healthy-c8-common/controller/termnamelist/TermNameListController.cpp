#include "TermNameListController.h"
#include "stdafx.h"
#include "../ApiDeclarativeServicesHelper.h"
TermNameListPageJsonVO::Wrapper TermNameListController::execQueryTermNameList(const TermNameListQuery::Wrapper& query, const PayloadDTO& payload)
{
	// ����ƾ֤
	std::string token = PayloadDTO::getTokenPrefix() + payload.getToken();
	// �����ͻ��˶���
	API_CLIENT_CREATE(ac, om, TermNameListApiClient, "query-termnamelist-api");
	// ���ؽ��
	return ac->queryTermNameList(token, query->pageIndex, query->pageSize, URIUtil::urlEncode(query->type_inspection),
								 URIUtil::urlEncode(query->type_term), URIUtil::urlEncode(query->factor_danger),
								 URIUtil::urlEncode(query->statu_on), URIUtil::urlEncode(query->content_term),
								 URIUtil::urlEncode(query->create_date))
	->readBodyToDto<TermNameListPageJsonVO::Wrapper>(om);
}
