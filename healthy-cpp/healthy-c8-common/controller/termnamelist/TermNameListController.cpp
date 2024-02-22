#include "TermNameListController.h"
#include "stdafx.h"
#include "../ApiDeclarativeServicesHelper.h"
TermNameListPageJsonVO::Wrapper TermNameListController::execQueryTermNameList(const TermNameListQuery::Wrapper& query, const PayloadDTO& payload)
{
	// 构建凭证
	std::string token = PayloadDTO::getTokenPrefix() + payload.getToken();
	// 创建客户端对象
	API_CLIENT_CREATE(ac, om, TermNameListApiClient, "query-termnamelist-api");
	// 返回结果
	return ac->queryTermNameList(token, query->pageIndex, query->pageSize, URIUtil::urlEncode(query->type_inspection),
								 URIUtil::urlEncode(query->type_term), URIUtil::urlEncode(query->factor_danger),
								 URIUtil::urlEncode(query->statu_on), URIUtil::urlEncode(query->content_term),
								 URIUtil::urlEncode(query->create_date))
	->readBodyToDto<TermNameListPageJsonVO::Wrapper>(om);
}
