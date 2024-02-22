#include "PackageProNameListController.h"
#include "stdafx.h"
#include "../ApiDeclarativeServicesHelper.h"
PackageProNameListJsonVO::Wrapper PackageProNameListController::execQueryPackageProNameList(const PayloadDTO& payload)
{
	// ����ƾ֤
	std::string token = PayloadDTO::getTokenPrefix() + payload.getToken();
	// �����ͻ��˶���
	API_CLIENT_CREATE(ac, om, PackageProNameListApiClient, "query-sectionnamelist-api");
	// ���ؽ��
	return ac->queryPackageProNameList(token)->readBodyToDto<PackageProNameListJsonVO::Wrapper>(om);
}
