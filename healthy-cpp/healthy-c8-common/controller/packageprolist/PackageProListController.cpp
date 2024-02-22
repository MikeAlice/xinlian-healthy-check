#include "PackageProListController.h"
#include "stdafx.h"
#include "../ApiDeclarativeServicesHelper.h"
PackageProListPageJsonVO::Wrapper PackageProListController::execQueryPackageProList(const PackageProListQuery::Wrapper& query, const PayloadDTO& payload)
{
	// ����ƾ֤
	std::string token = PayloadDTO::getTokenPrefix() + payload.getToken();
	// �����ͻ��˶���
	API_CLIENT_CREATE(ac, om, PackageProListApiClient, "query-packageprolist-api");
	// ���ؽ��
	return ac->queryPackageProList(token, query->pageIndex, query->pageSize, URIUtil::urlEncode(query->keyword), URIUtil::urlEncode(query->section))->readBodyToDto<PackageProListPageJsonVO::Wrapper>(om);
}
