#include "PackageProNameListController.h"
#include "stdafx.h"
#include "../ApiDeclarativeServicesHelper.h"
PackageProNameListJsonVO::Wrapper PackageProNameListController::execQueryPackageProNameList(const PayloadDTO& payload)
{
	// 构建凭证
	std::string token = PayloadDTO::getTokenPrefix() + payload.getToken();
	// 创建客户端对象
	API_CLIENT_CREATE(ac, om, PackageProNameListApiClient, "query-sectionnamelist-api");
	// 返回结果
	return ac->queryPackageProNameList(token)->readBodyToDto<PackageProNameListJsonVO::Wrapper>(om);
}
