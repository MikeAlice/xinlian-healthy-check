#include "PackageProListController.h"
#include "stdafx.h"
#include "../ApiDeclarativeServicesHelper.h"
PackageProListPageJsonVO::Wrapper PackageProListController::execQueryPackageProList(const PackageProListQuery::Wrapper& query, const PayloadDTO& payload)
{
	// 构建凭证
	std::string token = PayloadDTO::getTokenPrefix() + payload.getToken();
	// 创建客户端对象
	API_CLIENT_CREATE(ac, om, PackageProListApiClient, "query-packageprolist-api");
	// 返回结果
	return ac->queryPackageProList(token, query->pageIndex, query->pageSize, URIUtil::urlEncode(query->keyword), URIUtil::urlEncode(query->section))->readBodyToDto<PackageProListPageJsonVO::Wrapper>(om);
}
