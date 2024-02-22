#include "JobNameListController.h"
#include "stdafx.h"
#include "../ApiDeclarativeServicesHelper.h"
JobNameListPageJsonVO::Wrapper JobNameListController::execQueryJobNameList(const JobNameListQuery::Wrapper& query, const PayloadDTO& payload)
{
	// 创建客户端对象
	API_CLIENT_CREATE(ac, om, JobNameListApiClient, "dictionary-list-api");
	// 构建凭证
	std::string token = PayloadDTO::getTokenPrefix() + payload.getToken();
	// 返回查询结果
	return ac->queryJobNameList(token, query->pageIndex, query->pageSize, URIUtil::urlEncode(query->keyword))->readBodyToDto<JobNameListPageJsonVO::Wrapper>(om);
}
